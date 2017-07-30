# SAM-BAR
SAM-BAR source code and project files for [Atmel Studio 7](http://www.microchip.com/development-tools/atmel-studio-7).

## Bootloader Programming
The bootloader can be flashed with an ARM SWD (Serial Wire Debug) programmer.
To protect the bootloader flash section the fuse ```NVMCTRL_BOOTPROT``` has to be set to ```0x01```.


## Bootloader Activation
The bootloader will be activated if no user program exists or by doing two reset in 0.5s (double pressing reset switch).
It can also be activated via an Arduino Sketch, when opening the serial port with 1200bps. This will erase the user program and start the bootloader.


## Bootloader Usage
When the bootloader is active then a new program can be loaded via the serial port (SAM-BA protocol) or via the mass storage device.
For the mass storage device delete the file ```FLASH.BIN``` and then copy a new binary file ```FLASH.BIN``` to the drive.
After the copy process is finished, do a reset to start the new program.

On Linux/Mac the dd command can be used to write the firmware: ```dd if=NEW.BIN of=/media/BOOTLOADER/FLASH.BIN conv=notrunc```

A binary file can be generated and exported in the Arduino IDE with *Sketch->Export compiled Binary* command.
