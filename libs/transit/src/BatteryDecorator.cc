#include "BatteryDecorator.h"

#include "DataCollection.h"
#include "RechargerDrone.h"
#include "Reservice.h"
#define _USE_MATH_DEFINES

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "BeelineStrategy.h"
#include "DfsStrategy.h"
#include "DijkstraStrategy.h"
#include "JumpDecorator.h"
#include "SpinDecorator.h"

BatteryDecorator::BatteryDecorator(IEntity* ent) {
  this->drone = ent;
  battery = 100;
  outOfBattery = false;
  this->dronePtr = static_cast<Drone*>(ent);
  dc = DataCollection::GetInstance();
}

BatteryDecorator::~BatteryDecorator() { delete drone; }

void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
  if (outOfBattery == false) {
    drone->Update(dt, scheduler);
    if (drone->GetAvailability() == false) {
      battery -= 2 * dt;
      // drone = dynamic_cast<Drone*>(drone);
      dronePtr->GetTripData()->IncreaseBatteryUsed(2 * dt);
      dc->IncreaseTotalBatUsage(2 * dt);
    } else {
      battery -= dt;
      dronePtr->GetTripData()->IncreaseBatteryUsed(dt);
      dc->IncreaseTotalBatUsage(dt);
    }

    if (battery <= 0) {
      outOfBattery = true;
      Reservice* mediator = Reservice::GetInstance();
      RechargerDrone* nearest =
          mediator->FindNearestAvailableRechargerDrone(this);
      if (nearest != nullptr) {
        rDrone = nearest;
      } else {
        rDrone = nullptr;
      }
    }
  } else {
    if (rDrone != nullptr) {
      if (rDrone->GetFinishedRechargingDrone() == true) {
        dronePtr->GetTripData()->IncrementRecharges();
        dc->IncrementTotalRecharges();
        outOfBattery = false;
        rDrone = nullptr;
        if (dronePtr->GetTripData()) {
          dronePtr->GetTripData()->IncrementRecharges();
        }
      }
    } else {
      Reservice* mediator = Reservice::GetInstance();
      RechargerDrone* nearest =
          mediator->FindNearestAvailableRechargerDrone(this);
      if (nearest != nullptr) {
        rDrone = nearest;
      } else {
        rDrone = nullptr;
      }
    }
  }
}
