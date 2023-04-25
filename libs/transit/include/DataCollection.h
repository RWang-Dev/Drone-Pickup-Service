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
  private: DataCollection() {};

     static DataCollection* instance;  // The single instance of DataCollection
     std::list<struct TripData> trips; // The trip data
     int totalDistance;                // Total distance traveled
     int totalRecharges;               // The total number of drone recharge sessions

  public:
     // Delete copy constructor & assignment operator.
     DataCollection(const DataCollection& o) = delete;
     DataCollection* operator=(const DataCollection& o) = delete;

     /**
      * Gets the single instance of DataCollection.
      */
     static DataCollection* getInstance();

     /**
      * Adds a trip the list of trips.
      * @param trip The trip to add.
      */
     void addTrip(struct TripData* trip);

     /**
      * @brief Uses data collected to create CSV file.
      */
     void outputCSVFile();
};

#endif
