#ifndef RENNEN_H
#define RENNEN_H

#include <QObject>
#include <QList>
#include <QVariantList>
#include "racelane.h"

Q_DECLARE_METATYPE(RaceLane*)
class Rennen : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint16 index READ index WRITE setIndex NOTIFY IndexChanged)
    Q_PROPERTY(quint16 abteilung READ abteilung WRITE setAbteilung NOTIFY AbteilungChanged)
    Q_PROPERTY(QString rennNumber READ rennNumber WRITE setRennNumber NOTIFY RennNumberChanged)
    Q_PROPERTY(QVariantList lanes READ lanes  NOTIFY LanesChanged)//WRITE setLanes

    unsigned short p_index = 0;
    unsigned short p_abteilung = 0;
    QString p_rennNummer; // String because of letters in the Race Name
    QList<RaceLane*> p_lanes;



public:
    explicit Rennen(QObject *parent = nullptr);
    void createDatastuktureFromString(QString InputString);
    unsigned short index();
    unsigned short abteilung();
    QString rennNumber();
    QVariantList lanes();

signals:
    void IndexChanged(void);
    void AbteilungChanged(void);
    void RennNumberChanged(void);
    void LanesChanged(void);


public slots:
    void setIndex(unsigned short newIndex);
    void setAbteilung(unsigned short);
    void setRennNumber(QString newNumber);


};

#endif // RENNEN_H
