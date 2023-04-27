# Write up

## Team information
**Team-001-36**  
Stephen Ma, ma000094  
Robert Wang, wan00379  
Robert Tan, tan00222  
Calvin Theis, theis530  

## Project Overview
This project is a drone simulation system that takes place on the University of Minnesota campus. The user is able to schedule trips by setting the pickup and location and final destination of a robot. A drone will then pick up the robot and bring it to its destination. 

## How to Run the Simulation
In order to run the simulation, first git clone this repository. Then, cd into the project directory.  
In order to build the project, type ```make -j``` in the terminal. To run the project, type ```./build/bin/transit_service 8081 apps/transit_service/web/``` in the terminal.  
Navigate to http://127.0.0.1:8081 and you should see a visualization.  
Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.  
*Note: 8081 will depends on what port you used. If you use port 8082, then it will be http://127.0.0.1:8082 instead.*

## What the Simulation Does
When the user schedules a trip for the drone to pick up and bring a robot to a specified destination, they can also choose which routing algorithm will be used to reach that location (E.g. A*, Depth first search, Dijkstra's). 

## New Features
### Feature 1: 
Our first extension uses the Decorator, Mediator, and Singleton design patterns in order to 
### Feature 2:

## Sprint Retrospective
