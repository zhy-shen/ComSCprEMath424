"""
Module for my functions
"""
e = 2.7182818284590451

def sqrt(x, debug = 0, initial = 3, kmax = 100, diff = 10**-14):
    """
    Newton's method for solving square root
    x: non negative number to solve for square root
    debug: whether to print intermediate results on every loop
    initial: the initial guess for newton's method, non-negative
    kmax: maximum number of iterations, default 100
    diff: tolerance between loops
    """
    
    #convert input to float
    x = 1.0 * x
    
    #check if input meets requirements
    if x == 0.0:
        return 0.0
    elif x < 0.0:
        print("ERROR: Input x must be non negative")
        return -1.0
    
    #set s to initial, default 3
    s = initial
    for k in range(kmax):
        if debug == 1:
            print("iteration: " + str(k) + " result: " + str(s))
        
        sold = s
        s = 0.5*(s + x/s)
        
        #run Newton's method until the difference is under the preset limit
        if (abs(s - sold) < diff):
            break
    return s

def test_sqrt():
    """
    testing sqrt function between this and numpy
    """
    import numpy as np
        
    #array: numbers to test between myfuncs and numpy
    array = [2, 6, 10, 20, 80]
    
    for i in range(0, len(array)):
        print("Testing sqrt with x as " + str(array[i]) + "...")
        print(" myfunc: " + str(sqrt(array[i])))
        print(" numpy:  " + str(np.sqrt(array[i])))
        print(" diff:   " + str(abs(np.sqrt(array[i]) - sqrt(array[i]))))
        print("")

def exp(x, debug = 0, kmax = 100, diff = 10**-14):
    """
    Taylor series to compute the exponential
    x: number to solve for exponential
    debug: whether to print intermediate results on every loop
    kmax: maximum number of iterations, default 100
    diff: tolerance between loops
    """
    
    #round input
    x0 = int(round(x))
    z = x - x0
    tempNum = 0
    
    #calculates iterations, default is 100
    for i in range(0, kmax):
        currentNum = (e ** x0) * tempNum
        tempNum += (z ** i) / factorial_rec(i)
        if (debug == 1):
            print("iteration: " + str(i) + " result: " + str((e ** x0) * tempNum))
        
        #run loop until difference is lower than the set tolerance
        if  (abs((e ** x0) * tempNum - currentNum) < diff):
            break
    return (e ** x0) * tempNum
    
def test_exp():
    """
    testing exp function between this and numpy
    """
    import numpy as np
    
    #array: numbers to test between myfuncs and numpy
    array = [2, 4, 6, 8, 10]
    
    for i in range(0, len(array)):
        print("Testing exp with x as " + str(array[i]) + "...")
        print(" myfunc: " + str(exp(array[i])))
        print(" numpy:  " + str(np.exp(array[i])))
        print(" diff:   " + str(abs(np.exp(array[i]) - exp(array[i]))))
        print("")
    
    
    
def factorial(x):
    """
    function for solving the factorial
    """
    temp = 1
    
    #round input
    x = int(round(x))
    
    #checks validity of input
    if(x < 0):
        return -1;
    
    if x == 0:
        return 1;
    
    #loops from one to x to get the factorial
    for i in range(1, x + 1):
        temp *= i
        
    return temp

#recursive factorial
def factorial_rec(x):
    """
    function for solving factorial, recursively
    """
    
    #round input
    x = int(round(x))
        
    #checks validity of input
    if(x < 0):
        return -1;
        
    if x == 0:
        return 1;
    
    #calls this function recursively to get the result
    else:
        s = x * factorial_rec(x-1)
    return s


def test_factorial():
    """
    testing factorial functions between this and numpy
    """
    import numpy as np
        
    #array: numbers to test between myfuncs and numpy
    array = [2, 4, 6, 8, 10, 20]
    
    for i in range(0, len(array)):
        print("Testing factorial with x as " + str(array[i]) + "...")
        print(" myfunc:           " + str(factorial(array[i])))
        print(" myfunc recursive: " + str(factorial_rec(array[i])))
        print(" numpy:            " + str(np.math.factorial(array[i])))
        print(" diff:             " + str(abs(factorial(array[i]) - np.math.factorial(array[i]))))
        print(" diff (recursive): " + str(abs(factorial_rec(array[i]) - np.math.factorial(array[i]))))
        print("")

def ln(x, guess = None, debug = 0, kmax = 100, diff = 10**-14):
    """
    Newton's method for calculating natural log
    x: number to solve for natural log
    guess: initial guess for solving, default none
    debug: whether to print intermediate results on every loop
    kmax: maximum number of iterations, default 100
    diff: tolerance to end loop early
    """
    
    if (not guess):
        s = x * 1.0
    else:
        s = guess
    
    #loops up to kmax, 100 default
    for i in range(kmax):
        currentNum = s
        s = s - 1 + x * exp(-1.0 * s)
        if (debug == 1):
            print("iteration: " + str(i) + " result: " + str(s))
        if (abs(s - currentNum) < diff):
            break
    return s

def test_ln():
    """
    testing natural log functions between this and numpy
    """
    import numpy as np
    
    array = [2, 6, 10, 20, 80]
    
    for i in range(0, len(array)):
        print("Testing ln with x as " + str(array[i]) + "...")
        print(" myfunc: " + str(ln(array[i])))
        print(" numpy:  " + str(np.log(array[i])))
        print(" diff:   " + str(abs(np.log(array[i]) - ln(array[i]))))
        print("")
