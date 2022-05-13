/* Fri May 13 06:18:05 PM IST 2022 */
/* Author: preetamsad */
/* Title: Graph Representation using Adjacent Matrix */

#include "../include/adjacency-matrix.h"

#ifndef GRAPH_ADM_H
#define GRAPH_ADM_H

enum type {DIRECTED, UNDIRECTED};

/* Graph structure. According to wikipedia "Data on edges and vertices must be stored externally. Only the cost for one edge can be stored between each pair of vertices." So I implemented adjacency matrix as its own structure */

struct adm_graph {
   enum type type;
   ad_dmatrix adm;
   int nvertices;
};

typedef struct adm_graph graph;

/* Fucntions */
graph* new_graph(enum type type, int nvertices);

#endif
