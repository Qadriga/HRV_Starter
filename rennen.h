#ifndef RENNEN_H
#define RENNEN_H

#include <QObject>
#include <QVector>


class Rennen : public QObject
{
    Q_OBJECT
    Q_PROPERTY(unsigned short Index READ Index WRITE setIndex NOTIFY IndexChanged)
    Q_PROPERTY(unsigned short Abteilung READ Abteilung WRITE setAbteilung NOTIFY AbteilungChanged)
    Q_PROPERTY(QString RennNumber READ RennNumber WRITE setRennNumber NOTIFY RennNumberChanged)

    unsigned short p_index = 0;
    unsigned short p_abteilung = 0;
    QString p_rennNummer; // String because of letters in the Race Name
    QVector<unsigned short> p_delay_start;
    QVector<unsigned short> p_start_Number;


public:
    explicit Rennen(QObject *parent = nullptr);
    void createDatastuktureFromString(QString InputString);
    unsigned short Index();
    unsigned short Abteilung();
    QString RennNumber();


signals:
    void IndexChanged(void);
    void AbteilungChanged(void);
    void RennNumberChanged(void);

public slots:
    void setIndex(unsigned short newIndex);
    void setAbteilung(unsigned short);
    void setRennNumber(QString newNumber);
};

#endif // RENNEN_H
