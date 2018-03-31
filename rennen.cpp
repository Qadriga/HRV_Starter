#include "rennen.h"
#include <QStringList>
Rennen::Rennen(QObject *parent) : QObject(parent)
{

}
// https://stackoverflow.com/questions/14287252/accessing-c-qlists-from-qml
unsigned short Rennen::Index(){
    return this->p_index;
}
unsigned short Rennen::Abteilung(){
    return this->p_abteilung;
}

QString Rennen::RennNumber(){
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
    DataStrukture = InputString.split(';',QString::SkipEmptyParts);
    DataStrukture.removeAll(QString('\n'));
    if(DataStrukture.length() <= 10)
        return;
    this->setIndex(DataStrukture.at(0).toShort());
    this->setRennNumber(DataStrukture.at(1));
    this->setAbteilung(DataStrukture.at(2).toShort());
    // Unschön aber funktoniert für 4 bahen
    for(uint i = 0; i< 4 ;i ++){
        this->p_delay_start.append(DataStrukture.at(i+2).toShort());
        this->p_start_Number.append(DataStrukture.at(i +2+4).toShort());
    }


}
