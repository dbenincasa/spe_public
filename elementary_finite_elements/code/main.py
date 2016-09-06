import numpy as np

from mesh import *
from basis_func import *
from assemble import *

from viewer import *

def clear_rows(A,b_nodes):
    d = np.diag(A)
    A[b_nodes,:] = 0
    A[b_nodes,b_nodes] = d[b_nodes]



if __name__ == "__main__":

    topo , x , y , nodes , b_nodes = read_msh('mesh/square.msh')

    A = gradu_gradv(topo , x , y)
    f = f_v(topo , x , y)

    clear_rows(A,b_nodes)
    f[b_nodes] = 0

    sol = np.linalg.solve(A,f)

    plot_sol_p1(x,y,sol,topo)
