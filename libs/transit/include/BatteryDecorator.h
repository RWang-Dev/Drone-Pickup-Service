#ifndef BATTERY_DECORATOR_H_
#define BATTERY_DECORATOR_H_

#include "IEntity.h"

/**
 * @brief this class inhertis from the IStrategy class and is represents
 * a battery decorator where the entity will celebrate according to it.
 */
class BatteryDecorator : public IEntity {
  public:
   /**
   * @brief Updates the entity's position in the physical system.
   * @param dt The time step of the update.
   * @param scheduler The list of all entities in the system.
   */
    virtual void Update(double dt, std::vector<IEntity*> scheduler) {};
   
    /**
   * @brief Gets the position of the entity.
   * @return The position of the entity.
   */
  virtual Vector3 GetPosition() const {};

  /**
   * @brief Gets the direction of the entity.
   * @return The direction of the entity.
   */
  virtual Vector3 GetDirection() const {};

  /**
   * @brief Gets the destination of the entity.
   * @return The destination of the entity.
   */
  virtual Vector3 GetDestination() const {};

  /**
   * @brief Gets the details of the entity.
   * @return The details of the entity.
   */
  virtual JsonObject GetDetails() const {};

    /**
   * @brief Gets the speed of the entity.
   * @return The speed of the entity.
   */
  virtual float GetSpeed() const {};
};

#endif  // BATTERY_DECORATOR_H_
