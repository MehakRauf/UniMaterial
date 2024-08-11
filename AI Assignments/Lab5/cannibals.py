def check_state(state):  # function to check if state is valid
    missionaries, cannibals, boat = state 
    if missionaries < 0 or cannibals < 0 or missionaries > 3 or cannibals > 3:  #valid number of missionaries and cannibals
        return False  
    
    if missionaries > 0 and missionaries < cannibals and boat == 1:  # if more cannibals than missionaries on starting side
        return False  
    
    if missionaries < 3 and missionaries < cannibals and boat == 0:  # if more cannibals than missionaries on opposite side
        return False  
    return True  

def dfs(state, path, visited):  
    if state in visited:  # if state has been visited before, so can't be expanded
        return None  
    if state == (0, 0, 0):  # goal state is reached then return the path 
        return path 
    visited.add(state)  
    
    possible_moves = [(1, 0), (2, 0), (0, 1), (0, 2), (1, 1)]  #the allowed possible moves
    for moves in possible_moves:  # iterate through possible moves
        missionaries, cannibals, boat = state  
        if boat == 1:  # if boat is on starting side
            new_state = (missionaries - moves[0], cannibals - moves[1], 0)  
        else:  # if boat is on opposite side
            new_state = (missionaries + moves[0], cannibals + moves[1], 1)  
        
        if check_state(new_state):  # if new state is valid
            new_path = path + [new_state]  #create a new path
            result = dfs(new_state, new_path, visited)  #for backtracking
            if result is not None:  # if solution is found
                return result  

def dfs_search(): 
    start_state = (3, 3, 1)  # initial state (missionaries, cannibals, boat_location)
    visited = set()  # initialize visited set
    return dfs(start_state, [start_state], visited)  # call depth-first search with initial state

solution = dfs_search() 

if solution:  # if solution is found
    for i in range(len(solution)):  
        state = solution[i]  # get current state
        print(f"Step {i+1}: {state}")  # print each step of the solution
else:  # if no solution 
    print("No solution found.")  # print message indicating no solution found
