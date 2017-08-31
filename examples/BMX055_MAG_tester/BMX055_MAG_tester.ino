/*
    Code written by Chia Jiun Wei @ 29-8-2017
    This code test the BMX055_MAG library
*/

/*  PIN connection for a MSP432 LaunchPad board:
    P6.0 - > BMX055 CSM, define P6.0 as SPI chip select
*/

#include "BMX055_MAG.h"

DSPI master;        // used EUSCI_B0
BMX055_MAG imu_mag(&master, 2);

s16 mag_data[3];

void setup()
{
  // initialize the UART
  Serial.begin(115200);
  delay(300);

  // initialise SPI:
  master.begin();
  delay(300);

  Serial.print("**** Start BMX055 Magnetometer test ****");
  Serial.println();

  //initalise BMX055 magnetometer
  imu_mag.init();

  Serial.print("BMX055 magnetometer initialised");
  Serial.println();
  Serial.print("Pinging BMX055 magnetometer...");
  Serial.println();

  if (imu_mag.ping() == 1)
  {
    Serial.print("Ping sucess");
    Serial.println();
  }
  else
  {
    Serial.print("Ping fail");
    Serial.println();
  }
}

void loop()
{
  Serial.print("Reading magnetometer data");
  Serial.println();
  imu_mag.get_mag(mag_data);

  Serial.print("B field x: ");
  Serial.print(mag_data[0], DEC);
  Serial.print("  ");
  Serial.print("B field y: ");
  Serial.print(mag_data[1], DEC);
  Serial.print("  ");
  Serial.print("B field z: ");
  Serial.print(mag_data[2], DEC);
  Serial.print("  ");
  Serial.println();
}

