#ifndef USB_WRAPPER_H
#define USB_WRAPPER_H

#include <QObject>

#include <libusb-1.0/libusb.h>

class Usb_wrapper : public QObject
{
    Q_OBJECT

    libusb_context *p_libusb = nullptr;
    static Usb_wrapper* one_obj; // static pointer to singel object
    explicit Usb_wrapper(QObject *parent = nullptr);

private slots:

public:
    static Usb_wrapper* getInstance();
    virtual ~Usb_wrapper();


signals:

public slots:
    bool sendData(QString Data );
    QStringList getPorts();
};

#endif // USB_WRAPPER_H
