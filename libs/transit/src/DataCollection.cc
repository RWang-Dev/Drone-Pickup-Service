#include "DataCollection.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

DataCollection* DataCollection::instance = nullptr;

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

  csv << trip->getTripID() << ",";
  csv << trip->getDroneID() << ",";
  csv << trip->getDistanceTraveled() << ",";
  csv << trip->getRoutingAlgorithm() << ",";
  csv << trip->getBatteryUsed() << ",";
  csv << trip->getRecharges();
  
  return csv.str();
}

void DataCollection::AddTrip(struct TripData *trip) {
  trips.push_back(trip);

  totalDistance += trip->getDistanceTraveled();
  totalRecharges += trip->getRecharges();
  totalBatteryUsage += trip->getBatteryUsed();
  currentTripId++;
} 

bool DataCollection::WriteCSVFile(std::string filename) {
  
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

bool DataCollection::OutputCSVFile() {
  std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
  std::time_t now_t = std::chrono::system_clock::to_time_t(now);

  std::stringstream time_stream;
  time_stream << "simdata-";
  time_stream << std::put_time(std::localtime(&now_t), "%Y%m%d%H%M%S");
  time_stream << ".csv";

  std::string filename = time_stream.str();

  return WriteCSVFile(filename);
}
