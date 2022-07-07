#pragma once

#include "AbstractStage.h"

// Template stage that all producer stages inherit from. Defines a single output port with no input port.
class AbstractProducerStage : AbstractStage{
	public:
		AbstractProducerStage() : AbstractStage(), m_outputport(addNewOutputPort<T>()){
			assert(m_outputport);
		}

		OutputPort<T>& getOutputPort(){
			assert(m_outputport);
			return *m_outputport;
		}

	private:
		OutputPort<T>* m_outputport;
		
		virtual void execute() override = 0;
};



