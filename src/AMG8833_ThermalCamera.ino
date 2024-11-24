// AMG8833_ThermalCamera - https://github.com/JaapDanielse/AMG8833-Thermal-Camera
// Documentation https://github.com/JaapDanielse/AMG8833-Thermal-Camera/wiki
// GNU General Public License v3.0 - Copyright (c) 2022 Jaap Danielse
// 
// Uses Melopero_AMG8833 library - https://github.com/melopero/Melopero_AMG8833 (install via IDE)
// Uses VirtualPanel - https://github.com/JaapDanielse/VirtualPanel (install via instructions)
//
// V1.0 07-04-2022 - Jaap Daniëlse 
//      Initial release

#include <Arduino.h>
#include <Melopero_AMG8833.h>
#include "AMG8833_ThermalCamera.h"
#include "VirtualPanel.h"
#include "SensorData.h"

//----------------------------------------------------------------------------
void setup() 
{
  Panel.begin(); // init port and protocol
  while(!PanelInit) Panel.receive(); // Wait for panel init
  Wire.begin(); // Start I2C  
  InitAMG8833();  // init AGM8833
}

//----------------------------------------------------------------------------
void loop() 
{
  Panel.receive(); // read panel input

  if(Power) // if camera on
  {
    SensorData(); // read sensor data
  } 
}