#include<thread>

class TaskQueueThread{      

    private:
      int numOfExecutions_; // Max number of executions thread should process on stage
      std::thread thread_; // Thread is started when start function is called
      GlobalTaskPoolScheduling* scheduling_; // Pointer to scheduling class

    public:
        void TaskQueueThread(int numOfExecutions, GlobalTaskPoolScheduling* scheduling){
            numOfExecutions_ = numOfExecutions;
            scheduling_ = scheduling;
        }

        void ~TaskQueueThread(){}

        // Starts the thread by passing it a lambda function. This will continue to run until software is terminated.
        start() {
            thread_ = std::thread( [this] { 
                // Get number of running stages
                CountDownAndUpLatch* numNonTerminatedFiniteStages = scheduling_->getNumRunningStages();

                // Get proritsed task pool
		        PrioritizedTaskPool* taskPool = scheduling->getPrioritizedTaskPool();

                // Keep looping until all stages are completed (all data is processed)
                while (numNonTerminatedFiniteStages->getCurrentCount() > 0) {
                    processNextStage(taskPool);
                } 
            });
        }

        //TODO
        void processNextStage(PrioritizedTaskPool* taskPool) {
            AbstractStage stage = taskPool->removeNextStage();
         
            
            try {

                Thread owningThread = scheduling.getOwningThreadSynched(stage);
               
                scheduling.setOwningThreadSynced(stage, this);

                try {
                    executeStage(stage);

                    reschedule(stage);
                } finally {
                    scheduling.setOwningThreadSynced(stage, null);
                }
            } finally {
                scheduling.setIsBeingExecuted(stage, false);
            }
        }

        void executeStage(final AbstractStage stage) {


            for (int i = 0; i < numOfExecutions_; i++) {
                stage.executeByFramework();
            }
            

        }
};