#include "Pipe.h"
#include "../Stage/AbstractStage.h"

template <typename T>
class UnsynchedPipe: public Pipe<T>{ 
    private:
        
	    Optional<T> m_value;
    	AbstractStage* m_targetStage;
    
    public:
		explicit UnsynchedPipe(AbstractStage* targetStage) : m_targetStage(targetStage){} // Should we also pass ports?

		virtual Optional<T> removeLast() override{
			Optional<T> ret = std::move(m_value);
			m_value.reset();
			return ret;
		}

		virtual bool tryAdd(T&& t) override{
			add(std::move(t));
			return true;
		}

		virtual void add(T&& t) override{
			//TODO: what to do if pipe is non-empty?
			assert(!m_value);
			m_value.set(std::move(t));

			m_targetStage->executeStage();
		}

		virtual void addSignal(const Signal& signal) override
		{
			if(signal.type == SignalType::Terminating){
				this->close();
			}

			m_targetStage->onSignal(signal);
		}

		virtual void waitForStartSignal() override{//do nothing}

		virtual bool isEmpty() const override{
			return !m_value;
		}
}