def print_path(path):
    print(f"Path: {path}")

def maze_game(maze, row, col, visited, path, goal_row, goal_col):
    path.append((row, col))
    visited[row][col] = True

    # Check if goal is reached
    if (row, col) == (goal_row, goal_col):
        print_path(path)
        return

    # Move down
    if row < len(maze) - 1 and not visited[row + 1][col]:
        if maze[row + 1][col] == 0:
            maze_game(maze, row + 1, col, visited.copy(), path.copy(), goal_row, goal_col)

    # Move up
    if row > 0 and not visited[row - 1][col]:
        if maze[row - 1][col] == 0:
            maze_game(maze, row - 1, col, visited.copy(), path.copy(), goal_row, goal_col)

    # Move right
    if col < len(maze[0]) - 1 and not visited[row][col + 1]:
        if maze[row][col + 1] == 0:
            maze_game(maze, row, col + 1, visited.copy(), path.copy(), goal_row, goal_col)

    # Move left
    if col > 0 and not visited[row][col - 1]:
        if maze[row][col - 1] == 0:
            maze_game(maze, row, col - 1, visited.copy(), path.copy(), goal_row, goal_col)

    # Backtrack
    visited[row][col] = False
    path.pop()

def main():
    # 0 means path and 1 means wall/block
    maze = [
        [0, 0, 1, 0, 0],
        [1, 0, 0, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0]
    ]

    visited = [[False] * len(maze[0]) for _ in range(len(maze))]
    path = []

    row = int(input("Enter the starting row: "))
    col = int(input("Enter the starting column: "))
    end_row = int(input("Enter the ending row: "))
    end_col = int(input("Enter the ending column: "))
    maze_game(maze, row, col, visited, path, end_row, end_col)

main()
