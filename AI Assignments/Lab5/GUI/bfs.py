def bfs(self, start, goal):
        visited_node = set()  # set to store visited_node 
        queue = [(start, [])]

        while queue:  # Loop until queue is not empty
            node, path = queue.pop(0)  # Pop a node from the queue
            if node == goal:  # Check if current node is the goal node
                return path + [node]  # Return the path to the goal node
            if node not in visited_node:  # Check if current node is not visited
                visited_node.add(node)  
                for neighbor, _ in self.graph.get(node, {}).items():  
                    if neighbor not in visited_node:  # Check if neighbor is not visited
                        queue.append((neighbor, path + [node]))  #the neighbor node along with the updated path is pushed onto the queue

        return None #if no path found