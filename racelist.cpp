#include "racelist.h"

#include <QFile>
#include <QDebug>
#include <QUrl>


RaceList::RaceList(QObject *parent) : QAbstractListModel(parent)
{

}

RaceList::~RaceList(){

}
int RaceList::rowCount(const QModelIndex &parent) const{
    Q_UNUSED(parent)
    return this->p_list.size();
}

QVariant RaceList::data(const QModelIndex &index, int role) const{
    int i = index.row();
    if(i < 0 || i >= p_list.size()){
        return QVariant(QVariant::Invalid);
    }
    return QVariant::fromValue(p_list[i]);
}

Rennen* RaceList::getAt(int idx){
    if(idx < 0 || idx >= this->p_list.size()){
        return nullptr;
    }
    return this->p_list[idx];
}
#if 0
int RaceList::columnCount(const QModelIndex &parent) const{

}
#endif
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
        this->beginInsertRows(QModelIndex(),rowCount(),rowCount());
        this->p_list.append(race_tmp);
        this->endInsertRows();

    }
    //emit dataChanged();

    i_file.close();
    return 0;
}


