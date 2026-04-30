# Successive Approximation ADC Method

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
Vmin = -2.55       # Minimum analog value
Vmax = 2.55        # Maximum analog value
Va   = 1.29        # Input analog voltage
n    = 9           # Resolution (bits)

Vo = -1.0          # Initial comparator output
rn = 4             # Rounding precision
i = n - 1

# Quantization step (quantum)
q = round((Vmax - Vmin) / (2**n - 1), rn)

# Plot control
gr = 1
grRampVd = np.zeros(n)
grRampVa = np.zeros(n)

print("Vmin", Vmin, sep="\t")
print("Vmax", Vmax, sep="\t")
print("n", n, sep="\t")
print("q", q, sep="\t")
print("\n")
print("Step", "Va", "Binary", "\tHEX", "Vd", "Vo", sep='\t')
print("---------------------------------------------------------")

base = 0

# Successive approximation loop
while i >= 0:
    bias = 2**i
    Vd = round((base + bias) * q + Vmin, rn)  # DAC output
    Vo = round(Vd - Va, rn)                  # Comparator output

    grRampVa[n - i - 1] = Va
    grRampVd[n - i - 1] = Vd

    print(n - i, Va, mybin(base + bias, n), hex(base + bias), Vd, Vo, sep='\t')

    i -= 1

    # Update base if approximation is valid
    if Vo <= 0:
        base += bias

# Final error
err = round(Va - Vd, rn + 2)
print("Quantization Error:", err)

# Plot
if gr == 1:
    axes = plt.gca()
    axes.set_ylim([Vmin, Vmax])
    plt.plot(grRampVd, 'ro', grRampVa, 'b--')
