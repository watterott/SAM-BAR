# Board Support Package
Board Support Package for [Arduino IDE v1.6+](https://www.arduino.cc/en/Main/Software) with Arduino SAMD Boards v1.6.10+


## Installation

Add the following URL to the Arduino Boards Manager (*File->Preferences*):
```
https://github.com/watterott/SAM-BAR/raw/master/arduino/package_sambar_index.json
```
Then open the Arduino Boards Manager (*Tools->Boards->Boards Manager*) and install the 
**Arduino SAMD Boards** and **SAMD (ARM Cortex-M0+) Boards with SAM-BAR**.


## Bootloader

The bootloader can be activated via the Arduino IDE or by doing two reset in 0.5s (double pressing reset switch).

When the bootloader is active then a new program can be loaded via the Arduino IDE and the serial port or via the mass storage device.
For the mass storage device delete the file ```FLASH.BIN``` and then copy a new binary file ```FLASH.BIN``` to the drive.
After the copy process is finished, do a reset to start the new program.

On Linux/Mac the dd command can be used to write the firmware: ```dd if=NEW.BIN of=/media/BOOTLOADER/FLASH.BIN conv=notrunc```

A binary file can be generated and exported in the Arduino IDE with *Sketch->Export compiled Binary* command.


## Known Issues

### Windows
Sometimes the driver for the USB Bootloader is not loaded correctly.
Check the driver state in the Device Manager, when the Bootloader is active (double press reset).
If you cannot install the driver on Windows 8 or higher then deactivate the [driver signature enforcement](https://learn.sparkfun.com/tutorials/disabling-driver-signature-on-windows-8/disabling-signed-driver-enforcement-on-windows-8).
* [SAM-BAR Driver](https://github.com/watterott/SAM-BAR/raw/master/arduino/driver.zip)

### Linux
The Modem Manager detects the Serial Ports (e.g. the USB Bootloader) as a modem and therefore a blacklist rule is needed.
Run one of the commands - depending on your system:

```sudo nano /etc/udev/rules.d/77-mm-usb-device-blacklist.rules```

```sudo nano /lib/udev/rules.d/77-mm-usb-device-blacklist.rules```

and add the following lines to the file:
```
ATTRS{idVendor}=="1D50", ATTRS{idProduct}=="6112", ENV{ID_MM_DEVICE_IGNORE}="1"
ATTRS{idVendor}=="1D50", ATTRS{idProduct}=="6113", ENV{ID_MM_DEVICE_IGNORE}="1"
```

Reload udev rules:
```
sudo udevadm control --reload-rules
```

Or you can also remove the Modem Manager from your system with
```
sudo apt-get uninstall modemmanager
```
