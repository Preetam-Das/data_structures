#include <stdio.h>
#include <stdlib.h>
#include "adjacency-matrix.h"

int main()
{
    ad_dmatrix adm = new_ad_dmatrix(3);
    printf("%d\n", connected_ad_dmatrix(adm, 0, 2)); 
    connect_ad_dmatrix(adm, 0, 1);
    connect_ad_dmatrix(adm, 0, 2);
    connect_ad_dmatrix(adm, 1, 2);
    connect_ad_dmatrix(adm, 2, 0);
    print_ad_dmatrix(adm, 3);
    printf("%d\n", connected_ad_dmatrix(adm, 0, 2)); 
    printf("%d\n", connected_ad_dmatrix(adm, 0, 0)); 
}
