#ifndef RESERVICE_H_
#define RESERVICE_H_

#include "RechargerDrone.h"
#include "IEntity.h"
#include <vector>

class Reservice {
public:
  Reservice();
  Reservice* GetInstance();

  RechargerDrone* FindNearestAvailableRechargerDrone(IEntity*);

  void AddRechargerDrone(RechargerDrone* drone);
  void RemoveRechargerDrone(RechargerDrone* drone);

private:
  std::vector<RechargerDrone *> rechargerDrones;
  static Reservice *instance;
};

#endif
