#include <stdio.h>
#include <stdlib.h>
#include "adjacency-matrix.h"

int main()
{
    ad_dmatrix adm = new_ad_dmatrix(8);
    connect_ad_dmatrix(adm, 0, 1);
    connect_ad_dmatrix(adm, 0, 3);
    connect_ad_dmatrix(adm, 0, 7);
    connect_ad_dmatrix(adm, 1, 3);
    connect_ad_dmatrix(adm, 1, 7);
    connect_ad_dmatrix(adm, 3, 5);
    connect_ad_dmatrix(adm, 3, 1);
    print_ad_dmatrix(adm, 16);
}
