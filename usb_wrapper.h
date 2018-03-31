#ifndef USB_WRAPPER_H
#define USB_WRAPPER_H

#include <QObject>

class Usb_wrapper : public QObject
{
    Q_OBJECT
public:
    explicit Usb_wrapper(QObject *parent = nullptr);

signals:

public slots:
};

#endif // USB_WRAPPER_H