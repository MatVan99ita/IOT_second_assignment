
#ifndef MACCHINETTA_BEVANDE_TASKASSISTANCE_H
#define MACCHINETTA_BEVANDE_TASKASSISTANCE_H

#include "Task.h"

class TaskAssistance: public Task{
public:
    TaskAssistance(String type);
    void init(int period);
    void tick();
private:
    String assistanceType = "Assistance_";
};

TaskAssistance::TaskAssistance(String type){
    //Refill - Complete
    this->assistanceType += type;
}

void TaskAssistance::init(int period){
    Task::init(period);
}

void TaskAssistance::tick(){
}


#endif //MACCHINETTA_BEVANDE_TASKASSISTANCE_H
