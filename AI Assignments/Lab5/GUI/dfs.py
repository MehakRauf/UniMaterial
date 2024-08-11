def dfs(self, start, goal):
    visited = set() #to keep track of the visited nodes
    stack = [(start, [])] 

    while stack:
        current, path = stack.pop() #poping the node and saving it as current node and path till now.
        if current == goal: #checks if we have reached the goal state
            return path + [current] #if reached then returns the path along with the current node
        if current not in visited: #if gosl state not reached then check if it is not visited
            visited.add(current) #if not visited then add it to the visited set
            for neighbor in self.graph.get(current, {}): #then goes to its edges to check for the path
                if neighbor not in visited: 
                    stack.append((neighbor, path + [current])) #add it in the stack
    return None #if no path is not found then 
