#ifndef RESERVICE_H_
#define RESERVICE_H_

#include <vector>

#include "IEntity.h"
#include "RechargerDrone.h"

/**
 * @class Reservice
 * @brief Acts as a mediator between out-of-battery drones and recharger drones
 */
class Reservice {
 public:
  Reservice(const Reservice& o) = delete;

  /**
   * @brief Gets instance of this class
   * @return Static pointer which points to instance of this class
   */
  static Reservice* GetInstance();

  /**
   * @brief Finds nearest, available recharger drone and calls its
   * SetDroneToRecharge function
   * @param drone Drone that's out of battery and needs to be recharged
   * @return nearest, available recharger drone
   */
  RechargerDrone* FindNearestAvailableRechargerDrone(IEntity* drone);

  /**
   * @brief Adds recharger drone to recharger drone vector
   * @param drone Recharger drone to be added to vector of recharger drones
   */
  void AddRechargerDrone(RechargerDrone* drone);

  /**
   * @brief Removes recharger drone from recharger drone vector
   * @param drone Recharger drone to be removed from vector of recharger drones
   */
  void RemoveRechargerDrone(RechargerDrone* drone);

  /**
   * @brief Returns vector of all recharger drones in the system
   * @return Vector of recharger drones
   */
  std::vector<RechargerDrone*> GetRechargerDrones() { return rechargerDrones; }

 private:
  std::vector<RechargerDrone*> rechargerDrones;
  static Reservice* instancePtr;
  Reservice(){}
};

#endif
