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

  // Reservice* mediator = Reservice::GetInstance(); Causing compile error
  // mediator->AddRechargerDrone(this);

  available = true;
}

RechargerDrone::~RechargerDrone() {
  // Delete dynamically allocated variables
  delete graph;
//   delete nearestEntity;
//   delete toRobot;
//   delete toFinalDestination;
}

void RechargerDrone::Update(double dt, std::vector<IEntity*> scheduler) {
//   if (available)
//     GetNearestEntity(scheduler);

//   if (toRobot) {
//     toRobot->Move(this, dt);

//     if (toRobot->IsCompleted()) {
//       delete toRobot;
//       toRobot = nullptr;
//       pickedUp = true;
//     }
//   } else if (toFinalDestination) {
//     toFinalDestination->Move(this, dt);

//     if (nearestEntity && pickedUp) {
//       nearestEntity->SetPosition(position);
//       nearestEntity->SetDirection(direction);
//     }

//     if (toFinalDestination->IsCompleted()) {
//       delete toFinalDestination;
//       toFinalDestination = nullptr;
//       nearestEntity = nullptr;
//       available = true;
//       pickedUp = false;
//     }
//   }
}

