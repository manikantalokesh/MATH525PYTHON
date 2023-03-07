#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadrilateral.h"



    void eqdis(quadrilateral* peri)
    {
        printf("-------Iam inside of the perimeter file---------\n\n");
        double X1=sqrt(pow((peri->node2.x-peri->node1.x),2)+pow((peri->node2.y-peri->node1.y),2));
        double X2=sqrt(pow((peri->node3.x-peri->node2.x),2)+pow((peri->node3.y-peri->node2.y),2));
        double X3=sqrt(pow((peri->node4.x-peri->node3.x),2)+pow((peri->node4.y-peri->node3.y),2));
        double X4=sqrt(pow((peri->node1.x-peri->node4.x),2)+pow((peri->node1.y-peri->node4.y),2));

        peri->perimeter=X1+X2+X3+X4;
    }