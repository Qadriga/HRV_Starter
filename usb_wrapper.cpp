#include "usb_wrapper.h"
#include <QDebug>

Usb_wrapper::Usb_wrapper(QObject *parent) : QObject(parent)
{
    int retval = libusb_init(&p_libusb);
    if (retval != 0){
        qInfo() << "Libusb Failure" << endl;
    }
    else{
        qInfo() << "Createed UsbSession" << endl;
    }
    retval = libusb_set_option(p_libusb,LIBUSB_OPTION_LOG_LEVEL,LIBUSB_LOG_LEVEL_DEBUG);
    if (retval != LIBUSB_SUCCESS){
        qInfo() << "Cann't set Debug Level" << endl;
    }
    retval = libusb_set_option(p_libusb,LIBUSB_OPTION_USE_USBDK);
    switch (retval) {
    case LIBUSB_SUCCESS:
        qInfo() << "Activate USBDK backend" << endl;
        break;
    case LIBUSB_ERROR_NOT_SUPPORTED:
        break;
    default:
        qInfo() << "Error" << endl;
        break;
    }


}

Usb_wrapper::~Usb_wrapper(){
    if (this->p_libusb != nullptr){
        libusb_exit(this->p_libusb);
    }
    return;
}
Usb_wrapper* Usb_wrapper::one_obj = nullptr; // init singelton pointer
Usb_wrapper* Usb_wrapper::getInstance(){
    if(Usb_wrapper::one_obj == nullptr)
        one_obj = new Usb_wrapper();
    return one_obj;

}

bool Usb_wrapper::sendData(QString Data){
    Q_UNUSED(Data)
    return true;
}
QStringList Usb_wrapper::getPorts(){
    return QStringList();
}
