class SudokuSolver:
    def __init__(self, grid):
        self.grid = grid
        # size of the Sudoku puzzle grid
        self.sub_grids = 9

    def printPuzzle(self):
        # iterate over each row
        for i in range(self.sub_grids):
            # iterate over each column in the current row
            for j in range(self.sub_grids):
                # print the value in the current cell 
                print(self.grid[i][j], end=" ")
                # if the current column is a multiple of 3 and not the last column
                if (j + 1) % 3 == 0 and j < self.sub_grids - 1:
                    # to separate subgrids
                    print("|", end=" ")
           # for next line
            print()
            # if the current row is a multiple of 3 and not the last row
            if (i + 1) % 3 == 0 and i < self.sub_grids - 1:
                print("-" * 22)

    def solve(self, row, col, num):
        # if the number already exists in the current row
        for x in range(self.sub_grids):
            if self.grid[row][x] == num:
                # yes then, return False
                return False
        # if the number already exists in the current column
        for x in range(self.sub_grids):
            if self.grid[x][col] == num:
                # yes then, return False
                return False

        # starting row index of the subgrid
        start_row = row - row % 3
        # starting column index of the subgrid
        start_col = col - col % 3

        # if the number already exists in the subgrid
        for i in range(3):
            for j in range(3):
                if self.grid[i + start_row][j + start_col] == num:
                    # yes then, return False
                    return False
        # if the number can be placed, return True
        return True
 
    def solveSudoku(self, row=0, col=0):
        # if the end of grid is reached
        if row == self.sub_grids - 1 and col == self.sub_grids:
            return True
        # end of the row is reached, move to the next row
        if col == self.sub_grids:
            row += 1
            # start of the new row
            col = 0
        # cell is already filled, move to the next cell
        if self.grid[row][col] > 0:
            return self.solveSudoku(row, col + 1)
        # placing numbers from 1 to 9 in the current cell
        for num in range(1, self.sub_grids + 1): 
            if self.solve(row, col, num):
                # If the number can be placed, update the grid 
                self.grid[row][col] = num
                if self.solveSudoku(row, col + 1):
                    return True
            # the number cannot be placed, backtrack by resetting the cell to 0
            self.grid[row][col] = 0
        # no solution exists, return False
        return False

if __name__ == "__main__":
    grid = [
    [5, 3, 0, 0, 7, 0, 0, 0, 0],
    [6, 0, 0, 1, 9, 5, 0, 0, 0],
    [0, 9, 8, 0, 0, 0, 0, 6, 0],
    [8, 0, 0, 0, 6, 0, 0, 0, 3],
    [4, 0, 0, 8, 0, 3, 0, 0, 1],
    [7, 0, 0, 0, 2, 0, 0, 0, 6],
    [0, 6, 0, 0, 0, 0, 2, 8, 0],
    [0, 0, 0, 4, 1, 9, 0, 0, 5],
    [0, 0, 0, 0, 8, 0, 0, 7, 9]
]

    solver = SudokuSolver(grid)
    if solver.solveSudoku():
        solver.printPuzzle()
    else:
        print("Solution does not exist.")
