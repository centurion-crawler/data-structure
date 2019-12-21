from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
import matplotlib 
import numpy as np
import math 
sigma1=float(input('σ1:'))
mu1=float(input('μ1:'))
sigma2=float(input('σ2:'))
mu2=float(input('μ2:'))
rho=float(input('ρ:'))
x0=float(input('x0:'))
y0=float(input('y0:'))
x1=float(input('x1:'))
y1=float(input('y1:'))
def r(x, y):
    return np.sqrt(x**2+y**2)
def p(xi,yi):
    return np.log(1/(2*math.pi*sigma1*sigma2*math.sqrt(1-rho**2))*np.exp(-1/(2*math.sqrt(1-rho**2))*(((xi-mu1)/sigma1)**2+((yi-mu2)\
    /sigma2)**2-2*rho*(xi-mu1)*(yi-mu2)/(sigma1*sigma2))))
def f(x,y):
    g=0
    A=(x1-x0)*(y1-y0)
    Ai=[]
    fq=[]
    fp=[]
    Ai=Ai+[(x1-x)*(y1-y)]+[(x-x0)*(y1-y)]+[(x-x0)*(y-y0)]+[(x1-x)*(y-y0)]
    fq=fq+[p(x,y0)]+[p(x1,y)]+[p(x,y1)]+[p(x0,y)]
    fp=fp+[p(x0,y0)]+[p(x1,y0)]+[p(x1,y1)]+[p(x0,y1)]
    for i in range(4):
        g=g+(Ai[i]+Ai[(i+1)%4])*fq[i]-Ai[i]*fp[i]        
    return np.exp(g/A)
x = np.linspace(x0+0.01,x1-0.01,100)
y = np.linspace(x0+0.01,y1-0.01,100)
X, Y = np.meshgrid(x, y)
Z = f(X,Y)
plt.figure(1)
ax = plt.axes(projection='3d')
ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_title('interp2 f(x,y)')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
x = np.linspace(x0+0.01,x1-0.01,100)
y = np.linspace(x0+0.01,y1-0.01,100)
X, Y = np.meshgrid(x, y)
Z = np.exp(p(X,Y))
plt.figure(2)
ax = plt.axes(projection='3d')
ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap='viridis', edgecolor='none')
ax.set_title('function f(x,y)')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
plt.show()