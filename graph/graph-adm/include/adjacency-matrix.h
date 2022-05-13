/* Sat May  7 11:05:01 AM IST 2022 */
/* Author: preetamsad */
/* Title: Adjacency-Matrix Representation */

#include <stdbool.h>

#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

/* Adjacency matrix is a square nxn matrix n being the */ 
/* number of vertices. For a undirected graph an element Aij */
/* is one when there is an edge from i to j otherwise 0. */

/* Directed graph */

/* Representing Adjacency matrix as an array of chars. One */ 
/* char is 8 bit, so a graph with V vertices will take */ 
/* ceil(|V|**2/8) bytes in memory. I chose char because it */ 
/* is the most basic c data type in any architecutre (maybe??) */

typedef unsigned char* ad_dmatrix;

/* Functions */

ad_dmatrix new_ad_dmatrix(int nvertices);
void connect_ad_dmatrix(ad_dmatrix adm_ptr, int from, int to);
void print_ad_dmatrix(ad_dmatrix adm_ptr, int V);
bool connected_ad_dmatrix(ad_dmatrix adm_ptr, int from, int to);

#endif
