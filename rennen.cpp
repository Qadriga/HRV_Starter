#include "rennen.h"
#include <QStringList>
#include <QDebug>
Rennen::Rennen(QObject *parent) : QObject(parent)
{

}
// https://stackoverflow.com/questions/14287252/accessing-c-qlists-from-qml
unsigned short Rennen::index(){
    return this->p_index;
}
unsigned short Rennen::abteilung(){
    return this->p_abteilung;
}

QString Rennen::rennNumber(){
    return this->p_rennNummer;
}

void Rennen::setIndex(unsigned short newIndex){
    if(newIndex < 400 ){
        this->p_index = newIndex;
        emit IndexChanged();
    }
    return;
}

void Rennen::setAbteilung(unsigned short newAbteilung){
    this->p_abteilung = newAbteilung;
    emit AbteilungChanged();
}
void Rennen::setRennNumber(QString newNumber){
    this->p_rennNummer = newNumber;
    emit RennNumberChanged();
}


void Rennen::createDatastuktureFromString(QString InputString){
    QStringList DataStrukture;
    RaceLane* obj = nullptr;
    DataStrukture = InputString.split(';',QString::SkipEmptyParts);
    DataStrukture.removeAll(QString('\n'));
    if(DataStrukture.length() <= 10)
        return;
    this->setIndex(DataStrukture.takeFirst().toShort());
    this->setRennNumber(DataStrukture.takeFirst());
    this->setAbteilung(DataStrukture.takeFirst().toShort());
    // Unschön aber funktoniert für 4 bahen
    if((DataStrukture.length() % 2)!= 0){
        qInfo("List are Not identical length ");
        return;
    }
    while(!DataStrukture.isEmpty()){
        obj = new RaceLane(DataStrukture.takeAt(DataStrukture.length()/2),DataStrukture.takeAt(0).toFloat());//take the first of the begining at the half and the first in the List
        this->p_lanes.append(obj);
    }
#ifdef QT_DEBUG
    for(int i = 0; i < this->p_lanes.length();i++){
        qDebug() << *this->p_lanes.at(i);
    }
#endif



}
QVariantList Rennen::lanes(){
    QVariantList newlist;
    QVariant var;
    for(int i = 0; i< this->p_lanes.count();i++){
        var.setValue(this->p_lanes.at(i));
        newlist.append(var);
    }
    return newlist;
    //return this->p_lanes;

}
bool Rennen::sendToDevice(quint32 index){
    Q_UNUSED(index)
    /* generate string and send to Device via usb_wrapper */
    return false;
}
