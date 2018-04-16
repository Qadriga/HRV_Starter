#ifndef RACELIST_H
#define RACELIST_H

#include <QObject>
#include <QVector>
#include <QAbstractListModel>

#include "rennen.h"

Q_DECLARE_METATYPE(Rennen*)

class RaceList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject*> list READ list NOTIFY racelistChanged)

    QList<QObject*> p_list;

public:
    explicit RaceList(QObject *parent = nullptr);
    ~RaceList();
    QList<QObject*> list();
    //int columnCount(const QModelIndex &parent) const override;
signals:
    void racelistChanged(void);
    void TransmissionSuccess(QString Data);

public slots:
    QObject* getAt(int idx);
    int createListFromFile(QString Filepath);
    bool sendToDevice(quint32 index = 0);

};

#endif // RACELIST_H
