import RS255
import numpy as np 
before = np.zeros(255, dtype=np.uint16)
after = np.zeros(255, dtype=np.uint16)
before[1] = 12
before[248] = 235
after[1] = 12
t = 16
RS255.berlekamp_decoder(t, before, after)

print("before decode: ")
print(before)

print("after decode:")
print(after)
