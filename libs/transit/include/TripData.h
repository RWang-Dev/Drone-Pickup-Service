#ifndef DATACOLLECTION_H_
#define DATACOLLECTION_H_

#include <string>

struct TripData {
  int tripId;                   // ID of the trip
  int droneId;                  // ID of the drone the carried out this trip
  float distanceTraveled;       // Distance traveled during this trip
  std::string routingAlgorithm; // Routing algorithm used during this trip
  int recharges;                // Number of times the drone needed to be recharged
  float batteryUsed;            // Percentage of battery used during this trip, not counting recharges
};

#endif
