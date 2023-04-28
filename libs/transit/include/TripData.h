#ifndef TRIPDATA_H_
#define TRIPDATA_H_

#include <string>

/** 
 * Class for collecting data on a single trip
 */
class TripData {
 private:
  int tripId = 0;                   // ID of the trip
  int droneId;                  // ID of the drone the carried out this trip
  float distanceTraveled = 0;       // Distance traveled during this trip
  std::string routingAlgorithm; // Routing algorithm used during this trip
  int recharges = 0;                // Number of times the drone needed to be recharged
  float batteryUsed = 0;            // Percentage of battery used during this trip, not counting recharges
 public:

  TripData() {}

  // TripData(int tId, int dId, float distTrav, std::string routAlg, int rech, float battUsage) 
  //   : tripId(tId), droneId(dId),  distanceTraveled(distTrav), routingAlgorithm(routAlg), 
  //     recharges(rech), batteryUsed(battUsage) {}

  /**
    * @brief Gets distanceTraveled
    * @return Distance traveled during this trip
    */
  float getDistanceTraveled() {return distanceTraveled;}

  /**
    * @brief Gets routingAlgorithm
    * @return Routing algorithm used during this trip
    */
  std::string getRoutingAlgorithm() {return routingAlgorithm;}

  /**
    * @brief Gets recharges
    * @return Number of times the drone needed to be recharged
    */
  float getRecharges() {return recharges;}

  /**
    * @brief Sets batteryUsed
    * @return Percentage of battery used during this trip, not counting recharges
    */
  float getBatteryUsed() {return batteryUsed;}

  /**
    * @brief gets Trip ID
    * @return Trip ID
    */
  int getTripID() {return tripId;}

  /**
    * @brief gets drone ID
    * @return Drone ID
    */
  int getDroneID() {return droneId;}

    /**
    * @brief Sets distanceTraveled
    * @param dist distance traveled during this trip
    */
  void IncreaseDistanceTraveled(float dist) {distanceTraveled += dist;}

  /**
    * @brief Sets routingAlgorithm
    * @param Routing algorithm used during this trip
    */
  void setRoutingAlgorithm(std::string routAlg) {routingAlgorithm = routAlg;}
  
  /**
    * @brief Sets drone ID
    * @param droneID representing ID of drone
    */
  void setDroneID(int droneID) {this->droneId = droneID;}

  /**
    * @brief Increment recharges
    * @param Number of times the drone needed to be recharged
    */
  void IncrementRecharges() {recharges += 1;}

  /**
    * @brief Sets batteryUsed
    * @param Percentage of battery used during this trip, not counting recharges
    */
  void IncreaseBatteryUsed(float batUsed) { batteryUsed += batUsed;}

  /**
  * @brief sets Trip ID
  */
  void SetTripID(int tID) {tripId = tID;}
  

};

#endif
