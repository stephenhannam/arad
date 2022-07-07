
#include "configuration/Configuration.h"
#include "schedulaers/Scheduler.h"

// Class executes the whole system. Constructor takes in configuration and chosen scheduler, then call ExecuteBlocking to run and wait for termination
class Execution{ 
    private: 
        Executionn(Configuration configuration, Scheduler* scheduler);
        ~Execution();

        WaitForTermination();
    
    public:
        Scheduler* m_scheduler;
        Configuration* m_configuration;

        ExectuteBlocking();
}