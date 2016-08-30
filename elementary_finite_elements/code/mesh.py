import numpy as np

def read_msh(filename):
    f = open ( filename , 'r')
    x = np.array([])
    y = np.array([])
    topo = np.array([], dtype=np.int_)
    nodes = np.array([], dtype=np.int_)
    b_nodes = np.array([], dtype=np.int_)
    int_nodes = np.array([], dtype=np.int_)

    for line in f:
        if line[0]=='$':
            print 'non fare un cippa'
        else:
            l = map(float,line.split())
            if len(l) == 4:
                x = np.append(x,l[1])
                y = np.append(y,l[2])
                nodes = np.append(nodes,int(l[0])-1)
                #print 'ciao'
            if len(l) == 7:
                nod = l[5:7]
                for i in nod:
                    i= int(i-1)
                    if i not in b_nodes:
                        b_nodes = np.append( b_nodes , i )
            if len(l) == 8:
                row = l[5:8]
                row = np.array(row, dtype=int)
                topo = np.append(topo,row)

    f.close()

    topo = np.reshape(topo,(len(topo)/3,3))
    topo = topo-1
    r_id = 0
    for row in topo:
        ck =      (x[row[1]]-x[row[0]])*(y[row[2]]-y[row[0]])
        ck = ck - (x[row[2]]-x[row[0]])*(y[row[1]]-y[row[0]])
        if ck < 0:
            topo[r_id,:] = np.array([[row[0],row[2],row[1]]])
        r_id+=1

    print r_id
    return topo , x , y , nodes , b_nodes
