#include "AbstractStage.h"

template<typename T>
InputPort<T>* AbstractStage::addNewInputPort(){
	if(m_state != StageState::Created){
		throw std::logic_error("Cannot create new ports after stage has been started");
	}

	InputPort<T>* port = new InputPort<T>(this);
	m_inputPorts.push_back(unique_ptr<AbstractInputPort>(port));
	return port;
}

template<typename T>
OutputPort<T>* AbstractStage::addNewOutputPort(){
	if(m_state != StageState::Created){
		throw std::logic_error("Cannot create new ports after stage has been started");
	}
	
	OutputPort<T>* port = new OutputPort<T>(this);
	m_outputPorts.push_back(unique_ptr<AbstractOuputPort>(port));
	return port;
}

std::vector<unique_ptr<AbstractOutputPort>>& AbstractStage::getOuputPorts(){
	return m_outputPorts;
}

std::vector<unique_ptr<AbstractOutputPort>>& AbstractStage::getOuputPorts(){
	return m_outputPorts;
}

StageState AbstractStage::currentState(){
	return m_state;
}

unsigned int AbstractStage::numInputPorts(){
	size_t s = m_inputPorts.size();
	assert(s < UINT32_MAX);

	return static_cast<unsigned int>(s);
}

unsigned int AbstractStage::numOutputPorts(){
	size_t s = m_outputPorts.size();
	assert(s < UINT32_MAX);
	
	return static_cast<unsigned int>(s);
}

AbstractInputPort* AbstractStage::getInputPort(unsigned int index){
	assert(index < m_inputPorts.size());
	return m_inputPorts[index].get();
}

AbstractOutputPort* AbstractStage::getOutputPort(unsigned int index){
	assert(index < m_outputPorts.size());
	return m_outputPorts[index].get();
}

