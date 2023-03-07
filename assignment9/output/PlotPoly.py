# def PlotPoly():
#     fid =open('poly.data','r')
#     Numpts=0
#     while True:
#         line =fid.readline()
#         if not line: break
#         Numpts=Numpts+1
#     fid.close()
    
#     import numpy as np
#     import string as str
#     import matplotlib.pyplot as plt

#     x=np.zeros(Numpts,dtype=float)
#     y=np.zeros(Numpts,dtype=float)
#     fid=open('poly.data','r')
#     for k in range(0,Numpts):
#         linestring=fid.readline()
#         linelist=str.split(linestring)
#         linelinst=linestring.split()
#         x[k]=float(linelinst[0])
#         y[k]=float(linelinst(1))
#         plt.rc("font",size=16); plt.figure(1)   #Third plot the result
#         plt.plot(x,y,linestyle='dashed',linewidth=2,marker="o",color='red',markersize=12); 
#         plt.xlim(-1.0,1.0); plt.xticks([-1.0,-0.5,0.0,0.5,1.0])
#         ax=plt.gca(); ax.grid(True)
#         plt.xlabel("x-axis",size=20); plt.ylabel("y-axis",size=20)
#         plt.title("polynomial plot", size=20)
#         plt.savefig('legendre.png',dpi=400,bbox_inches='tight')
#         plt.show(); 

# if __name__=="__main__":
#     PlotPoly(); 




def PlotPoly():
    # First, figure out how many floats there are
    Numpts=0
    fid = open('poly.data', 'r')
    while True:
        line = fid.readline()
        if not line: break
        Numpts = Numpts+1
    fid.close()

    import numpy as np; import string as str;
    import matplotlib.pyplot as plt
    # Second, read-in all the floats
    x = np.zeros(Numpts,dtype=float)
    y = np.zeros(Numpts,dtype=float)
    fid = open('poly.data', 'r')
    for k in range(0,Numpts):
        linestring = fid.readline()
        #linelist = str.split(linestring)
        linelist = linestring.split()
        x[k] = float(linelist[0])
        y[k] = float(linelist[1]) 
    plt.rc("font", size=16); plt.figure(1)
    plt.plot(x,y,linestyle="dashed",linewidth=2,marker="o",
    color="red",markersize=12)
    plt.xlim(-1.0,1.0); plt.xticks([-1.0,-0.5,0.0,0.5,1.0])
    ax = plt.gca(); ax.grid(True)
    plt.xlabel("x-axis",size=20); plt.ylabel("y-axis",size=20)
    plt.title("Polynomial Plot",size=20)
    plt.savefig('legendre.png',dpi=400,bbox_inches='tight')
    plt.show(); 
if __name__ == "__main__":
    PlotPoly()