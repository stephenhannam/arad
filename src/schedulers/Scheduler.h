/**
 * Interface for a scheduling strategy.
 */
class Scheduler {
    public:
    virtual void onInitialize() = 0;

	virtual void onValidate() = 0;

	//Executes the execution.
	virtual void onExecute() = 0;

	//Aborts the execution.
	virtual void onTerminate() = 0;

	// Waits for the execution to finished.
	virtual void onFinish() = 0;
};