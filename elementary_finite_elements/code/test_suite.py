import unittest
from mesh import *
import numpy as np


class MeshTest(unittest.TestCase):
    def test_read_msh(self):
        expected = np.array([ 65,129,85],dtype=np.int_)
        topo , x , y , nodes , b_nodes = read_msh('mesh/square.msh')
        result = topo[10,:]
        self.assertItemsEqual(result, expected)
        # assertCountEqual for python 3


if __name__ == "__main__":
    unittest.main()
