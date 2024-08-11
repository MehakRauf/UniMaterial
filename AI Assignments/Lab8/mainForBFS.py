# Import necessary classes
from eightPuzzleProblem import EightPuzzleProblem
from breadthFirstSearch import BreadthFirstSearchStrategy
from modifySearch import Search
#initial state
initial_state = [[1, 3, 4],[8, 6, 2],[7, 0, 5]]
#goal state
goal_state = [[1, 2, 3],[8, 0, 4], [7, 6, 5]]

#instance of the 8-puzzle problem
eight_puzzle_problem = EightPuzzleProblem(initial_state, goal_state)

#instance of the breadth-first search strategy
breadth_first_search_strategy = BreadthFirstSearchStrategy()

#search object
search = Search(eight_puzzle_problem, breadth_first_search_strategy)

# Solve the problem
result = search.solveProblem()

#result printing
search.printResult(result)

# Get the number of expanded nodes
expanded_nodes = search.getExpandedNodes()
print("The number of expanded nodes:", expanded_nodes)
