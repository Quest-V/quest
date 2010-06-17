/*                    The Quest Operating System
 *  Copyright (C) 2005-2010  Richard West, Boston University
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <drivers/usb/usb.h>
#include <drivers/usb/uhci.h>
#include <arch/i386.h>
#include <util/printf.h>
#include <kernel.h>

#define DEBUG_USB

#ifdef DEBUG_USB
#define DLOG(fmt,...) DLOG_PREFIX("USB",fmt,##__VA_ARGS__)
#else
#define DLOG(fmt,...) ;
#endif

int
usb_get_descriptor (
    USB_DEVICE_INFO * dev,
    uint16_t dtype,
    uint16_t dindex,
    uint16_t index,
    uint16_t length,
    addr_t desc)
{
  switch (dev->host_type)
  {
    case TYPE_HC_UHCI :
      if ((dev->devd).bMaxPacketSize0 == 0) {
        DLOG("USB_DEVICE_INFO is probably not initialized!");
        return -1;
      } else {
        return uhci_get_descriptor(dev->address, dtype, dindex,
            index, length, desc, (dev->devd).bMaxPacketSize0);
      }

    case TYPE_HC_EHCI :
      DLOG("EHCI Host Controller is not supported now!");
      return -1;

    case TYPE_HC_OHCI :
      DLOG("OHCI Host Controller is not supported now!");
      return -1;

    default :
      DLOG("Unknown Host Controller request!");
      return -1;
  }
  return -1;
}

int
usb_set_address (USB_DEVICE_INFO * dev, uint8_t new_addr)
{
  switch (dev->host_type)
  {
    case TYPE_HC_UHCI :
      if ((dev->devd).bMaxPacketSize0 == 0) {
        DLOG("USB_DEVICE_INFO is probably not initialized!");
        return -1;
      } else {
        return uhci_set_address(dev->address, new_addr,
            (dev->devd).bMaxPacketSize0);
      }

    case TYPE_HC_EHCI :
      DLOG("EHCI Host Controller is not supported now!");
      return -1;

    case TYPE_HC_OHCI :
      DLOG("OHCI Host Controller is not supported now!");
      return -1;

    default :
      DLOG("Unknown Host Controller request!");
      return -1;
  }
  return -1;
}

int
usb_get_configuration(USB_DEVICE_INFO * dev)
{
  switch (dev->host_type)
  {
    case TYPE_HC_UHCI :
      if ((dev->devd).bMaxPacketSize0 == 0) {
        DLOG("USB_DEVICE_INFO is probably not initialized!");
        return -1;
      } else {
        return uhci_get_configuration(dev->address,
            (dev->devd).bMaxPacketSize0);
      }

    case TYPE_HC_EHCI :
      DLOG("EHCI Host Controller is not supported now!");
      return -1;

    case TYPE_HC_OHCI :
      DLOG("OHCI Host Controller is not supported now!");
      return -1;

    default :
      DLOG("Unknown Host Controller request!");
      return -1;
  }
  return -1;
}

int
usb_set_configuration(USB_DEVICE_INFO * dev, uint8_t conf)
{
  switch (dev->host_type)
  {
    case TYPE_HC_UHCI :
      if ((dev->devd).bMaxPacketSize0 == 0) {
        DLOG("USB_DEVICE_INFO is probably not initialized!");
        return -1;
      } else {
        return uhci_set_configuration(dev->address, conf,
            (dev->devd).bMaxPacketSize0);
      }

    case TYPE_HC_EHCI :
      DLOG("EHCI Host Controller is not supported now!");
      return -1;

    case TYPE_HC_OHCI :
      DLOG("OHCI Host Controller is not supported now!");
      return -1;

    default :
      DLOG("Unknown Host Controller request!");
      return -1;
  }
  return -1;
}

int
usb_get_interface(USB_DEVICE_INFO * dev, uint16_t interface)
{
  switch (dev->host_type)
  {
    case TYPE_HC_UHCI :
      if ((dev->devd).bMaxPacketSize0 == 0) {
        DLOG("USB_DEVICE_INFO is probably not initialized!");
        return -1;
      } else {
        return uhci_get_interface(dev->address, interface,
            (dev->devd).bMaxPacketSize0);
      }

    case TYPE_HC_EHCI :
      DLOG("EHCI Host Controller is not supported now!");
      return -1;

    case TYPE_HC_OHCI :
      DLOG("OHCI Host Controller is not supported now!");
      return -1;

    default :
      DLOG("Unknown Host Controller request!");
      return -1;
  }
  return -1;
}

int
usb_set_interface(USB_DEVICE_INFO * dev, uint16_t alt, uint16_t interface)
{
  switch (dev->host_type)
  {
    case TYPE_HC_UHCI :
      if ((dev->devd).bMaxPacketSize0 == 0) {
        DLOG("USB_DEVICE_INFO is probably not initialized!");
        return -1;
      } else {
        return uhci_set_interface(dev->address, alt, interface,
            (dev->devd).bMaxPacketSize0);
      }

    case TYPE_HC_EHCI :
      DLOG("EHCI Host Controller is not supported now!");
      return -1;

    case TYPE_HC_OHCI :
      DLOG("OHCI Host Controller is not supported now!");
      return -1;

    default :
      DLOG("Unknown Host Controller request!");
      return -1;
  }
  return -1;
}

/*
 * Local Variables:
 * indent-tabs-mode: nil
 * mode: C
 * c-file-style: "gnu"
 * c-basic-offset: 2
 * End:
 */

/* vi: set et sw=2 sts=2: */