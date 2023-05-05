
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


# astar section

# create and print A matrix
battA = astar['Battery Used (%)'].values
rechargeA = astar['No. Recharge Sessions'].values
distA = astar['Distance Traveled'].values

A = np.vstack([distA, np.ones(len(distA))]).T

# solve for slope, intercept (dx + c) and error
param, residual, rank, singular = np.linalg.lstsq(A, battA, rcond=None)
dA = param[0]
cA = param[1]
print("Slope: ", dA)
print("Intercept: ", cA)
print("Error^2: ", residual[0])
print()

# create and show graph
plt.plot(distA, battA, 'o', label='Og data', markersize = 5) # og data
plt.plot(distA, dA*distA + cA, 'r', label='Least Squares Fit') # LLS line
plt.legend()
plt.xlabel("Distance Traveled (astar)")
plt.ylabel("Battery Used (%) (astar)")
# plt.show()
plt.savefig("assets/aStar.png")
plt.close()


# dfs section

# create and print A matrix
battB = dfs['Battery Used (%)'].values
rechargeB = dfs['No. Recharge Sessions'].values
distB = dfs['Distance Traveled'].values

A = np.vstack([distB, np.ones(len(distB))]).T

# solve for slope, intercept (dx + c) and error
param, residual, rank, singular = np.linalg.lstsq(A, battB, rcond=None)
dB = param[0]
cB = param[1]
print("Slope: ", dB)
print("Intercept: ", cB)
print("Error^2: ", residual[0])
print()

# create and show graph
plt.plot(distB, battB, 'o', label='Og data', markersize = 5) # og data
plt.plot(distB, dB*distB + cB, 'r', label='Least Squares Fit') # LLS line
plt.legend()
plt.xlabel("Distance Traveled (dfs)")
plt.ylabel("Battery Used (%) (dfs)")
# plt.show()
plt.savefig("assets/dfs.png")
plt.close()


# dijk section

# create and print A matrix
battC = dijkstra['Battery Used (%)'].values
rechargeC = dijkstra['No. Recharge Sessions'].values
distC = dijkstra['Distance Traveled'].values

A = np.vstack([distC, np.ones(len(distC))]).T

# solve for slope, intercept (dx + c) and error
param, residual, rank, singular = np.linalg.lstsq(A, battC, rcond=None)
dC = param[0]
cC = param[1]
print("Slope: ", dC)
print("Intercept: ", cC)
print("Error^2: ", residual[0])
print()

# create and show graph
plt.plot(distC, battC, 'o', label='Og data', markersize = 5) # og data
plt.plot(distC, dC*distC + cC, 'r', label='Least Squares Fit') # LLS line
plt.legend()
plt.xlabel("Distance Traveled (dijkstra)")
plt.ylabel("Battery Used (%) (dijkstra)")
# plt.show()
plt.savefig("assets/dijkstra.png")
plt.close()


# graph all lls

plt.plot(distA, dA*distA + cA, label='Least Squares astar', color='red') # LLS line
plt.plot(distB, dB*distB + cB, label='Least Squares dfs', color='green') # LLS line
plt.plot(distC, dC*distC + cC, label='Least Squares dijkstra', color='blue') # LLS line
plt.legend()
plt.xlabel("Distance Traveled")
plt.ylabel("Battery Used (%)")
# plt.show()
plt.savefig("assets/all_lls.png")
plt.close()