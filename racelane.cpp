#include "racelane.h"

RaceLane::RaceLane(QObject *parent) : QObject(parent)
{

}
RaceLane::RaceLane(QString Lable, float delay, QObject *parent): QObject(parent){
    this->setLane_Lable(Lable);
    this->setTime_delay(delay);
}

float RaceLane::gettime_delay(){
    return this->p_timedelay;
}

QString RaceLane::getLane_lable(){
    return this->p_LaneLable;
}
void RaceLane::setLane_Lable(QString setLable){
    this->p_LaneLable = setLable;
    emit this->Lane_LableChanged();
}
void RaceLane::setTime_delay(float setTime){

    double mod;
    this->p_timedelay = modf(setTime,&mod);

    if(mod > 0.5){
        this->p_timedelay += 0.5;
    }
    emit this->time_delayChanged();
}

QDebug operator<<(QDebug debug, const RaceLane &rl){
    debug.nospace() << "Delay: " << rl.p_timedelay << " Lane: " << rl.p_LaneLable;
    return debug;
}
RaceLane::RaceLane(const RaceLane &copy): QObject(copy.parent()){
    this->p_LaneLable = copy.p_LaneLable;
    this->p_timedelay = copy.p_timedelay;
}
RaceLane::~RaceLane(){

}
