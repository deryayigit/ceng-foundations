# Quantization Visualization

import numpy as np
import matplotlib.pyplot as plt

fig = plt.figure()
ax = fig.add_subplot(1, 1, 1)

sf = 10        # Number of samples
pi_n = 1       # Number of pi cycles
A = 1          # Vertical offset
rn = 2         # Rounding precision

# PARAMETERS
n = 4          # Resolution
Gmin = 0
Glen = 3.75
Gmax = Gmin + Glen

scale = Glen / 2.0

# Quantization step
q = round((Gmax - Gmin) / (2**n - 1), rn)

# Grid for quantization levels
minor_ticks = np.arange(Gmin, Gmax + 1, q)
ax.set_yticks(minor_ticks, minor=True)
ax.grid(which='minor')

# Generate signal
x2 = np.linspace(0, pi_n * 2 * np.pi, sf)
y2 = scale * (np.sin(x2) + A) + Gmin

plt.plot(x2, y2, "r.")
plt.show()
