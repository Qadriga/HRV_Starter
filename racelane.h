#ifndef RACELANE_H
#define RACELANE_H

#include <QObject>
#include <QDebug>
class RaceLane : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float time_delay READ gettime_delay WRITE setTime_delay NOTIFY time_delayChanged)
    Q_PROPERTY(QString lane_Lable READ getLane_lable WRITE setLane_Lable NOTIFY Lane_LableChanged)

    float p_timedelay;
    QString p_LaneLable;
public:
    explicit RaceLane(QObject *parent = nullptr);
    explicit RaceLane(QString Lable, float delay, QObject *parent = nullptr);
    RaceLane(const RaceLane &copy);
    ~RaceLane();
    QString getLane_lable(void);
    float gettime_delay(void);
    void setTime_delay(float setTime);
    void setLane_Lable(QString setLable);
    friend QDebug operator<<(QDebug debug,const RaceLane &rl);
signals:
    void time_delayChanged(void);
    void Lane_LableChanged(void);

public slots:

};
Q_DECLARE_METATYPE(RaceLane)

#endif // RACELAND_H
