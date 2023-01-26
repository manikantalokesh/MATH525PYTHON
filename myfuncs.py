""" square root function defined bby newtons method"""
def sqrt_newton(x,printshow=0,initial_guess=1.0,kmax=100,tol=10e-14):
  x=1.0*x
  print(" squareroot ny newton")

  if x==0.0:
    return 0.0
  elif x<0.0:
    print("error input")
    return -1
  
  s=initial_guess
  for k in range(kmax):
    if printshow>0:
      print("before iteration: %d , s=%20.15f"%(k,s))
    sold =s;
    s=0.5*(s+x/s)
    if (abs((s-sold)/x)<tol):
      break
    if printshow>0:
      print("after iteration: %d , s=%20.15f"%(k+1,s))
  return s


def myfactorial(x):
    '''
    factorial of a number and x is input
    '''
    s=1
    for k in range (1,x):
        s=s*(k+1)
    return s



'''
expoential function
'''
def exp(x,kmax=100,initial_guess=0,tol=10e-14, printshow=0):
    """
    Returns the exponent of the given real number
    x = real number
    kmax = number of iteration (default is 100)exit()
    initial_guess = initial guess (default is 1)
    tol = tolerance of the iteration (default is 1e-14)
    printshow = to check if user want to print or not (1 to print-0 to do not print)
    """
    import math  #to import math functions for pow func
    x0 = int(round(x))
    e = 2.7182818284590451
    z = x-x0
    expx0 = math.pow(e,x0)
    s=initial_guess
    for k in range(kmax):
        if printshow==1:
            print("Before iteration %2d, s = %20.15f" % (k,s))
        sold=s
        s= s+ (math.pow(z,k))/(myfactorial(k))
        if abs(sold-s)<tol:
            break
    return expx0*s

def ln(x,kmax=100,initial_guess=0,tol=10e-14, printshow=0):
  import math
  s=1
  for k in range(kmax):
    sold=s
    s=s-(((exp(s,kmax)-x)/exp(s,kmax)))
    if (abs(sold-s)<tol):
      break
  return s
