#pragma once

#include <assert.h>
//#include "../stages/AbstractStage.h"

class AbstractStage;

// Template class for all ports. Stores and manages owner stage that the port is attached too
class AbstractPort{
    private:
        AbstractStage* m_owner; // Pointer to stage that owns the port
    public:
        virtual ~AbstractPort() = default;

        // Returns pointer to owner stage
        AbstractStage* owner(){
            return m_owner;
        }

    protected:
        // Constructor sets the pointer to the owner stage
        explicit AbstractPort(AbstractStage* owner) : m_owner(owner){
            assert(owner);
        }
};
