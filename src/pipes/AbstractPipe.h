#pragma once
#include <atomic>

struct Signal;

class AbstractPipe{ 
    private:
        //make sure closed flag is stored on it's own cacheline.
        char padding0[64];
        std::atomic<bool> m_closed;
        char padding1[64];

    public:
        AbstractPipe() : m_closed(false){}

        virtual ~AbstractPipe() = default;

        virtual void addSignal(const Signal& s) = 0;
        virtual void waitForStartSignal() = 0;

        bool isClosed() const{
            return m_closed.load(std::memory_order_relaxed);
        }

        void close(){
            m_closed = true;
        }
};
