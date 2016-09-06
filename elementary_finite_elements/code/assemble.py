from basis_func import *
import numpy as np

def force_term(x_l,y_l):
    return np.ones(x_l.shape)

def gradu_gradv(topo,x,y):
    A = np.zeros((x.shape[0],x.shape[0]))
    for element in topo:
        x_l = x[element]
        y_l = y[element]
        (dx_phi,dy_phi,phi,surf_e) = tri_p1(x_l,y_l,np.zeros((1,2)))
        local_x = np.einsum('i,j->ij', dx_phi, dx_phi)
        local_y = np.einsum('i,j->ij', dy_phi, dy_phi)
        local_matrix = surf_e * (local_x+local_y)

        cols, rows = np.meshgrid(element,element)
        A[rows.flatten(),cols.flatten()] += local_matrix.flatten()

    return A

def f_v(topo,x,y):
    F = np.zeros((x.shape[0],))
    for element in topo:
        x_l = x[element]
        y_l = y[element]
        (dx_phi,dy_phi,phi,surf_e) = tri_p1(x_l,y_l,np.zeros((1,2)))
        f_i = surf_e/3.*force_term(x_l,y_l)
        F[element] += f_i

    return F
