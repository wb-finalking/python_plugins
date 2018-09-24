import numpy as np
import matting

a = np.array([[1,2],[3,4]], dtype=int)
b = np.array([[1,2],[3,4]], dtype=int)
c = matting.my_add(a, b)
print(c)