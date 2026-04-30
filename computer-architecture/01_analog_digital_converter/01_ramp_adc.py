# Ramp (Counter-Type) ADC Method

import numpy as np
import matplotlib.pyplot as plt

def mybin(num, n):
    """Convert decimal number to n-bit binary string"""
    s = ""
    while num > 0:
        m = num % 2
        num = num // 2
        s = str(m) + s
        n -= 1
    while n > 0:
        s = "0" + s
        n -= 1
    return s

# PARAMETERS
Vmin = 0
Vmax = 5.0
Va   = 1.7        # Input voltage
n    = 3          # Resolution

Vo = -1
i = 1
rn = 4            # Rounding precision

# Quantization step
q = round((Vmax - Vmin) / (2**n - 1), rn)

gr = 1
grRampVd = np.zeros(2**n)
grRampVa = np.zeros(2**n)

print("Vmin", Vmin, sep="\t")
print("Vmax", Vmax, sep="\t")
print("n", n, sep="\t")
print("q", q, sep="\t")
print("\n")
print("Va", "Binary", "Vd", "Vo", sep='\t')
print("-----------------------------")

# Ramp counting loop
while Vo < 0:
    Vd = round(i * q + Vmin, rn)   # DAC output
    Vo = round(Vd - Va, rn)        # Comparator output

    grRampVa[i - 1] = Va
    grRampVd[i - 1] = Vd

    print(Va, mybin(i, n), Vd, Vo, sep='\t')

    i += 1

# Fill remaining values for plotting
for j in range(i - 1, 2**n):
    grRampVa[j] = Va
    grRampVd[j] = Vd

# Error calculation
err = round(Va - Vd, rn + 2)
print("Quantization Error:", err)

# Plot
if gr == 1:
    axes = plt.gca()
    axes.set_ylim([Vmin, Vmax])
    plt.plot(grRampVd, 'ro', grRampVa, 'b--')
