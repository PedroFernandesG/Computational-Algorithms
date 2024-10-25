import matplotlib.pyplot as plt
import math

# Data
x = [10, 20, 30, 40, 50 ,60]
y = [222,842,1862,3282,5102,7322]

#Plot log-log
plt.loglog(x, y, marker='o', linestyle='--', color='b')

plt.title("Plot Log-Log")
plt.xlabel("X (Scale Log)")
plt.ylabel("Y (Scale Log)")

#Show 
plt.grid(True, which="both", linestyle="--")
plt.show()

deltaX = math.log10(x[2]) - math.log10(x[1])
deltaY = math.log10(y[2]) - math.log10(y[1])
print("Inclination --> ")
print(deltaY/deltaX)
