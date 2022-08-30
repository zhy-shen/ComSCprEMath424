"""
Demo for my functions
"""
import myfuncs as my
import numpy as np
exp = np.abs(my.exp(5)-np.exp(5))
print("exp(5) difference = " + str(exp))
exp = np.abs(my.exp(8.2)-np.exp(8.2))
print("exp(8.2) difference = " + str(exp))
print("")
ln = np.abs(my.ln(19)-np.log(19))
print("ln(19) difference = " + str(ln))
ln = np.abs(my.ln(3)-np.log(3))
print("ln(3) difference = " + str(ln))