#pragma once

#include <Arduino.h>
#include <Melopero_AMG8833.h>

Melopero_AMG8833 sensor;

bool  PanelInit = false; // panel init flag
bool  Power = false; // Camera on / off
bool  InfoPanel = false;
int   statusCode = 0; // AGM8833 status 
float InterpolatePixel[10][10]; // pixel interpolation buffer
float hightemp = 0.0; // highest temp in frame
float lowtemp  = 0.0; // ;lowest temp in frame
float centertemp = 0.0; // center of frame temp.
float ScaleTop = 25.0; // color scale top
float ScaleBottom = 15.0; // color scale botom
float ScaleStep = 0; // color scale step size
byte   ScaleOffset = 30;
byte   hoffset = ((255 - (16 * 8)) / 2) + 8 + 35; // calculate image position
byte   voffset = ((220 - (16 * 8)) / 2) + 8; 
enum  ImageMode { RAW, IP29, IP64 };
ImageMode ImageModeSelect = RAW;
enum  StillMode { OFF, GET, WRITE, SHOW};
StillMode Still = OFF;
byte  ip = 1;
byte  px = 16;
byte  clickx = 0;
byte  clicky = 0;
bool  mirror = false;