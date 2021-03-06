/*
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
/*
For beginners tutorial (and user guide) visit:
http://www.openelectrons.com/docs/viewdoc/25
*/

#include <Wire.h>
#include <EVShield.h>
#include <EVs_LineLeader.h>

// setup for this example:
// attach external power to EVShield.
// attach LineLeader to Port BAS1
// Open the Serial terminal to view.

//
// declare the EVShield(s) attached to your Arduino.
//
EVShield    evshield(0x34,0x36);

//
// declare the i2c devices used on EVShield(s).
//
EVs_LineLeader ll (0x02);

void setup()
{
  char str[256];

  Serial.begin(115200);  // start serial for output
  delay(500); // wait, allowing time to activate the serial monitor

//  Serial.println (__FILE__);
//  Serial.println ("Initializing the devices ...");
  //
  // Initialize the protocol for EVShield
  // It is best to use Hardware I2C (unless you want to use Ultrasonic).
  //
  evshield.init( SH_HardwareI2C );

  //
  // Wait until user presses GO button to continue the program
  //
  Serial.println ("Press GO button to continue");
  evshield.waitForButtonPress(BTN_GO);

  //
  // Initialize the i2c sensors.
  //
  ll.init( &evshield, SH_BAS1 );

}

#define DELAY_T 0

void loop()
{
  char aa[80];
  char str[256];
  uint8_t  result;
  char str2[20];

  strcpy(aa, ll.getFirmwareVersion() );
  sprintf (str, "ll: getFirmwareVersion: %s", aa);
  Serial.println(str);

  strcpy(aa, ll.getDeviceID() );
  sprintf (str, "ll: DeviceID: %s", aa);
  Serial.println(str);

  strcpy(aa, ll.getVendorID() );
  sprintf (str, "ll: VendorID: %s", aa);
  Serial.println(str);

  result = ll.getResult();
  format_bin(result, str2);
  sprintf (str, "ll: sensor array: %s", str2 );
  Serial.println(str);

  Serial.println( "-------------" );
  delay (1500);
}


