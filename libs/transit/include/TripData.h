#ifndef TRIPDATA_H_
#define TRIPDATA_H_

#include <string>

/**
 * @class TripData
 * @brief Stores important data for each trip, which aids in the data collection organization
 *
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
  /**
   * @brief TripData constructor
   */
  TripData() {}

  /**
    * @brief Gets distanceTraveled
    * @return Distance traveled during this trip
    */
  float getDistanceTraveled() {return distanceTraveled;}

  /**
    * @brief Gets routingAlgorithm
    * @return String: Routing algorithm used during this trip
    */
  std::string getRoutingAlgorithm() {return routingAlgorithm;}

  /**
    * @brief Gets recharges
    * @return Number of times the drone needed to be recharged
    */
  float getRecharges() {return recharges;}

  /**
    * @brief Gets batteryUsed
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
    * @brief Increases the distances traveled by a certain amount
    * @param dist distance traveled during this trip
    */
  void IncreaseDistanceTraveled(float dist) {distanceTraveled += dist;}

  /**
    * @brief Sets the routing algorithm of this trip
    * @param routAlg algorithm used during this trip
    */
  void setRoutingAlgorithm(std::string routAlg) {routingAlgorithm = routAlg;}
  
  /**
    * @brief Sets drone ID
    * @param droneID representing ID of drone
    */
  void setDroneID(int droneID) {this->droneId = droneID;}

  /**
    * @brief Increment the number of recharges during this trip by 1
    */
  void IncrementRecharges() {recharges += 1;}

  /**
    * @brief Sets batteryUsed
    * @param batUsed of battery used during this trip, not counting recharges
    */
  void IncreaseBatteryUsed(float batUsed) { batteryUsed += batUsed;}

  /**
  * @brief sets Trip ID
  * @param tID the unique identifier ID of this trip
  */
  void SetTripID(int tID) {tripId = tID;}
};

#endif
