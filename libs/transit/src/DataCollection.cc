#include "DataCollection.h"
#include "TripData.h"

DataCollection* DataCollection::GetInstance() {
    if (instance == nullptr) {
        instance = new DataCollection();
        return instance;
    } else {
        return instance;
    }
}

void DataCollection::AddTrip(struct TripData *trip) {
  trips.push_back(trip);

  totalDistance += trip->distanceTraveled;
  totalRecharges += trip->recharges;
  totalBatteryUsage += trip->batteryUsed;
  currentTripId++;
} 

void DataCollection::OutputCSVFile() {
  
}
