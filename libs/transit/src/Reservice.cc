#include "Reservice.h"
#include "RechargerDrone.h"
#include <algorithm>

Reservice::Reservice() {
  Reservice::instance = this;
}

Reservice* Reservice::GetInstance() {
  return Reservice::instance;
}

void Reservice::AddRechargerDrone(RechargerDrone *drone_to_add) {
  this->rechargerDrones.push_back(drone_to_add);
}

void Reservice::RemoveRechargerDrone(RechargerDrone *drone_to_delete) {
  auto iter = std::find(
      this->rechargerDrones.begin(),
      this->rechargerDrones.end(),
      drone_to_delete);
  this->rechargerDrones.erase(iter);
}

RechargerDrone* Reservice::FindNearestAvailableRechargerDrone(IEntity *drone) {
  int min_distance = 0; //Might have to change this to infinity

  RechargerDrone *nearest_recharger_drone = nullptr;
  
  int distance = 0;
  for (auto recharger_drone : this->rechargerDrones) {
    if (recharger_drone->GetAvailability()) {
      distance = recharger_drone->GetPosition().Distance(drone->GetPosition()); 
      if (distance <= min_distance) {
        min_distance = distance;
        nearest_recharger_drone = recharger_drone;
      }
    }
  }

  return nearest_recharger_drone;
}
