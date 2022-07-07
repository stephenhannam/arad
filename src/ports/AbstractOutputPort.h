#pragma once

#include "AbstractPort.h"

// Forward declarations
struct Signal;
class AbstractPipe;

// Template class for all output ports. Includes the extra function used to send signals, and a virtual function to get the pipe joining the port
class AbstractOutputPort : public AbstractPort{
    public:
        explicit AbstractOutputPort(AbstractStage* owner): AbstractPort(owner){};

        void sendSignal(const Signal& signal);

    private:
        virtual AbstractPipe* getPipe() = 0;
};
