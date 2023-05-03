#ifndef HUMAN_H_
#define HUMAN_H_

#include "IEntity.h"
#include "IStrategy.h"

/** 
 * @class Human
 * @brief Represents a human in the simulation
 */
class Human : public IEntity {
 public:
  /**
   * @brief Humans are created with a name
   * @param obj JSON object containing the human's information
   */
  Human(JsonObject& obj);

  /**
   * @brief Destroy the Human object
   */
  ~Human();
  /**
   * @brief Gets the speed of the human
   * @return The speed of the human
   */
  float GetSpeed() const override { return speed; }

  /**
   * @brief Gets the position of the human
   * @return The position of the human
   */
  Vector3 GetPosition() const override { return position; }

  /**
   * @brief Gets the direction of the human
   * @return The direction of the human
   */
  Vector3 GetDirection() const override { return direction; }

  /**
   * @brief Gets the destination of the human
   * @return The destination of the human
   */
  Vector3 GetDestination() const override { return destination; }

  /**
   * @brief Gets the details information of the human
   * @return The details information of the human
   */
  JsonObject GetDetails() const override { return details; }

  /**
   * @brief Updates the human's position
   * @param dt Delta time
   * @param scheduler Vector containing all the entities in the system
   */
  void Update(double dt, std::vector<IEntity*> scheduler) override;

  /**
   * @brief Sets the position of the human
   * @param pos_ The new position of the human
   */
  void SetPosition(Vector3 pos_) override { position = pos_; }

  /**
   * @brief Sets the direction of the human
   * @param dir_ The new direction of the human
   */
  void SetDirection(Vector3 dir_) override { direction = dir_; }

  /**
   * @brief Sets the destination of the human
   * @param des_ The new destination of the human
   */
  void SetDestination(Vector3 des_) override { destination = des_; }

  /**
   * @brief Creates new destination for the human
   */
  void CreateNewDestination();

  private:
  JsonObject details;
  Vector3 position;
  Vector3 direction;
  Vector3 destination;
  float speed;
  IStrategy* toDestination = nullptr;
};

#endif
