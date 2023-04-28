#ifndef DRONE_H_
#define DRONE_H_

#include <vector>

#include "IEntity.h"
#include "IStrategy.h"
#include "RechargerDrone.h"
#include "TripData.h"
#include "math/vector3.h"
#include "DataCollection.h"

class DataCollection;

// Represents a drone in a physical system.
// Drones move using euler integration based on a specified
// velocity and direction.
/**
 * @class Drone
 * @brief Represents a drone in a physical system. Drones move using euler
 * integration based on a specified velocity and direction.
 */
class Drone : public IEntity {
public:
  /**
   * @brief Drones are created with a name
   * @param obj JSON object containing the drone's information
   */
  Drone(JsonObject& obj);

  /**
   * @brief Destructor
   */
  ~Drone();

  /**
   * @brief Gets the speed of the drone
   * @return The speed of the drone
   */
  float GetSpeed() const override { return speed; }

  /**
   * @brief Gets the position of the drone
   * @return The position of the drone
   */
  Vector3 GetPosition() const override { return position; }

  /**
   * @brief Gets the direction of the drone
   * @return The direction of the drone
   */
  Vector3 GetDirection() const override { return direction; }

  /**
   * @brief Gets the destination of the drone
   * @return The destination of the drone
   */
  Vector3 GetDestination() const override { return destination; }

  /**
   * @brief Gets the color of the drone
   * @return The color of the drone
   */
  std::string GetColor() const override { return color; }

  /**
   * @brief Gets the details information of the drone
   * @return The details information of the drone
   */
  JsonObject GetDetails() const override { return details; }

  /**
   * @brief Gets the availability of the drone
   * @return The availability of the drone
   */
  bool GetAvailability() const override { return available; }

  /**
   * @brief Gets a pointer to the drone's current TripData
   * @return The pointer to a TripData object representing the current trip
   */
  TripData *GetTripData() const { return tripData; }

  /**
   * @brief Gets the nearest entity in the scheduler
   * @param scheduler Vector containing all the entities in the system
   */
  void GetNearestEntity(std::vector<IEntity*> scheduler);

  /**
   * @brief Gets the TripData pointer
   * @return TripData object pointer
   */
  TripData* GetTripData() {return tripData;}

  /**
   * @brief Updates the drone's position
   * @param dt Delta time
   * @param scheduler Vector containing all the entities in the system
   */
  void Update(double dt, std::vector<IEntity*> scheduler) override;

  /**
   * @brief Sets the position of the drone
   * @param pos_ The new position of the drone
   */
  void SetPosition(Vector3 pos_) override { position = pos_; }

  /**
   * @brief Sets the direction of the drone
   * @param dir_ The new direction of the drone
   */
  void SetDirection(Vector3 dir_) override { direction = dir_; }

  /**
   * @brief Sets the destination of the drone
   * @param des_ The new destination of the drone
   */
  void SetDestination(Vector3 des_) override { destination = des_; }

  /**
   * @brief Sets the color of the drone
   * @param col_ The new color of the drone
   */
  void SetColor(std::string col_) override { color = col_; }

  /**
   * @brief Sets a new TripData object to track the current trip
   * @param trip_ The pointer to the new TripData object
   */
  void SetTripData(TripData *trip_) { tripData = trip_; }

  /**
   * @brief Rotates the drone
   * @param angle The angle by which the drone should be rotated
   */
  void Rotate(double angle) override;

  /**
   * @brief Makes the drone jump
   * @param height The height at which the drone should jump
   */
  void Jump(double height) override;

  /**
   * @brief Notifies all recharger drones
   */

  void alertRechargerDrones();
  /* Extra comments:
   * loop through vector of red drones, checks which red drone is closest and
   * available Closest red drone: Call red->alert("true") -> starts moving
   * toward drone that needs to be recharged, gets Singleton object, proportion
   * of true and false notifications All other drones: Call red->alert("false")
   * -> gets Singleton object, writes data to a vector
   */

  /**
   * @brief Removing the copy constructor and assignment operator
   * so that drones cannot be copied.
   */
  Drone(const Drone& drone) = delete;
  Drone& operator=(const Drone& drone) = delete;

private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  std::string color = "None"; // None means default color
  float jumpHeight = 0;
  bool goUp = true; // jump helper
  Vector3 destination;
  float speed;
  bool available;
  bool pickedUp;
  IEntity* nearestEntity = nullptr;
  IStrategy* toRobot = nullptr;
  IStrategy* toFinalDestination = nullptr;
  std::vector<RechargerDrone*> rechargerDroneLists;

  TripData* tripData = new TripData();
  DataCollection* dc;
};

#endif
