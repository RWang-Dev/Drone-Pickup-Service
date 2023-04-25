#ifndef RESERVICE_H_
#define RESERVICE_H_

#include "RechargerDrone.h"
#include "IEntity.h"
#include <vector>

class Reservice {
public:
  Reservice(const Reservice& o) = delete;
  static Reservice* GetInstance();

  RechargerDrone* FindNearestAvailableRechargerDrone(IEntity* drone);

  void AddRechargerDrone(RechargerDrone* drone);
  void RemoveRechargerDrone(RechargerDrone* drone);
  std::vector<RechargerDrone*> GetRechargerDrones() {return rechargerDrones; };

private:
  std::vector<RechargerDrone*> rechargerDrones;
  static Reservice* instancePtr; //Singleton static pointer which points to instance of this class
  Reservice() {}; //Default constructor
};

#endif
