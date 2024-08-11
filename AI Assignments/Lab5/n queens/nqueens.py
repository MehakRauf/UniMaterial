def is_safe(board, row, col, N):
    # Check if there is a queen in the same row
    for i in range(col):
        #same row but different column
        if board[row][i] == 1:
            return False
    
    # Check upper diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    # Check lower diagonal
    for i, j in zip(range(row, N), range(col, -1, -1)):
        #if queen is already placed
        if board[i][j] == 1:
            return False
    #if it is safe to place a queen
    return True

def solve_n_queens_until(board, col, n, valid_solutions):
    if col == n:
        valid_solutions.append([row[:] for row in board]) #When a valid placement of queens is found, a copy of the board state is appended to valid_solutions list.
        return
    #iterate over each row
    for i in range(n):
        #check if it is safe, if yes then place
        if is_safe(board, i, col, n):
            board[i][col] = 1
            #recursively call the function to place the queens
            solve_n_queens_until(board, col + 1, n, valid_solutions)
            board[i][col] = 0  # Backtracking to find other possibilities

def solve_n_queens(n):
    #board of size n*n
    board = [[0]*n for _ in range(n)]  
    #to keep track of the valid solutions for printing
    valid_solutions = []
    
    solve_n_queens_until(board, 0, n, valid_solutions)

    return valid_solutions

n = int(input("Enter the number of queens: "))
valid_solutions = solve_n_queens(n)

if (valid_solutions):
    print(f"The number of valid_solutions for {n}-queens problem is: {len(valid_solutions)}")
    index = 1
    for solution in valid_solutions:
        print(f"Solution {index}:")
        for row in solution:
            print(row)
        print()
        index += 1
else:
    print("No solutions")