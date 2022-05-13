#include "graph-adm.h"
#include <stdio.h>

int main()
{
    graph *g = new_graph(DIRECTED, 3);
    printf("%d\n", g->nvertices);
}

