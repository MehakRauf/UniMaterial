def dfs_mincost(self, start, goal):
    visited = set()  # set to keep track of visited nodes
    stack = [(start, 0, [])]  # Initialize stack for DFS

    while stack:  # Loop until stack is empty
        current, cost, path = stack.pop()  # Pop a node from the stack
        if current == goal:  # Check if current node is the goal node
            return path + [(current, cost)]
        if current not in visited:
            visited.add(current)  # Mark current node as visited if not visited
            for neighbor, edge_cost in self.graph.get(current, {}).items():
                if neighbor not in visited:
                    stack.append((neighbor, cost + edge_cost, path + [(current, cost)]))

    return None
