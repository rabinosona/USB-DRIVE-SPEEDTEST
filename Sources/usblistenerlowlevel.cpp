#include <libudev.h>
#include <stdio.h>

static struct udev_device*
get_child(
     struct udev* udev, struct udev_device* parent, const char* subsystem)
{
  struct udev_device* child = NULL;
  struct udev_enumerate *enumerate = udev_enumerate_new(udev);

  udev_enumerate_add_match_parent(enumerate, parent);
  udev_enumerate_add_match_subsystem(enumerate, subsystem);
  udev_enumerate_scan_devices(enumerate);

  struct udev_list_entry *devices = udev_enumerate_get_list_entry(enumerate);
  struct udev_list_entry *entry;

  udev_list_entry_foreach(entry, devices) {
    const char *path = udev_list_entry_get_name(entry);
    child = udev_device_new_from_syspath(udev, path);
    break;
  }

  udev_enumerate_unref(enumerate);
  return child;
}
