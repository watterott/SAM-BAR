/**
 * \file
 *
 * \brief Board configuration.
 *
 */

#ifndef _CONF_BOARD_H_
#define _CONF_BOARD_H_


//#define BOARD_ARDUINO_MKR1000
//#define BOARD_ARDUINO_MKRZERO
//#define BOARD_ARDUINO_ZERO
//#define BOARD_WATTUINO_RC
//#define BOARD_EITECH_ROBOTICS


#if defined BOARD_ARDUINO_MKR1000      /* Arduino MKR1000 */

#define USB_DEVICE_VENDOR_ID         0x1D50 // Arduino = 0x2341
#define USB_DEVICE_PRODUCT_ID        0x6112 // MKR1000 Bootloader = 0x004E
#define USB_DEVICE_MANUFACTURE_NAME  "Arduino"
#define USB_DEVICE_PRODUCT_NAME      "Arduino MKR1000"
#define USB_DEVICE_SERIAL_NAME       "876427839026" // Disk SN for MSC
#define VOLUMELABEL                  "BOOTLOADER"
#define LED_BOOT                     PORT_PA20  // PA20 (digital pin 6)
#define LED_BOOT_GROUP               0          // Port A


#elif defined BOARD_ARDUINO_MKRZERO    /* Arduino MKRZero */

#define USB_DEVICE_VENDOR_ID         0x1D50 // Arduino = 0x2341
#define USB_DEVICE_PRODUCT_ID        0x6112 // MKRZero Bootloader = 0x004F
#define USB_DEVICE_MANUFACTURE_NAME  "Arduino"
#define USB_DEVICE_PRODUCT_NAME      "Arduino MKRZero"
#define USB_DEVICE_SERIAL_NAME       "876427839026" // Disk SN for MSC
#define VOLUMELABEL                  "BOOTLOADER"
#define LED_BOOT                     PORT_PB08  // PB08 (digital pin 32)
#define LED_BOOT_GROUP               1          // Port B


#elif defined BOARD_ARDUINO_ZERO       /* Arduino Zero */

#define USB_DEVICE_VENDOR_ID         0x1D50 // Arduino = 0x2341
#define USB_DEVICE_PRODUCT_ID        0x6112 // Zero Bootloader = 0x004D
#define USB_DEVICE_MANUFACTURE_NAME  "Arduino"
#define USB_DEVICE_PRODUCT_NAME      "Arduino Zero"
#define USB_DEVICE_SERIAL_NAME       "876427839026" // Disk SN for MSC
#define VOLUMELABEL                  "BOOTLOADER"
#define LED_BOOT                     PORT_PA17  // PA17 (digital pin 13)
#define LED_BOOT_GROUP               0          // Port A


#elif defined BOARD_WATTUINO_RC        /* Watterott Wattuino RC */

#define USB_DEVICE_VENDOR_ID         0x1D50 // OpenMoko = 0x1D50
#define USB_DEVICE_PRODUCT_ID        0x6112 // SAM-BAR Bootloader = 0x6112
#define USB_DEVICE_MANUFACTURE_NAME  "Watterott"
#define USB_DEVICE_PRODUCT_NAME      "Wattuino RC"
#define USB_DEVICE_SERIAL_NAME       "876427839026" // Disk SN for MSC
#define VOLUMELABEL                  "BOOTLOADER"
#ifdef DEBUG
# define LED_BOOT                    PORT_PA02  // PA02/J1
#else
# define LED_BOOT                    PORT_PA30  // PA30/SWCLK
#endif
#define LED_BOOT_GROUP               0          // Port A


#elif defined BOARD_EITECH_ROBOTICS    /* Eitech Robotics */

#define USB_DEVICE_VENDOR_ID         0x1D50 // OpenMoko = 0x1D50
#define USB_DEVICE_PRODUCT_ID        0x6110 // Eitech Robotics Bootloader = 0x6110
#define USB_DEVICE_MANUFACTURE_NAME  "Eitech"
#define USB_DEVICE_PRODUCT_NAME      "Eitech Robotics"
#define USB_DEVICE_SERIAL_NAME       "876427839026" // Disk SN for MSC
#define VOLUMELABEL                  "BOOTLOADER"
#ifdef DEBUG
# define LED_BOOT                    PORT_PA02  // PA02/J1
#else
# define LED_BOOT                    PORT_PA30  // PA30/SWCLK (Dev-Edition: PA31/SWDIO)
#endif
#define LED_BOOT_GROUP               0          // Port A


#else                                  /* no board defined */

#define USB_DEVICE_VENDOR_ID         0x1D50 // OpenMoko = 0x1D50
#define USB_DEVICE_PRODUCT_ID        0x6112 // SAM-BAR Bootloader = 0x6112
#define USB_DEVICE_MANUFACTURE_NAME  "Watterott"
#define USB_DEVICE_PRODUCT_NAME      "SAM-BAR"
#define USB_DEVICE_SERIAL_NAME       "876427839026" // Disk SN for MSC
#define VOLUMELABEL                  "BOOTLOADER"

#endif


#ifdef LED_BOOT
# ifdef DEBUG
#  define LED_BOOT_INIT()              PORT->Group[LED_BOOT_GROUP].DIRSET.reg = LED_BOOT
# else
#  define LED_BOOT_INIT()              PORT->Group[0].PINCFG[PIN_PA30].bit.PMUXEN = 0; \
                                       PORT->Group[0].PINCFG[PIN_PA31].bit.PMUXEN = 0; \
                                       PORT->Group[LED_BOOT_GROUP].DIRSET.reg = LED_BOOT
# endif
#  define LED_BOOT_ON()                PORT->Group[LED_BOOT_GROUP].OUTSET.reg = LED_BOOT
#  define LED_BOOT_OFF()               PORT->Group[LED_BOOT_GROUP].OUTCLR.reg = LED_BOOT
#endif


#ifdef DEBUG
# define APP_START_ADDRESS           0x6000  // Debug
#else
# define APP_START_ADDRESS           0x4000  // Release
#endif


#endif // _CONF_BOARD_H_
