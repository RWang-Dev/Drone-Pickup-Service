#ifndef RECHARGERDRONE_FACTORY_H_
#define RECHARGERDRONE_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "RechargerDrone.h"

/**
 *@brief Recharger Drone Factory to produce Recharger Drones class.
 **/
class RechargerDroneFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for IEntityFactory class.
   **/
  virtual ~RechargerDroneFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity) override;
};

#endif
