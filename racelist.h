#ifndef RACELIST_H
#define RACELIST_H

#include <QObject>

class RaceList : public QObject
{
    Q_OBJECT
public:
    explicit RaceList(QObject *parent = nullptr);

signals:

public slots:
};

#endif // RACELIST_H