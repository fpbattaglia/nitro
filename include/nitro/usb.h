// Copyright (C) 2009 Ubixum, Inc. 
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
#ifndef NITRO_USB_H
#define NITRO_USB_H

#include "device.h"

namespace Nitro {

/**
 * \ingroup dataac
 * 
 * \brief Nitrogen USB %Device
 **/
class DLL_API USBDevice : public Device {
private:
   struct impl;
   impl* m_impl;
protected:
   DataType _get( uint32 terminal_addr, uint32 reg_addr, uint32 timeout );
   void _set( uint32 terminal_addr, uint32 reg_addr, const DataType& type, uint32 timeout ) ;
   void _read( uint32 terminal_addr, uint32 reg_addr, uint8* data, size_t length, uint32 timeout );
   void _write( uint32 terminal_addr, uint32 reg_addr, const uint8* data, size_t length, uint32 timeout ) ;
   void _close();
   int _transfer_status();
   uint16 _transfer_checksum();
public:
    // core methods
    USBDevice(uint32 vid, uint32 pid);
    ~USBDevice() throw();

    // static methods
    /**
     *  Returns the number of connected usb devices. This is a static method and does
     *  not require an open device before calling.
     *  @param vid Vendor Id
     *  @param pid Product Id
     *  @return Number of connected Nitro USB devices. 
     *  @throw Exception
     **/
    static uint32 get_device_count(uint32 vid, uint32 pid);

    /**
     * Retrieve the serial number of the nth connected usb device. This is a static method and does 
     * not require an open device before calling.  The serial number returned is the same as 
     * reported by the device descriptor of the device.  The device descriptor is cached by the
     * operating system until the device renumerates.  That is, if the serial number is changed and
     * the device is not reset, this method will still return the old serial number.
     * \param vid Vendor Id
     * \param pid Product Id
     * \param index The 0 based index of the number of connected devices.  
     * @return The serial number of the nth connected usb device.
     * @throw Exception
     **/
    static std::string get_device_serial(uint32 vid, uint32 pid, uint32 index ) ;


    /**
     * \brief Retrieve the device serial
     *
     * This member function returns the device serial from an already open device.
     * This function returns the serial number as stored by the device.  It can be out
     * of sync with the static get_device_serial until the device is reset.
     **/
    std::string get_device_serial();


    /**
     * \brief set the device serial number.
     *
     * After setting the serial number, if you want the corresponding get_device_serial 
     * to match what you set, you must call reset
     *
     * \param serial must be an string of length 8
     *
     **/
    void set_device_serial(const std::string serial);

    /**
     * \brief Get the device bus and location
     *
     * \param vid Vendor Id
     * \param pid Product Id
     * \param index The 0 based index of the number of connected devices.
     *
     * \return 16 bit integer representing the bus number in the MSB and 
     *  the device number in the LSB
     * \throw Exception
     **/
    static uint16 get_device_address(uint32 vid, uint32 pid, uint32 index) ;


    /**
     * \brief Get the device address.
     *
     *  Member function that can return the device address from an already
     *  opened device.
     **/
    uint16 get_device_address();

    // open methods
    /**
     * Open the nth connected device.
     * \param index The 0 based index of the number of connected devices.
     * \param override_version Normally, the drivers work with a minimum
     *        and maximum firmware version.  You can set this parameter
     *        to true to override the version check.  This is useful for
     *        upgrading old firmware versions.  Warning, USB communication
     *        other than load_firmware probably won't work correctly
     *        if a device has to be opened with override_version=true
     * \throw Exception
     **/
    void open(uint32 index=0, bool override_version=false);

    /**
     * Opens the device with the specified serial number.
     * \param serial Serial number of device to open.
     * \throw Exception
     **/
    void open(const std::string& serial);


    /**
     * Opens the device with the specified address.  Addresses are determined
     * by the operating system and device driver.  The device address can be
     * retrieved with USBDevice::get_device_address.
     *
     * \param addr The address as returned by get_device_address.
     **/
    void open_by_address( uint16 addr );

	/**
	 * \brief Whether or not the device has been opened.
	 **/
	bool is_open();

    /**
     * This call resets the device and loads new firmware.  The device will
     * automatically re-enumerate.  The USBDevice is no longer valid and close
     * is automatically called.  It is OK to call open again but the firmware
     * and OS takes at least a few seconds to finish the enumeration process.
     * 
     * @param bytes Firmware Intel hex file (ihx file contents, not the path).
     * @param length Length of bytes.
     * @throw Exception
     **/
    void load_firmware( const char *bytes, size_t length );

    /**
     * @return the firmware version of the open device.
     *  The firmware version is composed of a major and minor version number
     *  stored in a 16 bit field.  The MSB is the major number and the LSB
     *  is the minor number.
     **/
    uint16 get_firmware_version() const ;

    /**
     * This call causes the device to re-enumberate.  The USBDevice is no longer valid and 
     * close is automatically called.
     * @throw Exception
     **/
    void renum();

    /**
     * This call causes the device firmware to reboot.  This
     * automatically calls close.
     **/
    void reset();
        
};

} 
#endif
