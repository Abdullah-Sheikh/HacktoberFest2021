
# A star Algorithm function ------------------------------------------!!

def A_Star_Algo(StartNode, EndNode):

    open_set = set(StartNode)
    closed_set = set()
    distance = {}  # store distance from starting node
    parents = {}  # Adjacency map of all nodes

    distance [StartNode] = 0 # ditance of starting node from itself is zero
    parents[StartNode] = StartNode

    while len(open_set) > 0:
        n = None
        for v in open_set:
            if n == None or distance [v] + heuristic(v) < distance [n] + heuristic(n):
                n = v
        if n == EndNode or Graph_nodes[n] == None:
            pass
        else:
            for (m, weight) in get_neighbors(n):

                if m not in open_set and m not in closed_set:
                    open_set.add(m)
                    parents[m] = n
                    distance [m] = distance [n] + weight

                # for each node m,compare its distance from start i.e g(m) to the
                # from start through n node
                else:
                    if distance [m] > distance [n] + weight:
                        # update g(m)
                        distance [m] = distance [n] + weight
                        # change parent of m to n
                        parents[m] = n

                        # if m in closed set,remove and add to open
                        if m in closed_set:
                            closed_set.remove(m)
                            open_set.add(m)

        if n == None:
            print('Path does not exist!')
            return None
        # if the current node is the stop_node
        # then we begin reconstructin the path from it to the start_node
        if n == EndNode:
            path = []

            while parents[n] != n:
                path.append(n)
                n = parents[n]

            path.append(StartNode)

            path.reverse()

            print('Path found:......... !\n\n\t\t\t {}'.format(path))
            return path
        # remove n from the open_list, and add it to closed_list
        # because all of his neighbors were inspected
        open_set.remove(n)
        closed_set.add(n)

    print('Path does not exist!')
    return None


# this function will return neighbor and its distance ------------------------------------------!!
def get_neighbors(v):
    if v in Graph_nodes:
        return Graph_nodes[v]
    else:
        return None

# this function returns heuristic distance for all nodes ------------------------------------------!!
def heuristic(n):
    H_dist = {
        'A': 40,
        'B': 32,
        'C': 25,
        'D': 35,
        'E': 19,
        'F':17,
        'H':10,
        'G': 0,

    }

    return H_dist[n]

# Define graph  ------------------------------------------!!
Graph_nodes = {
    'A': [('B', 1), ('D', 7) , ('C',1)],
    'B': [('E', 1)],
    'C': [('E', 8), ('F', 1) ],
    'E': [('H', 9)],
    'D': [ ('F',2)],
    'F':[('G',2)],
    'H':[('G',1)]

}


# Main program run :

print('\n##---------------------------------------------------------##\n')
print('\t\t\t\tA* Star Algorithm\n\n')


# call the main function ------------------------------------------!!
A_Star_Algo('A', 'G')
