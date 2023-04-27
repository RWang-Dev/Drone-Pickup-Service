#ifndef DATACOLLECTION_H_
#define DATACOLLECTION_H_

#include <vector>
#include <list>

#include "TripData.h"
#include "math/vector3.h"

/** 
 * Singleton class for collecting data about each trip that occurs during the
 * simulation.
 */
class DataCollection { 
private: 
  DataCollection() {};
    
  int currentTripId;                   // ID of the next trip to add.
  static DataCollection* instance;     // The single instance of DataCollection
  std::list<struct TripData*> trips;   // The trip data
  float totalDistance;                 // Total distance traveled
  float totalBatteryUsage;             // Total battery used
  int totalRecharges;                  // The total number of drone recharge sessions

  // Get the string representation of a trip
  static std::string GetTripCSV(struct TripData* trip);

  /**
    * @brief Uses data collected to create CSV file.
    * @param filename Location to write to
    * @return Whether the write succeeded
    */
  bool WriteCSVFile(std::string filename);
public:
  // Delete copy constructor & assignment operator.
  DataCollection(const DataCollection& o) = delete;
  DataCollection* operator=(const DataCollection& o) = delete;

  /**
    * Gets the single instance of DataCollection.
    */
  static DataCollection* GetInstance();

  /**
    * Adds a trip the list of trips.
    * @param trip The trip to add.
    */
  void AddTrip(struct TripData* trip);

  /**
   * Writes CSV file to a file derived from date and time.
   * @return Whether the write succeeded
   */
  bool OutputCSVFile();
};

#endif
