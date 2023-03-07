#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadrilateral.h"

int main()
    {
        quadrilateral quad;
        quad.node1.x = 0.0; quad.node1.y = 0.0;
        quad.node2.x = -0.5; quad.node2.y = 0.5;
        quad.node3.x = -1.0; quad.node3.y = 2.5;
        quad.node4.x = -2.0; quad.node4.y = 4.5;
        void compute_area(quadrilateral* quadarea);
        compute_area(&quad);
        void eqdis(quadrilateral* quad);
        eqdis(&quad);
        printf("\n quadrilateral node #1: ( %12.5e, %12.5e )",quad.node1.x,quad.node1.y);
        printf("\n quadrilateral node #2: ( %12.5e, %12.5e )",quad.node2.x,quad.node2.y);
        printf("\n quadrilateral node #3: ( %12.5e, %12.5e )",quad.node3.x,quad.node3.y);
        printf("\n quadrilateral node #4: ( %12.5e, %12.5e )",quad.node4.x,quad.node4.y);
        printf("\n area = %12.5e\n\n",quad.area);
        printf("\n area = %12.5e\n\n",quad.perimeter);
    }
