#include "BatteryDecorator.h"
#include "Reservice.h"
#include "RechargerDrone.h"
#include "DataCollection.h"
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
  this->dronePtr = (Drone*)ent;
  dc = DataCollection::GetInstance();
}

BatteryDecorator::~BatteryDecorator() {
  delete drone;
}

void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    if (outOfBattery == false) {
      drone->Update(dt, scheduler);
      if (drone->GetAvailability() == false) {
        battery -= 2*dt;
        // drone = dynamic_cast<Drone*>(drone);
        dronePtr->GetTripData()->IncreaseBatteryUsed(2*dt);
        dc->IncreaseTotalBatUsage(2*dt);
      }
      else {
        battery -= dt;
        dronePtr->GetTripData()->IncreaseBatteryUsed(dt);
        dc->IncreaseTotalBatUsage(dt);
      }

      if (battery <= 0) {
        outOfBattery = true;
        Reservice* mediator = Reservice::GetInstance();
        rDrone = mediator->FindNearestAvailableRechargerDrone(this);
      }
    } else {
        if (rDrone->GetFinishedRechargingDrone() == true) {
          dronePtr->GetTripData()->IncrementRecharges();
          dc->IncrementTotalRecharges();
          outOfBattery = false;
          rDrone = nullptr;
        }
    }
}