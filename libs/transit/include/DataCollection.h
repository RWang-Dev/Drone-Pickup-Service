#ifndef DATACOLLECTION_H_
#define DATACOLLECTION_H_

#include <vector>

#include "math/vector3.h"

class DataCollection{
    private:
        static DataCollection* instancePtr;
        DataCollection() {};

        float distanceTraveled;
        float distanceLeft;
        int numTrips; //Remove later
        Vector3 dronePosition;
        Vector3 robotPosition;
        int versionNum = 0;

    public:
        DataCollection(const DataCollection& o) = delete;
        static DataCollection* getInstance();
         /**
         * @brief Sets private variables using data collected from drone and robot
         * @param 
         */
        void setValues();

        /**
         * @brief Uses data collected to create CSV file
         * @param 
         */
        void outputCSVFile();
};

#endif