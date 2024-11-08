#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

typedef struct {
    int nodes;
    int edges;
    double avg_clustering;
    int triangles;
    int diameter;
} GraphMetrics;

GraphMetrics metrics = {0};

void process_graph(int rank) {
    metrics.nodes += rank * 100; // Simulação de trabalho
}

int main(int argc, char *argv[]) {
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0 && argc < 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    char *input_file = argv[1];

    process_graph(rank);

    if (rank == 0) {
        printf("{ \"graph_metrics\": { \"nodes\": %d, \"edges\": %d, \"average_clustering_coefficient\": %.4f, \"triangles\": %d, \"diameter\": %d } }\n",
               metrics.nodes, metrics.edges, metrics.avg_clustering, metrics.triangles, metrics.diameter);
    }

    MPI_Finalize();
    return 0;
}

