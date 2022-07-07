#include "Execution.h"

// Constructor takes in the configuration and chosen scheduler. Initialtes the scheduler
Execution::Execution(Configuration configuration, Scheduler* scheduler){
    
    m_configuration = configuration;
    m_scheduler = scheduler;

    scheduler.onInitialize();
}

Execution::~Execution(){};

// Function called to execute the system. Executes the scheduler then waits for it to finish
Execution::ExecuteBlocking(){
    m_scheduler.onExecute()

    waitForTermination()
}

// Wait for the system to terminate (this will need to be added)
Execution::WaitForTermination(){
    // TODO: logic to wait for termination
    m_scheduler.onFinish();
}