#include "BatteryDecorator.h"
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
}

BatteryDecorator::~BatteryDecorator() { delete drone; }

void BatteryDecorator::Update(double dt, std::vector<IEntity *> scheduler) {
  // std::cout << battery << std::endl;
  TripData *trip = drone->GetTripData();
  if (outOfBattery == false) {
    drone->Update(dt, scheduler);
    if (drone->GetAvailability()) {
      battery -= dt;
      if (trip)
        drone->GetTripData()->batteryUsed += dt;
      // std::cout << drone->GetId() << " Battery level: " << battery <<
      // std::endl;
    } else {
      battery -= 2 * dt;
      if (trip)
        drone->GetTripData()->batteryUsed += 2 * dt;
    }

    if (battery <= 0) {
      outOfBattery = true;
      // Call reservice's FindNearestAvailableRechargerDrone function once
      Reservice *mediator = Reservice::GetInstance();
      rDrone = mediator->FindNearestAvailableRechargerDrone(this);
    }
  } else if (rDrone->GetFinishedRechargingDrone() == true) {
    outOfBattery = false;
    rDrone = nullptr;
    if (trip)
      trip->recharges++;
  }
}
