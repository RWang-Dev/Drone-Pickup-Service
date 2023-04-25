#include "BatteryDecorator.h"
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
//   std::cout << battery;
    drone->Update(dt, scheduler);
//   if (!outOfBattery) {
//     if (!(drone->GetAvailability())){
//         battery -= 2*dt;
//     }
    
//     if (battery <= 0) {
//         // Call mediator's function once
//         outOfBattery = true;
//     }
//   }
}
