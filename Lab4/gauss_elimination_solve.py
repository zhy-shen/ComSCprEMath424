"""
Module gaussian elimination
"""
import numpy as np

A = np.array([[-2,0.0,1.0],[-1.0,7.0,1.0],[5.0,-1.0,1.0]])
b = np.array([-4.0,-50.0,-26.0])

AA = A.copy();
bb = b.copy();

rows = 3;
cols = 3;

for col in range(cols - 1):
    for row in range(col + 1 , rows):
        next = A[row][col]
        current = A[col][col]
        ratio = next / current
        
        A[row] = A[row] - ratio * A[col]
        b[row] = b[row] - ratio * b[col]
        #print(A)
        #print(b)

x = np.zeros(3)
#from second to last row to first row
#row - 2: second to last row
LastRowIndex = rows - 1;

#backfill
for row in range(LastRowIndex, -1, -1):
    nextRow = row + 1
    print('row' + str(row))
    for col in range(cols - 1, row, -1):
        #print current backfill cell
        print('[{}][{}]'.format(row, col))
        bdiff = A[row][col] * x[col]
        b[row] = b[row] - bdiff
        print(x)
    x[row] = b[row] / A[row][row]
    #clear next bit

print('custom result: ')
print(x)
from numpy import linalg as la
xx = la.solve(AA,bb)

print('numpy: ')
print(xx)
