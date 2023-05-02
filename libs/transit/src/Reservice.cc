#include "Reservice.h"
#include "RechargerDrone.h"
#include <algorithm>
#include <cmath>

Reservice* Reservice::instancePtr = nullptr;

Reservice* Reservice::GetInstance() {
  if (instancePtr == nullptr) {
    instancePtr = new Reservice();
    return instancePtr;
  }
  else {
    return instancePtr;
  }
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

RechargerDrone* Reservice::FindNearestAvailableRechargerDrone(IEntity* drone) {
  float min_distance = std::numeric_limits<float>::max();

  RechargerDrone* nearest_recharger_drone = nullptr;
  
  float distance = 0;
  for (auto recharger_drone : this->rechargerDrones) {
    if (recharger_drone->GetAvailability()) {
      distance = recharger_drone->GetPosition().Distance(drone->GetPosition()); 
      if (distance <= min_distance) {
        min_distance = distance;
        nearest_recharger_drone = recharger_drone;
      }
    }
  }
  if(nearest_recharger_drone != nullptr){
    nearest_recharger_drone->SetDroneToRecharge(drone); 
    return nearest_recharger_drone;
  }
  else{
    return nullptr;
  }
  
}
