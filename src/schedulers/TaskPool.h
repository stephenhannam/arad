
class TaskPool {      

    private:
        arrayQueue_; // Stores all arrays in the queue
        std::vector addedStages_;
    public:
        TaskPool(int capacity) {
            arrayQueue_ = new MpmcArrayQueue<>(capacity) // TODO: use boost lib
		}

        boolean scheduleStage(AbstractStage stage) {
            if (!addedStages_.add(stage)) {
                return true;
            }

            boolean offered = arrayQueue_.offer(stage); // Fix
            if (!offered) {
                addedStages_.remove(stage);

                Object peekElement = stages.peek();
                String message = String.format("(scheduleStage) Full level %s (size=%s/%s) with first element %s", levelIndex, stages.size(),
                        peekElement);
                if (LOGGER.isWarnEnabled()) {
                    LOGGER.warn(message);
                }
                throw new IllegalStateException(message);
            }

            return offered;
        }

        AbstractStage removeNextStage() {
 
    
            AbstractStage stage = arrayQueue_.poll(); // Fix
           
            if (null != stage) {
                addedStages_.remove(stage);
                return stage;
            }
            return null;
        }

};