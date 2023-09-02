from rs_decoder_py import Berlekamp_Decoder
import numpy as np 
before = np.zeros(255, dtype=np.int32)

before[1] = 12
before[248] = 235
before[6] = 9
before[30] = 12
before[45] = 44
t = 16
decoder = Berlekamp_Decoder(t)
after = decoder.Decode(before)

print("before decode: ")
print(before)

print("after decode:")
print(after)
