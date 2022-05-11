
#ifndef MACCHINETTA_BEVANDE_TASKASSISTANCE_H
#define MACCHINETTA_BEVANDE_TASKASSISTANCE_H

class TaskAssistance{
public:
    TaskAssistance(String type){
        //Refill - Complete
        this->assistanceType += type;
    }


private:
    String assistanceType = "Assistance_";
};

#endif //MACCHINETTA_BEVANDE_TASKASSISTANCE_H
