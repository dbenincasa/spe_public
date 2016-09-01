import unittest
from mesh import *
from basis_func import *
import numpy as np

class BasisFuncsTest(unittest.TestCase):
    def test_basis_func_00(self):
        x = np.array([0.,1.,0.])
        y = np.array([0.,0.,1.])
        dx_phi,dy_phi,phi,surf_e = tri_p1(x,y,np.array([.1,.2]))
        self.assertEqual(surf_e,.5)
        self.assertItemsEqual(dx_phi, [-1., 1., 0.])
        self.assertItemsEqual(dy_phi, [-1., 0., 1.])
        self.assertItemsEqual(phi, [ 0.7, 0.1, 0.2])
    def test_basis_func_01(self):
        x = np.array([1.,1.,0.])
        y = np.array([0.,1.,1.])
        dx_phi,dy_phi,phi,surf_e = tri_p1(x,y,np.array([.9,.8]))
        self.assertEqual(surf_e,.5)
        self.assertItemsEqual(dx_phi, [0.,1.,-1.])
        self.assertItemsEqual(dy_phi, [-1.,1.,0.])
        self.assertItemsEqual(phi, [ 0.2,0.7,0.1])


class MeshTest(unittest.TestCase):
    def test_read_msh(self):
        expected = np.array([ 65,129,85],dtype=np.int_)
        topo , x , y , nodes , b_nodes = read_msh('mesh/square.msh')
        result = topo[10,:]
        self.assertItemsEqual(result, expected)
        # assertCountEqual for python 3

"""class MeshTest(unittest.TestCase):
    def test_read_msh(self):
        expected = np.array([ 65,129,85],dtype=np.int_)
        topo , x , y , nodes , b_nodes = read_msh('mesh/square.msh')
        result = topo[10,:]
        self.assertItemsEqual(result, expected)
        # assertCountEqual for python 3"""


if __name__ == "__main__":
    unittest.main()
