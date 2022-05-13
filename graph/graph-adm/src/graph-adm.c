/* Fri May 13 06:28:51 PM IST 2022 */
/* Author: preetamsad */
/* Title: Graph implementation using adjacency matrix */

#include "graph-adm.h"
#include <stdio.h>
#include <stdlib.h>
#include "adjacency-matrix.h"

/* Returns a new graph pointer */

graph* new_graph(enum type type, int nvertices) 
{
    ad_dmatrix adm_ptr = new_ad_dmatrix(nvertices);

    if (adm_ptr == NULL) {
	/* handle_error(MALLOC_FAIL); */
	return NULL;
    }

    graph *graph_ptr = (graph*) malloc(sizeof(graph));

    if (adm_ptr == NULL) {
	/* handle_error(MALLOC_FAIL); */
	return NULL;
    }

    graph_ptr->nvertices = nvertices;
    graph_ptr->type = type;

    return graph_ptr;
}
