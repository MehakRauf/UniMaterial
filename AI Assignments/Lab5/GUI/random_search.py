import random

def random_search(self, start_node, max_steps):
        current_node = start_node  
        steps = 0  
        path = [current_node]  # Initialize path with start node

        while steps < max_steps and current_node != self.goal_node_entry.get():  # Loop until maximum steps reached or goal node found
            neighbors = list(self.graph.get(current_node, {}).keys())  # Get neighbors of current node
            if not neighbors:  # Check if no neighbors
                break 
            current_node = random.choice(neighbors)  # Choose a random neighbor
            path.append(current_node)  # Add chosen neighbor to path
            steps += 1  

        return path  