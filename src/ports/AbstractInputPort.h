#pragma once

#include "AbstractPort.h"

// Template class for all input ports. Includes the extra function used when waiting for start signal.
class AbstractInputPort : public AbstractPort{
    public:
        explicit AbstractInputPort(AbstractStage* owner): AbstractPort(owner){}

        virtual ~AbstractInputPort() = default;

        virtual void waitForStartSignal() = 0;
};