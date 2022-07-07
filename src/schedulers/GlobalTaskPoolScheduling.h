#include "../Interfaces/Scheduler.h"
#include "StageCollector.h"
#include "CountUpDownLatch.h"

// Implements a global task pool type scheduler
class GlobalTaskPoolScheduling : public Scheduler{      

    private:
        int numThreads_;
        int numOfExecutions_;
        Configuration* configuration_;
        PrioritizedTaskPool* taskPool_;

        std::vector<TeeTimeTaskQueueThreadChw> regularThreads_ = {};

        CountDownAndUpLatch numRunningStages_ = CountDownAndUpLatch();


        // Constructor saves number of threads, number of executions and configuration to class variables to be used later
        void GlobalTaskPoolScheduling(const int numThreads, Configuration* configuration, const int numOfExecutions) {
            numThreads_ = numThreads;
            configuration_ = configuration;

            if (numOfExecutions <= 0) {
                throw std::invalid_argument(std::cerr << "numOfExecutions is " << numOfExecutions << ", but must have a positive value." << std::endl);
            }
            
            numOfExecutions_ = numOfExecutions;
        }

        // Destructure deletes pointers to free memory
        ~GlobalTaskPoolScheduling(){
            delete configuration_
        }

        // Function runs on initalization of the global task pool scheduler
        void onInitialize() {

            InitializeTaskPool();

            InitializePipes();

            InitializeThreads();
        }

        // Initializes the task pool that is used to organise and prioritise the tasks to be completed.
        // Determines total number of stages, and adds producers to the task pool to be started
        void InitializeTaskPool() {

            std::vector<AbstractStage>* stages = StageCollector.getStages();

            std::vector<AbstractStage> frontStages;
            for (AbstractStage stage : stages) {
                if(stage->isProducer()) {
                    frontStages.push_back(stage);
                }
                numRunningStages_.countUp();
            }

            const int capacity = numRunningStages_.getCurrentCount();
            taskPool_ = new TaskPool(capacity);
            taskPool_->scheduleStages(frontStages);

        }

        void InitializePipes() {
            // TODO: Join the pipes with the ports
        }

        // Creates all threads and starts them
        void InitializeThreads() {
            for (int i = 0; i < numThreads_; i++) {
                TaskQueueThread backupThread(numOfExecutions_, this);
                backupThread.start();
                regularThreads_.push_back(backupThread);
            }
        }

        CountDownAndUpLatch* getNumRunningStages() {
            return &numRunningStages_;
        }

        PrioritizedTaskPool* getPrioritizedTaskPool() {
            return &taskPool_;
        }
};