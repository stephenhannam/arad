#include "AbstractPipe.h"

template <class T>
class AbstractUnsynchedPipe: public AbstractPipe<T>{ 
    private:
        boolean closed_;

	    AbstractUnsynchedPipe(OutputPort<T> sourcePort, InputPort<T> targetPort) : AbstractPipe(sourcePort, targetPort) {
        }

        void sendSignal(ISignal signal) {
            // getTargetPort is always non-null since the framework adds dummy ports if necessary
            cachedTargetStage_->onSignal(signal, getTargetPort());
        }

        void reportNewElement() {
            cachedTargetStage_->executeByFramework();
        }

        boolean isClosed() {
            return closed_;
        }

        void close() {
            closed_ = true;
        }
   
}