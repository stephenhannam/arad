#pragma once

#include "../stages/AbstractStage.h"

class AbstractStage; // Forward declaration

enum class SignalType{
    None,
    Start,
    Terminating
};

struct Signal{
    public:
        Signal(SignalType type, const AbstractStage* stage) : type(type), sender(stage){}

        SignalType type;
        const AbstractStage* sender;
};

inline const char* toString(SignalType type){
    switch(type){
        case SignalType::Start:
            return "SignalType::Start";
        case SignalType::Terminating:
            return "SignalType::Terminating";
        default:
            break;
    }

    return "SignalType::?";
}
