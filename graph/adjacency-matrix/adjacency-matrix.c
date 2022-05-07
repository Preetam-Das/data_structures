/* Sat May  7 11:26:55 AM IST 2022 */
/* Author: preetamsad */
/* Title: Adjacency Matrix implementation */

#include "adjacency-matrix.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

/* Returns a admatrix pointer initialized with zero */

ad_dmatrix new_ad_dmatrix(int nvertices)
{
   int nchar = ((nvertices*nvertices)/CHAR_BIT) + (nvertices*nvertices % CHAR_BIT != 0);
   ad_dmatrix adm_ptr_temp = calloc(nchar, sizeof(char));
   return adm_ptr_temp;
}

/* connects the two input vertices */

void connect_ad_dmatrix(ad_dmatrix adm_ptr, int frm, int to)
{
    adm_ptr[frm] |= 1 << (CHAR_BIT - to - 1);
}

/* Prints V rows of the Adjacency Matrix */

void print_ad_dmatrix(ad_dmatrix adm_ptr, int V)
{
    for (int i = 0; i < V; i++) {
	for (int j = 0; j < V; j++) {
	    if (adm_ptr[i] & (1 << (CHAR_BIT - j - 1))) fputs("1 ", stdout);
	    else fputs("0 ", stdout);
	}
	fputs("\n", stdout);
    }
}
