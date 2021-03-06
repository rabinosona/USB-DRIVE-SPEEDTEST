#include "mainw.h"
#include "ui_mainw.h"
#include "usbworker.h"

mainw::mainw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainw)
{
    ui->setupUi(this);
    struct udev* udev = udev_new();

    if (!udev)
    {
        qDebug() << "Couldn't create udev. Aborting...";
        exit(1);
    }

    Usbworker::listFlashDrives(udev, ui->comboBox);
    udev_unref(udev);
}

mainw::~mainw()
{
    delete ui;
}

void mainw::on_speedtestbutton_clicked()
{
    float results[2];
    float *pt = results;
    Usbworker::ddexec(ui->comboBox, pt);

    QMessageBox msg;
    msg.setText("The write speed is: " + QString::number(results[0]) + "MB/s\nThe read speed is: " + QString::number(results[1]) + "MB/s \n");
    msg.setDefaultButton(QMessageBox::Ok);
    msg.exec();
}
