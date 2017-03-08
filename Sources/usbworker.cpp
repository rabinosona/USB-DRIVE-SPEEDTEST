#include "usbworker.h"
#include "usblistenerlowlevel.cpp"

void Usbworker::listFlashDrives(struct udev *udev, QComboBox *box)
{
    struct udev_enumerate* enumerate = udev_enumerate_new(udev);

    udev_enumerate_add_match_subsystem(enumerate, "scsi");
    udev_enumerate_add_match_property(enumerate, "DEVTYPE", "scsi_device");
    udev_enumerate_scan_devices(enumerate);

    struct udev_list_entry *devices = udev_enumerate_get_list_entry(enumerate);
    struct udev_list_entry *entry;

    udev_list_entry_foreach(entry, devices) {
      const char* path = udev_list_entry_get_name(entry);
      struct udev_device* scsi = udev_device_new_from_syspath(udev, path);

      struct udev_device* block = get_child(udev, scsi, "block");
      struct udev_device* scsi_disk = get_child(udev, scsi, "scsi_disk");

      struct udev_device* usb
        = udev_device_get_parent_with_subsystem_devtype(
            scsi, "usb", "usb_device");

      if (block && scsi_disk && usb) {
          int size;
          QString *devices = new QString[256];
          qDebug() << "block: " << udev_device_get_devnode(block) << "\n";
          size++;
          devices[size] = " ";
          devices[size].append(QString(udev_device_get_devnode(block)) + " " + QString(udev_device_get_sysattr_value(scsi, "vendor")) + QString(udev_device_get_sysattr_value(usb, "product")));
          box->addItem(devices[size]);
      }

      if (block)
        udev_device_unref(block);

      if (scsi_disk)
        udev_device_unref(scsi_disk);

      udev_device_unref(scsi);
    }

    udev_enumerate_unref(enumerate);

}

void Usbworker::ddexec(QComboBox *box, float *results)
{
    std::chrono::time_point<std::chrono::system_clock> start, end;

    QString drive;
    drive = box->currentText().split(' ')[1];
    QString sysin = "dd if=" + drive + " of=./largefile bs=4M count=1024 2>out.txt";
    QString sysread = "dd if=./largefile of=" + drive + " bs=4M count=1024 2>out.txt";
    QByteArray ba = sysin.toLatin1();
    const char *c_str = ba.data();
    ba = sysread.toLatin1();
    const char *c_str_read = ba.data();
    start = std::chrono::system_clock::now();
    system(c_str); // write test
    end = std::chrono::system_clock::now();
    double elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
    start = std::chrono::system_clock::now();
    system(c_str_read); // read test
    end = std::chrono::system_clock::now();
    double elapsed_seconds_read = std::chrono::duration_cast<std::chrono::seconds>(end-start).count();
    results[0] = 4096 / elapsed_seconds;
    results[1] = 4096 / elapsed_seconds_read;
}
