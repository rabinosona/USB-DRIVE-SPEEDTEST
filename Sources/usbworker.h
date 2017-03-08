#include <QString>
#include <QDebug>
#include <QComboBox>
#include <iostream>
#include <usb.h>
#include <chrono>
#include <libudev.h>
#include <QMessageBox>
#include <string>
#include "mainw.h"

#ifndef USBWORKER
#define USBWORKER

class Usbworker
{
public:
    static void listFlashDrives(struct udev *udev, QComboBox *box);
    static void ddexec(QComboBox *box, float *results);
};

#endif // USBWORKER

