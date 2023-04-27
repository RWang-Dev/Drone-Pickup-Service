#include "RechargerDroneFactory.h"

IEntity* RechargerDroneFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("rechargerDrone") == 0) {
    std::cout << "Recharger Drone Created" << std::endl;
    return new RechargerDrone(entity);
  }
  return nullptr;
}
