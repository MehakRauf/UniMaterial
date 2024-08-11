import random

def random_search_openclosed(self, start_node):
    open_list = [start_node] #initialize the open list
    closed_list = [] #initialize the closed list

    while open_list: #loop until we reach the maximum steps or the open list is empty
        current_node = random.choice(open_list) #choose a random node
        closed_list.append(current_node) #append it to the closed list
        open_list.remove(current_node) #remove it from the open list as it is visited

        if current_node == self.goal_node_entry.get(): #check if we have reached the goal node
            return closed_list #return the path

        neighbors = list(self.graph.get(current_node, {}).keys())
        for neighbor in neighbors:
            if neighbor not in closed_list and neighbor not in open_list: 
                open_list.append(neighbor)

    return closed_list