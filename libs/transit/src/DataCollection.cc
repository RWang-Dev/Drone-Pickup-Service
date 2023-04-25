#include "DataCollection.h"
#include <sstream>
#include <fstream>
#include <iostream>

DataCollection* DataCollection::GetInstance() {
    if (instance == nullptr) {
        instance = new DataCollection();
        return instance;
    } else {
        return instance;
    }
}

std::string DataCollection::GetTripCSV(struct TripData* trip) {
  std::stringstream csv; // Use of sstream allows for advanced float formatting

  csv << trip->tripId << ",";
  csv << trip->droneId << ",";
  csv << trip->distanceTraveled << ",";
  csv << trip->routingAlgorithm << ",";
  csv << trip->batteryUsed << ",";
  csv << trip->recharges;
  
  return csv.str();
}

void DataCollection::AddTrip(struct TripData *trip) {
  trips.push_back(trip);

  totalDistance += trip->distanceTraveled;
  totalRecharges += trip->recharges;
  totalBatteryUsage += trip->batteryUsed;
  currentTripId++;
} 

bool DataCollection::OutputCSVFile(std::string filename) {
  
  // Try to open file
  std::ofstream csvOut { filename };
  if (!csvOut) {
    std::cerr << "Unable to open " << filename << std::endl;
    return false;
  }

  // Write header
  csvOut << "Trip ID" << ",";
  csvOut << "Drone ID" << ",";
  csvOut << "Distance Traveled" << ",";
  csvOut << "Routing Algorithm" << ",";
  csvOut << "Battery Used (%)" << ",";
  csvOut << "No. Recharge Sessions" << std::endl;

  // Write data
  for (TripData* trip : trips) 
    csvOut << GetTripCSV(trip) << std::endl;

  // Clean up
  csvOut.close();
  return true;
}
