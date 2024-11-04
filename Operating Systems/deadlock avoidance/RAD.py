def input_matrix():
    rows = int(input("Enter number of rows: "))
    cols = int(input("Enter number of columns: "))
    matrix = []
    print("Enter the elements row by row:")
    for i in range(rows):
        row = list(map(int, input().split()))
        while len(row) != cols:
            print(f"Please enter exactly {cols} elements.")
            row = list(map(int, input().split()))
        matrix.append(row)
    return matrix

def print_matrix(matrix):
    print("Matrix:")
    for row in matrix:
        print(row)

def check_row(allocation, claim, available, row_index):
    # Ensure the row index is within the bounds
    if row_index >= len(claim) or row_index >= len(allocation):
        print("Row index out of bounds.")
        return False

    # Calculate claim - allocation for the specified row
    claim_minus_allocation = [claim[row_index][j] - allocation[row_index][j] for j in range(len(claim[row_index]))]
    
    # Check if the claim minus allocation is less than or equal to available resources
    for j in range(len(claim_minus_allocation)):
        if claim_minus_allocation[j] > available[j]:
            return False
    return True

# Example usage
Claim_Matrix = input_matrix()
Allocation_Matrix = input_matrix()

# Ensure the Available_Matrix is a single row vector
print("Enter available resources as a single line:")
Available_Matrix = list(map(int, input().split()))  # Single line input for available resources

# Track the execution status of processes
process_executed = [False] * len(Claim_Matrix)

# Keep looping until all processes are executed
while not all(process_executed):
    executed_in_this_round = False

    for i in range(len(Claim_Matrix)):
        if not process_executed[i]:  # Only check processes that haven't run yet
            is_valid = check_row(Allocation_Matrix, Claim_Matrix, Available_Matrix, i)

            if is_valid:
                print(f"Process P{i + 1} can be executed.")
                print(f"Previous Available Matrix: {Available_Matrix}")  # Display current available resources
                
                # Update the Available_Matrix by adding the allocated resources back
                for j in range(len(Available_Matrix)):
                    Available_Matrix[j] += Allocation_Matrix[i][j]  # Add the current allocation to available
                
                print(f"Updated Available Matrix: {Available_Matrix}")  # Display updated available resources
                
                # Mark the process as executed
                process_executed[i] = True
                executed_in_this_round = True
            else:
                print(f"Process P{i + 1} cannot be executed due to insufficient resources.")

    if not executed_in_this_round:
        print("Deadlock detected. No processes can be executed.")
        break  # Break the loop if no process was executed in this round
else:
    print("All processes have been executed successfully.")
