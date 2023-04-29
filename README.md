# Write up

## Team information
**Team-001-36**  
Stephen Ma, ma000094  
Robert Wang, wan00379  
Robert Tan, tan00222  
Calvin Theis, theis530

## Youtube Presentation Link
https://www.youtube.com/watch?v=dQw4w9WgXcQ&ab_channel=RickAstley

## Docker Hub Link


## Project Overview
This project is a drone simulation system that takes place on the University of Minnesota campus. The user is able to schedule trips by setting the pickup location and final destination of a robot. A drone will then pick up the robot and bring it to its destination. Each drone also has a battery life that is decremented over the course of the simulation. When the drone runs out of battery, a special recharger drone will fly to the drone and charge its battery back up to 100%. Lastly, the user can also collect information on all completed trips in the simulation by pressing a button that outputs a CSV file.

## How to Run the Simulation

### Git: 
In order to run the simulation, first git clone this repository. Then, cd into the project directory.  
In order to build the project, type ```make -j``` in the terminal. To run the project, type ```./build/bin/transit_service 8081 apps/transit_service/web/``` in the terminal.  

Navigate to http://127.0.0.1:8081 and you should see a visualization.  
Navigate to http://127.0.0.1:8081/schedule.html and you should see a page to schedule the trips.  
*Note: 8081 will depends on what port you used. If you use port 8082, then it will be http://127.0.0.1:8082 instead.*

### Docker:
(note this needs to be checked)
Pull the docker image with ```docker pull <image_name>```
Next, run the image with ```docker run --rm -it -p <local_port>:<container_port> <image_name>```
From there, you are free to navigate to the website links listed above in the Git section.

## What the Simulation Does
When the user schedules a trip for the drone to pick up and bring a robot to a specified destination, they will also choose the routing algorithm that will be used by the drone to reach that location (E.g. A*, Depth first search, Dijkstra's). Once the trip has been successfully scheduled, the nearest available (not already assigned to a robot) drone will be assigned to the newly created robot and will start flying directly towards it. Then, the drone will navigate to the final destination using the chosen routing algorithm. Because the drone's battery is constantly decremented throughout the simulation, the drone may run out of battery and stop moving in the middle of a trip. When this occurs, the closest available (not already assigned to recharging a drone) recharger drone will head directly to the dead drone. Once the recharger drone reaches the dead drone, the drone will immediately resume movement after being fully recharged by the recharger drone. After the drone reaches the final destination and drops off the robot, the drone then becomes available for the next trip. For each completed trip, the drone that completed it will collect data pertaining to battery usage, distance traveled, routing algorithm, etc. This information is saved and made readily available for outputting and analyzing.

## New Features
### Feature 1: Battery and Recharge

#### What does it do?
Our first extension uses the Decorator, Mediator, and Singleton design patterns in order to implement drones that have a set battery life. The battery decrements when idle and in use, and the drone ceases to function once battery runs out. Once this happens, the drone will call the mediator, which will then route the closest available recharger drone to the depleted drone. The recharger drone then recharges the drone over time until its battery is full. The drone will then resume operation as normal. 

#### Why is it significantly interesting?
This feature helps create a more realistic simulation, as drones cannot have infinite battery life in real life. We can simulate the performance of different battery lives and how much time is sacrificed due to recharge time. 

#### How does it add to the existing work?
All drones now have a battery decorator that wraps the actual drone entity. All commands to the drone go through this decorator, which also keeps track of the battery variable. When conditions are met, the drone's activities are paused while the decorator calls upon the mediator singleton to request recharge. The closest recharger drone then beelines towards the depleted drone and charges it every update cycle until the battery is full.

#### Which design patterns are implemented and why?
The decorator pattern is used to give all transporation drones a battery. The decorator deals with anything battery related while keeping the drone's update function untouched. This is useful in keeping all battery related functions separate from the drone's functions, meaning this decorator could be applied to more things beyond just the drones. The drones could also be used without the battery decorator, in case simulations without batteries are desired.

The mediator and singleton patterns are combined to provide a convenient place for the transporation drones to request a recharge and the recharger drones to receive assignments. Singleton is used to ensure there is only one mediator since only one is needed for all drone communication. Mediator is used to keep communication between drone and recharger drone separate as well as to provide a convenient place to calculate the closest recharger drone.

#### How to use the new feature
This feature is not able to be interacted at all by the user directly. It automatically operates as drones move throughout the simulation.

### Feature 2: Data Collection

#### What does it do?
This extension utilizes the Singleton design pattern to collect information about every trip taken by the drones. The information can then be outputted as a CSV file to be inspected and analyzed. Specific trends could be identified in the data to provide more insightful information about the drone's operation.

#### Why is it significantly interesting?
As a simulation, it is useful to collect statistics on the trips taken by drones in order to run analysis. With this information, one could optimize the drone routing algorithms or battery life for different situations. 

#### How does it add to the existing work?
All drones now utilize the TripData class to store information about each trip taken. At the end of every trip, the information is saved to the singleton and the drone gets a new TripData to save information about the next trip. In addition, there is a new button on the schedule html that can output the information stored by the DataCollection singleton as a CSV.

#### Which design patterns are implemented and why?
The singleton pattern is used to provide all drones with one single data collection object. This ensures that all the information is conveniently collected in one place regardless of how many drones there are in the simulation. 

#### How to use the new feature
The actual collection of data is unable to be determined by the user directly. In other words, the user cannot determine what data is collected nor how it is outputted. The only way the user can interact with this feature is by pressing the ```Output CSV``` button on the schedule html page. This will output the CSV file for the user to analyze.

## Sprint Retrospective
