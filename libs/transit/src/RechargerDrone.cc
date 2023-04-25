#define _USE_MATH_DEFINES
#include "RechargerDrone.h"
#include "Reservice.h"
#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include "SpinDecorator.h"

RechargerDrone::RechargerDrone(JsonObject& obj) : details(obj) {
  JsonArray pos(obj["position"]);
  position = {pos[0], pos[1], pos[2]};
  JsonArray dir(obj["direction"]);
  direction = {dir[0], dir[1], dir[2]};

  speed = obj["speed"];
  available = true;
  finishedRechargingDrone = false;

  //Add itself to reservice's vector of recharger drones when instantiated
  Reservice* mediator = Reservice::GetInstance();
  mediator->AddRechargerDrone(this);
}

RechargerDrone::~RechargerDrone() {
  // Delete dynamically allocated variables
  delete graph;
  delete droneToRecharge;
}

void RechargerDrone::Update(double dt, std::vector<IEntity*> scheduler) {
    if (available == false) {
      if (routingStrategy == nullptr) {
        routingStrategy = new BeelineStrategy(position, destination);
      }
      else {
        if(!(routingStrategy->IsCompleted())) { 
          
          routingStrategy->Move(this, dt);
        } else {
          
          RechargerDrone::RechargeDrone();
          finishedRechargingDrone = true;
        }
    }
  }
}

void RechargerDrone::SetDroneToRecharge(IEntity* droneToRecharge) {
  // std::cout << "Successfully set drone" << std::endl;
  this->droneToRecharge = droneToRecharge; 
  destination = droneToRecharge->GetPosition();
  available = false;
  finishedRechargingDrone = false;
  routingStrategy = new BeelineStrategy(position, destination);
  // std::cout << "Routing strat made" << std::endl;
}

void RechargerDrone::RechargeDrone() { 
  // sleep_until(system_clock::now() + seconds(10));
  std::cout << "Done recharging drone";
  available = true;
  droneToRecharge = nullptr;
}
