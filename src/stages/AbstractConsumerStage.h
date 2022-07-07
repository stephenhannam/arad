#pragma once


// Template stage that all consumer stages inherit from. Defines a single input port with no input port.
class AbstractConsumerStage : AbstractStage{
	public:
		AbstractConsumerStage() : AbstractStage(), m_inputport(addNewInputPort<T>()){
			assert(m_inputport);
		}

		InputPort<T>& getInputPort(){
			assert(m_inputport);
			return *m_inputport;
		}

	private:
		InputPort<T>* m_inputport;
		
		// Execute function that must be defined by inheriting class
		virtual void execute(T&& value) = 0;

		//  Execute function with no input. Gets last entry from input port and calls other execute function. Terminates if input port is closed.
		virtual void execute() override{
			assert(m_inputport);

			auto v = m_inputport->receive();
			if(v){
				execute(std::move(*v));
			}else if(m_inputport->isClosed()){
				terminate();
			}else{
				std::this_thread::yield();
			}
		}
};



