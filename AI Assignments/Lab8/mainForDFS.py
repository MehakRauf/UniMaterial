from eightPuzzleProblem import EightPuzzleProblem
from depthFirstSearch import DepthFirstSearchStrategy
from modifySearch import Search

#initial state
initial_state = [[1, 3, 4], [8, 6, 2], [7, 0, 5]]
#goal state
goal_state = [[1, 2, 3], [8, 0, 4], [7, 6, 5]]

#instance of the 8-puzzle problem
eight_puzzle_problem = EightPuzzleProblem(initial_state, goal_state)

#instance of the Depth-First Search strategy
dfs_strategy = DepthFirstSearchStrategy()

#search object
dfs_search = Search(eight_puzzle_problem, dfs_strategy)
# Solve the problem 
dfs_result = dfs_search.solveProblem()
if dfs_result is not None:
    print("\nDepth First Search Result:")
    dfs_search.printResult(dfs_result)
else:
    print("Depth First Search: No solution found.")

expanded_nodes = dfs_search.getExpandedNodes()
print("The number of expanded nodes:", expanded_nodes)