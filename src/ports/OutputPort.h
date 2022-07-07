#pragma once
#include "../stages/AbstractStage.h"
#include "AbstractOutputPort.h"

/*
    Ouput port class.
    T type of data elements that can be sent through this port.
*/
template <class T>
class OutputPort: public AbstractOutputPort{ 
    private:
        Pipe<T>* m_pipe; // todo: Should be unique pointer

        // Return the pipe connected to the output port
        virtual AbstractPipe* getPipe() override{
            return m_pipe.get();
        }

    public:
        explicit OutputPort(AbstractStage* owner) : AbstractOutputPort(owner), m_pipe(nullptr){}

        // Disable copy constructor
        OutputPort(const OutputPort&) = delete;

        // Sends the data element of type T to the connected pipe
        void send(T&& t) {
            assert(m_pipe);
            m_pipe->add(std::move(t));
        }

        // Tries to send element of type T to the connected pipe
        bool trySend(T&& t){
            assert(m_pipe);
            return m_pipe->tryAdd(std::move(t));
        }

        // TODO: function that assigns pipe
};
