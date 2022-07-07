#pragma once

#include <vector>
#include <memory>

// Forward declarations
class AbstractInputPort;
class AbstractOutputPort;
template <typename T> class InputPort;
template <typename T> class OutputPort;

enum class StageState{
	Created,
	Started,
	Terminating,
	Terminated
};

// Template stage class that all stages inherit from
class AbstractStage{
	private:
		virtual void execute() = 0;	

		StageState m_state; // Current state

		template<typename T>
		using pointers = std::vector<std::unique_ptr<T>>;
		pointers<AbstractInputPort> m_inputPorts; // All input ports
		pointers<AbstractOutputPort> m_outputPorts; // All output ports

	protected:
		template<typename T>
		InputPort<T>* addNewInputPort();
		
		template<typename T>
		OutputPort<T>* addNewOutputPort();

		std::vector<std::unique_ptr<AbstractOutputPort>>& getOutputPorts();
		std::vector<std::unique_ptr<AbstractInputPort>>& getInputPorts();
	public:
		explicit AbstractStage();
		virtual ~AbstractStage();

		StageState getState();
		void setState(StageState state);

		unsigned int numInputPorts();
		unsigned int numOutputPorts();
		AbstractInputPort* getInputPort(unsigned int index);
		AbstractOutputPort* getOutputPort(unsigned int index);




};



