#include "DataCollection.h"

DataCollection* DataCollection::getInstance() {
    if (instancePtr == nullptr) {
        instancePtr = new DataCollection();
        return instancePtr;
    }
    else {
        return instancePtr;
    }
}

void DataCollection::setValues() {

}

void DataCollection::outputCSVFile() {
    
}