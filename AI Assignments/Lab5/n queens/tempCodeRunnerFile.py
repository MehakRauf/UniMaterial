def is_safe(board, row, col, N):
    # Check if there is a queen in the same row
    for i in range(col):
        if board[row][i] == 1:
            return False
    
    # Check upper diagonal
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    # Check lower diagonal
    for i, j in zip(range(row, N), range(col, -1, -1)):
        if board[i][j] == 1:
            return False
    
    return True

def solve_n_queens_until(board, col, n, valid_solutions):
    if col == n:
        valid_solutions.append([row[:] for row in board]) #When a valid placement of queens is found, a copy of the board state is appended to valid_solutions list.
        return
    
    for i in range(n):
        if is_safe(board, i, col, n):
            board[i][col] = 1
            solve_n_queens_until(board, col + 1, n, valid_solutions)
            board[i][col] = 0  # Backtracking

def solve_n_queens(n):
    board = [[0]*n for _ in range(n)]  
    valid_solutions = []
    
    solve_n_queens_until(board, 0, n, valid_solutions)

    return valid_solutions

n = int(input("Enter the number of queens: "))
valid_solutions = solve_n_queens(n)

print(f"Following are the valid_solutions for {n}-queens problem: {len(valid_solutions)}")
index = 1
for solution in valid_solutions:
    print(f"Solution {index}:")
    for row in solution:
        print(row)
    print()
    index += 1