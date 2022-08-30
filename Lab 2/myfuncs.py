"""
Module for my functions
"""
e = 2.7182818284590451

#taylor series to compute the exponential
def exp(x, debug = 0, kmax = 100, diff = 10**-14):
    x0 = int(round(x))
    z = x - x0
    tempNum = 0
    
    #calculates iterations, default is 100
    for i in range(0, kmax):
        currentNum = (e ** x0) * tempNum
        tempNum += (z ** i) / factorial(i)
        if (debug == 1):
            print("iteration: " + str(i) + " result: " + str((e ** x0) * tempNum))
        if  (abs((e ** x0) * tempNum - currentNum) < diff):
            break
    return (e ** x0) * tempNum
    
#factorial function to help with calculating exponential
def factorial(x):
    temp = 1
    for i in range(1, x + 1):
        temp *= i
    return temp

#Newton's method for calculating ln
def ln(x, guess = None, debug = 0, kmax = 100, diff = 10**-14):
    
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
