"""
Module gaussian elimination
"""
import numpy as np
import matplotlib.pyplot as plt

def GaussElimination(A,b):
    """
    Gaussian Elimination function, takes A as a matrix and b as an array
    """
    
    #set the row and column size
    rows = A.shape[0]
    cols = A.shape[1]

    for col in range(cols - 1):
        for row in range(col + 1 , rows):
            next = A[row][col]
            current = A[col][col]
            ratio = next / current
            #print('[{}][{}]'.format(row, col))
            #print(A)
            #loops and clears the matrix cells
            A[row] = A[row] - ratio * A[col]
            b[row] = b[row] - ratio * b[col]
            #print(A)
            #print('\n')

    #initialize return array
    x = np.zeros(rows)
    #from second to last row to first row
    LastRowIndex = rows - 1;

    #backfill
    for row in range(LastRowIndex, -1, -1):
        nextRow = row + 1
        #print('row' + str(row))
        for col in range(cols - 1, row, -1):
            #print current backfill cell
            #print('[{}][{}]'.format(row, col))
            bdiff = A[row][col] * x[col]
            b[row] = b[row] - bdiff
            #print(x)
        x[row] = b[row] / A[row][row]
        #clear next bit
        
    return x



if __name__ == '__main__' :
    """
    Main program to run the comparison between the estimate and the actual cosine function
    """
    from numpy import linalg as la
    
    #cosine function as baseline
    f = lambda x : np.cos(x)
    
    #set up the points
    x0 = -0.1
    x1 = -0.02
    x2 = 0.02
    x3 = 0.1
    
    """
    Ax, bx: matrix/array setup for approximating cosine
    """
    Ax = np.array([[x0**3, x0**2, x0**1, x0**0],[x1**3, x1**2, x1**1, x1**0],[x2**3, x2**2, x2**1, x2**0],[x3**3, x3**2, x3**1, x3**0]])
    bx = np.array([np.cos(x0), np.cos(x1), np.cos(x2), np.cos(x3)])
    
    #arrays from last lab
    #Ax = np.array([[-2,0.0,1.0],[-1.0,7.0,1.0],[5.0,-1.0,1.0]])
    #bx = np.array([-4.0,-50.0,-26.0])
    
    #print('custom result: ')
    x = GaussElimination(Ax.copy(),bx.copy())
    xx = la.solve(Ax.copy(),bx.copy())
    #print(x)

    #print('numpy: ')
    #print(xx)
    
    x_space = np.linspace(-0.1,0.1,101)
    y1 = [f(n) for n in x_space]
    y2 = x[0]*x_space**3 + x[1]*x_space**2 + x[2]*x_space**1 + x[3]*x_space**0
    
    """
    plot the original and the approximate lines and display them
    """
    plt.plot(x_space,y1,label='cosine')
    plt.plot(x_space,y2, 'o',label='approx')
    plt.legend(loc="upper left")
    plt.show()
