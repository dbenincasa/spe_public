import numpy as np

def tri_p1(x,y,eval_p):
    """
    Linear shape function on triangles, namely p1.

    Input:

    x : one dimensional array of triangle vertices x coords.\n
    y : one dimensional array of triangle vertices y coords.\n
    eval_p: (n,2) array of the n evaluation points. first
            column indicates x-coord, second y-coord.\n

    Output:

    dx_phi : the three x-derivatives.\n
    dy_phi : the three y-derivatives.\n
    phi    : (n,3) array of the three shape funtions ath the n eval points.\n
    surf_e : the triangle area.\n

    Notice: all the quantities are computed on the current element

    """
    # =================================================|
    # given the triangle nodes                         |
    # i write this subroutine to evaluate              |
    # the basis (test) function drivatives and surface |
    # implied in the variational formulation           |
    # =================================================|
    # picewise linear basis function:                  |
    # -------------------------------------------------|
    # psi_j(X) = a_j * x + b_j * y +  c_j              |
    # -------------------------------------------------|x
    # psi_1(X_1) = 1                                   |
    # psi_1(X_2) = 0                                   |
    # psi_1(X_3) = 0                                   |
    #                                                  |
    # similar for nodes 2,3                            |
    #                                                  |
    # a_j = der_psi_x_j                                |
    # b_j = der_psi_y_j                                |
    # j = 1...3                                        |
    # -------------------------------------------------|
    # follows the variables definition:                |
    # -------------------------------------------------|
    # ----------------------------------|
    # these variables mean i'm a coward |
    # ----------------------------------|
    #
    a_j = np.zeros((3,), dtype = 'd')
    b_j = np.zeros((3,), dtype = 'd')
    c_j = np.zeros((3,), dtype = 'd')
    #
    x = np.reshape(x,(3,1))
    y = np.reshape(y,(3,1))
    #
    #
    eval_p = np.reshape(eval_p,(-1,2))
    #
    surf_e = 1./2. * abs(x[0]*y[2]-x[0]*y[1]+x[1]*y[0]-x[1]*y[2]+x[2]*y[1]-x[2]*y[0] )
    #
    A = np.hstack((x,y))
    A = np.hstack((A,np.ones((3,1))))

    for i in range(0,3):
        rhs = np.zeros((3,1), dtype = 'd')
        rhs[i] = 1.
        [a_j[i],b_j[i],c_j[i]] = np.linalg.solve(A, rhs)

    dx_phi = a_j
    dy_phi = b_j
    #
    phi = np.zeros((0,3))
    #
    coeffs = np.vstack([a_j,b_j,c_j])
    eval_p = np.array(eval_p)
    #print eval_p.shape
    #xq = eval_p[:,0]
    #yq = eval_p[:,1]
    nqp = eval_p.shape[0]
    coords = np.hstack([eval_p,
                        np.ones((nqp,1))])
    phi = np.dot(coords,coeffs)
    #
    return dx_phi,dy_phi,phi[0],surf_e
