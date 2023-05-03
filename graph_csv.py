
import numpy as np
import pandas as pd
from matplotlib import pyplot as plt

# import data from csv
data = pd.read_csv("simdata-20230503173018.csv")

data.sort_values('Routing Algorithm', inplace=True)

# print(data)

astar = data[data['Routing Algorithm'] == "astar"]
dijkstra = data[data['Routing Algorithm'] == "dijkstra"]
dfs = data[data['Routing Algorithm'] == "dfs"]

# trip = data['Trip ID'].values
# drone = data['Drone ID'].values
# dist = data['Distance Traveled'].values
# rout = data['Routing Algorithm'].values
# batt = data['Battery Used (%)'].values
# recharge = data['No. Recharge Sessions'].values

# astar section

# create and print A matrix
batt = astar['Battery Used (%)'].values
recharge = astar['No. Recharge Sessions'].values
dist = astar['Distance Traveled'].values

A = np.vstack([dist, np.ones(len(dist))]).T

# solve for slope, intercept (dx + c) and error
param, residual, rank, singular = np.linalg.lstsq(A, batt, rcond=None)
d = param[0]
c = param[1]
print("Slope: ", d)
print("Intercept: ", c)
print("Error^2: ", residual[0])
print()

# create and show graph
plt.plot(dist, batt, 'o', label='Og data', markersize = 5) # og data
plt.plot(dist, d*dist + c, 'r', label='Least Squares Fit') # LLS line
plt.legend()
plt.xlabel("Distance Traveled (astar)")
plt.ylabel("Battery Used (%) (astar)")
plt.show()


# dfs section

# create and print A matrix
batt = dfs['Battery Used (%)'].values
recharge = dfs['No. Recharge Sessions'].values
dist = dfs['Distance Traveled'].values

A = np.vstack([dist, np.ones(len(dist))]).T

# solve for slope, intercept (dx + c) and error
param, residual, rank, singular = np.linalg.lstsq(A, batt, rcond=None)
d = param[0]
c = param[1]
print("Slope: ", d)
print("Intercept: ", c)
print("Error^2: ", residual[0])
print()

# create and show graph
plt.plot(dist, batt, 'o', label='Og data', markersize = 5) # og data
plt.plot(dist, d*dist + c, 'r', label='Least Squares Fit') # LLS line
plt.legend()
plt.xlabel("Distance Traveled (dfs)")
plt.ylabel("Battery Used (%) (dfs)")
plt.show()


# dijk section

# create and print A matrix
batt = dijkstra['Battery Used (%)'].values
recharge = dijkstra['No. Recharge Sessions'].values
dist = dijkstra['Distance Traveled'].values

A = np.vstack([dist, np.ones(len(dist))]).T

# solve for slope, intercept (dx + c) and error
param, residual, rank, singular = np.linalg.lstsq(A, batt, rcond=None)
d = param[0]
c = param[1]
print("Slope: ", d)
print("Intercept: ", c)
print("Error^2: ", residual[0])
print()

# create and show graph
plt.plot(dist, batt, 'o', label='Og data', markersize = 5) # og data
plt.plot(dist, d*dist + c, 'r', label='Least Squares Fit') # LLS line
plt.legend()
plt.xlabel("Distance Traveled (dijkstra)")
plt.ylabel("Battery Used (%) (dijkstra)")
plt.show()

