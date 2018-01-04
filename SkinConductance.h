/*
 * SkinConductance.h
 *
 * This class defines an object that can be used to gather information about
 * skin conductance (SC) -- also called galvanic skin respone (GSR) or electro-dermic
 * activity (EDA).
 *
 * This file is part of the BioData project
 * (c) 2018 Erin Gee
 *
 * Contributing authors:
 * (c) 2018 Erin Gee
 * (c) 2018 Sofian Audry
 * (c) 2017 Thomas Ouellet Fredericks
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Average.h"
#include "MinMax.h"
#include "Lop.h"

#ifndef SKIN_CONDUCTANCE_H_
#define SKIN_CONDUCTANCE_H_

class SkinConductance {

  // Analog pin the SC sensor is connected to.
  uint8_t _pin;

  Average<float> GSRaverager;
  int gsrSensorReading;
  float GSRmastered;   //The final GSR value that you will send to serial
  float GSRav;
  MinMax gsrMinMax;
  Lop gsrLop;
  float gsrSensorFiltered;
  float gsrSensorAmplitude;
  float gsrSensorLop;

public:
  SkinConductance(uint8_t pin);
  virtual ~SkinConductance() {}

  /// Resets all values.
  void reset();

  /**
   * Reads the signal and perform filtering operations. Call this before
   * calling any of the access functions.
   */
  void update();

  /// Returns skin conductance response (SRC).
  float getSCR() const;

  /// Returns skin conductance level (SCL).
  float getSCL() const;

  /// Returns raw signal as returned by analogRead() (inverted).
  int getRaw() const;
};

#endif