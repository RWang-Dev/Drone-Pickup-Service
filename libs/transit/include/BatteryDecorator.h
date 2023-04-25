#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include "IEntity.h"
#include "IStrategy.h"
#include "RechargerDrone.h"

/**
 * @brief this class inhertis from the IStrategy class and is represents
 * a battery decorator where the entity will celebrate according to it.
 */
class BatteryDecorator : public IEntity {
  public:
     /**
   * @brief Drones w/ battery are created with a name
   * @param ent entity pointer
   */
  BatteryDecorator(IEntity* ent);

  /**
   * @brief Destructor
   */
  ~BatteryDecorator();
   
   /**
   * @brief Updates the entity's position in the physical system.
   * @param dt The time step of the update.
   * @param scheduler The list of all entities in the system.
   */
    virtual void Update(double dt, std::vector<IEntity*> scheduler);
   
    /**
   * @brief Gets the position of the entity.
   * @return The position of the entity.
   */
  virtual Vector3 GetPosition() const { return drone->GetPosition(); };

  /**
   * @brief Gets the direction of the entity.
   * @return The direction of the entity.
   */
  virtual Vector3 GetDirection() const { return drone->GetDirection(); };

  /**
   * @brief Gets the destination of the entity.
   * @return The destination of the entity.
   */
  virtual Vector3 GetDestination() const { return drone->GetDestination(); };

  /**
   * @brief Gets the details of the entity.
   * @return The details of the entity.
   */
  virtual JsonObject GetDetails() const { return drone->GetDetails(); };

    /**
   * @brief Gets the speed of the entity.
   * @return The speed of the entity.
   */
  virtual float GetSpeed() const { return drone->GetSpeed(); };

   /**
   * @brief Gets the battery of the entity.
   * @return The battery of the entity.
   */
  virtual float GetBattery() const { return battery; };

  /**
   * @brief Set battery of entity
   * @param battery Battery amount to set entity's battery to
   */
  virtual void SetBattery(float newBatteryAmt) { battery = newBatteryAmt; };

  /**
   * @brief Sets the graph object used by the entity in the simulation, 
   * @param graph The IGraph object to be used.
   */
  virtual void SetGraph(const IGraph* graph) { drone->SetGraph(graph); }

  /**
   * @brief increment battery by certain percent 
   * @param batt amount to add
   */
  virtual void IncrementBattery(float batt) { battery += batt; }

 private:
  float battery;
  bool outOfBattery;
  IEntity* drone;
  RechargerDrone* rDrone;
};


#endif  // BATTERY_DECORATOR_H_
