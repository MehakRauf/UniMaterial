import queue  # for priority queue implementation

def ucs(self, start, goal):
    visited = set()  # set to keep track of visited nodes
    priority_queue = queue.PriorityQueue()  # Initialize priority queue for UCS
    priority_queue.put((0, start, []))  # Initialize with start node and cost 0

    while not priority_queue.empty():  # Loop until priority queue is empty
        cost, current, path = priority_queue.get()  # Get the lowest cost node 
        if current == goal:  # Check if current node is the goal node
            return path + [(current, cost)]
        if current not in visited:
            visited.add(current)  # Mark current node as visited if not visited
            for neighbor, edge_cost in self.graph.get(current, {}).items():
                if neighbor not in visited:
                    priority_queue.put((cost + edge_cost, neighbor, path + [(current, cost)]))

    return None  # if no path found
