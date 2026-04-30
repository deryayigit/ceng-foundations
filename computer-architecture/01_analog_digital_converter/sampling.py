# Sampling Demonstration

import numpy as np
import matplotlib.pyplot as plt

sf = 100        # Number of samples

pi_n = 1
A = 1
Gmin = 0
Glen = 3.75
Gmax = Gmin + Glen
scale = Glen / 2.0

# Continuous signal
x = np.linspace(0, pi_n * 2 * np.pi, 1000)
y = scale * (np.sin(x) + A) + Gmin

# Sampled signal
x2 = np.linspace(0, pi_n * 2 * np.pi, sf)
y2 = scale * (np.sin(x2) + A) + Gmin

plt.plot(x, y, "b-", x2, y2, "ro")
plt.grid(True)
plt.show()
