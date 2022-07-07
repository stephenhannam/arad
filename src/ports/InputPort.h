#pragma once
#include "AbstractInputPort.h"
#include "../pipes/Pipe.h"

class AbstractOutputPort;

/*
    Input port class
*   T type of data elements that can be received through this port.
*/
template <typename T>
class InputPort : public AbstractInputPort{ 
    private:
        Pipe<T>* m_pipe; // Pipe that is connected to the port

    public:
        InputPort(AbstractStage* owner) : AbstractInputPort(owner) {};

        // Forbid copy constructor
        InputPort(const InputPort&) = delete;

        // Removes the last element from pipe and returns it from the function. Could return null
        T receive() {
            return m_pipe->removeLast();
        }

        // Function to tell pipe to wait for start signal
        virtual void waitForStartSignal() override{
            m_pipe->waitForStartSignal();
        }

        // Determine whether the pipe (and therefore port) is closed
        bool isClosed() const{
            return m_pipe->isClosed() && m_pipe->isEmpty();
        }

        // TODO: function that assigns pipe
};
