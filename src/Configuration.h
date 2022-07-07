

/**
* A configuration.
* Derive your P&F configuration from this class.
*
* execute the configuration with 'executeBlocking()';
*/
class Configuration{ 
    public: 
        Configuration();
        virtual ~Configuration();

        //no copy construction, no assignment
        Configuration(const Configuration&) = delete;
        Configuration& operator=(const Configuration&) = delete;

    private:
        ReadConfiguration(){}; // TODO: Reads the configuration (from file?)
}

