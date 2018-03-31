#ifndef USB_WRAPPER_H
#define USB_WRAPPER_H

#include <QObject>

#include <libusb-1.0/libusb.h>

class Usb_wrapper : public QObject
{
    Q_OBJECT
    libusb_context *p_libusb = nullptr;
private slots:

public:
    explicit Usb_wrapper(QObject *parent = nullptr);
    virtual ~Usb_wrapper();
signals:

public slots:
};

#endif // USB_WRAPPER_H
