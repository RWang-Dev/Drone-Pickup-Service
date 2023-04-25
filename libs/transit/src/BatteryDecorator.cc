#include "BatteryDecorator.h"
#include "Reservice.h"
#include "RechargerDrone.h"
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
}

BatteryDecorator::~BatteryDecorator() {
  delete drone;
}

void BatteryDecorator::Update(double dt, std::vector<IEntity*> scheduler) {
    // std::cout << battery << std::endl;
    if (outOfBattery == false) {
      drone->Update(dt, scheduler);
      if (drone->GetAvailability() == false) {
        battery -= 2*dt;
        // std::cout << drone->GetId() << " Battery level: " << battery << std::endl;
      }
      else {
        battery -= dt;
      }

      if (battery <= 0) {
        outOfBattery = true;
        // Call reservice's FindNearestAvailableRechargerDrone function once
        Reservice* mediator = Reservice::GetInstance();
        rDrone = mediator->FindNearestAvailableRechargerDrone(drone);
      }
    } else {
        if (rDrone->GetFinishedRechargingDrone() == true) {
          battery = 100;
          outOfBattery = false;
          rDrone = nullptr;
        }
    }
}