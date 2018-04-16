#include "racelist.h"

#include <QFile>
#include <QDebug>
#include <QUrl>


RaceList::RaceList(QObject *parent) : QObject(parent)
{

}

RaceList::~RaceList(){
    foreach (QObject* listitem, this->p_list) {
        delete listitem;
    }
}

QObject *RaceList::getAt(int idx){
    if(idx < 0 || idx >= this->p_list.size()){
        return nullptr;
    }
    return this->p_list[idx];
}

int RaceList::createListFromFile(QString Filepath){
    QFile i_file ;
    QUrl fileurl = QUrl(Filepath);
    i_file.setFileName(fileurl.path());
    if(!i_file.exists()){
        qInfo() << "File does not exist" << endl;
        return -1;
    }
    i_file.open(QIODevice::ReadOnly);
    while (!i_file.atEnd()) {
        QByteArray line = i_file.readLine();
        if(line.length() < 2)
            continue;
        Rennen* race_tmp = new Rennen();
        race_tmp->createDatastuktureFromString(line);
#ifdef QT_DEBUG
        qInfo() << QString(line) << endl;
#endif        
        this->p_list.append(race_tmp);
}
    emit this->racelistChanged();
    i_file.close();
    return 0;
}

QList<QObject*> RaceList::list(){
    return this->p_list;
}

