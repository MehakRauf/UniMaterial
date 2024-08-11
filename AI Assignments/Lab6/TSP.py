import itertools  #for permutation generation

# Define the weighted graph
graph=[
    [0,10,15,20],
    [10,0,35,25],
    [15,35,0,30],
    [20,25,30,0]
]

# to calculate the cost of a given path in the graph
def cost_calculator(path):
    cost = 0  
    # Iterate through the path
    for i in range(len(path)-1):
        cost += graph[path[i]][path[i+1]]
    # Add the cost of returning to the starting point from the last vertex
    cost += graph[path[-1]][0]
    return cost  # Return cost

# find the minimum Hamiltonian cycle and its cost in the graph
def ham_cycle(graph):
    n = len(graph)  # number of vertices in the graph
    min_weight = float('inf')  # minimum cost to positive infinity
    min_cycle = None  # minimum path to None
    # Generate permutations of vertex indices, excluding the starting vertex

    for perm in itertools.permutations(range(1, n)):
        #Hamiltonian cycle by prepending the starting vertex (0) to each permutation
        cycle = [0] + list(perm)
        # Calculate the cost of the Hamiltonian cycle
        cost = cost_calculator(cycle)
        # Check if the current cost is less than the minimum cost found so far
        if cost < min_weight:
            # Update the minimum cost
            min_weight = cost
            # Update the minimum cycle
            min_cycle = cycle
    return min_cycle, min_weight  # Return the minimum Hamiltonian cycle and its cost

min_cycle, min_weight = ham_cycle(graph)
# print("minimum Hamiltonian Cycle : ", min_cycle)
print("minimum weight Hamiltonian Cycle : ", min_weight)
