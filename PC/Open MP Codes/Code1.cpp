#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM 5
#define TAG_ROWS 1
#define TAG_MATRIX 2
#define TAG_RESULT 3

int mat_a[NUM][NUM] = {
    {1, 2, 3, 4, 5},
    {4, 6, 1, 3, 0},
    {1, 1, 0, 3, 2},
    {2, 0, 0, 1, 1},
    {4, 3, 6, 5, 1}
};

int mat_b[NUM][NUM] = {
    {3, 2, 6, 0, 1},
    {0, 1, -3, 0, 0},
    {1, 0, 1, 3, 0},
    {5, 3, 7, -3, 2},
    {3, 2, 4, 5, -1}
};

int mat_c[NUM][NUM];  // Final result

void MatrixMultiply(int *row, int mat_b[][NUM], int *dest, int size) {
    for (int j = 0; j < size; j++) {
        dest[j] = 0;
        for (int k = 0; k < size; k++) {
            dest[j] += row[k] * mat_b[k][j];
        }
    }
}

int main(int argc, char *argv[]) {
    int mytid, numprocs;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &mytid);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    if (mytid == 0) {
        // Parent process
        int rows_per_process = NUM / numprocs;
        int extra_rows = NUM % numprocs;
        int offset = 0;

        // Broadcast matrix B to all
        MPI_Bcast(mat_b, NUM * NUM, MPI_INT, 0, MPI_COMM_WORLD);

        for (int dest = 1; dest < numprocs; dest++) {
            int rows_to_send = rows_per_process + (dest < extra_rows ? 1 : 0);
            MPI_Send(&rows_to_send, 1, MPI_INT, dest, TAG_ROWS, MPI_COMM_WORLD);
            MPI_Send(&mat_a[offset][0], rows_to_send * NUM, MPI_INT, dest, TAG_MATRIX, MPI_COMM_WORLD);
            offset += rows_to_send;
        }

        // Parent does its own work
        int parent_rows = rows_per_process + (0 < extra_rows ? 1 : 0);
        for (int i = 0; i < parent_rows; i++) {
            MatrixMultiply(mat_a[i], mat_b, mat_c[i], NUM);
        }

        // Receive from children
        offset = parent_rows;
        for (int source = 1; source < numprocs; source++) {
            int rows_received;
            MPI_Recv(&rows_received, 1, MPI_INT, source, TAG_ROWS, MPI_COMM_WORLD, &status);
            MPI_Recv(&mat_c[offset][0], rows_received * NUM, MPI_INT, source, TAG_RESULT, MPI_COMM_WORLD, &status);
            offset += rows_received;
        }

        // Print final result
        printf("Resultant Matrix C (A x B):\n");
        for (int i = 0; i < NUM; i++) {
            for (int j = 0; j < NUM; j++) {
                printf("%4d ", mat_c[i][j]);
            }
            printf("\n");
        }
    } else {
        // Child process
        int my_rows;
        int work_rows[NUM][NUM];
        int answer_rows[NUM][NUM];

        MPI_Bcast(mat_b, NUM * NUM, MPI_INT, 0, MPI_COMM_WORLD);

        MPI_Recv(&my_rows, 1, MPI_INT, 0, TAG_ROWS, MPI_COMM_WORLD, &status);
        MPI_Recv(&work_rows[0][0], my_rows * NUM, MPI_INT, 0, TAG_MATRIX, MPI_COMM_WORLD, &status);

        for (int i = 0; i < my_rows; i++) {
            MatrixMultiply(work_rows[i], mat_b, answer_rows[i], NUM);
        }

        MPI_Send(&my_rows, 1, MPI_INT, 0, TAG_ROWS, MPI_COMM_WORLD);
        MPI_Send(&answer_rows[0][0], my_rows * NUM, MPI_INT, 0, TAG_RESULT, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
