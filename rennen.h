#ifndef RENNEN_H
#define RENNEN_H

#include <QObject>

class Rennen : public QObject
{
    Q_OBJECT
public:
    explicit Rennen(QObject *parent = nullptr);

signals:

public slots:
};

#endif // RENNEN_H