"""
Module for my functions
"""
e = 2.7182818284590451
def exp(x):
    x0 = int(round(x))
    z = x - x0
    num = 1 + z;
    for i in range(2, 100):
        num += (z ** i) / factorial(i)
    return (e ** x0) * num
def factorial(x):
    temp = 1
    for i in range(1, x + 1):
        temp *= i
return temp
def ln(x):
    s = x * 1.0
    for i in range(100):
        s = s - 1 + x * exp(-1.0 * s)
return s