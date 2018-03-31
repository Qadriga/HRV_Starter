#ifndef RACELIST_H
#define RACELIST_H

#include <QObject>
#include <QVector>
#include <QAbstractListModel>

#include "rennen.h"

Q_DECLARE_METATYPE(Rennen*)

class RaceList : public QAbstractListModel
{
    Q_OBJECT
    QList<Rennen*> p_list;

public:
    explicit RaceList(QObject *parent = nullptr);
    ~RaceList();
    int rowCount(const QModelIndex &parent = QModelIndex() ) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    //int columnCount(const QModelIndex &parent) const override;
signals:
    void racelistChanged(void);
public slots:
    Rennen* getAt(int idx);
    int createListFromFile(QString Filepath);

};

#endif // RACELIST_H
