#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadrilateral.h"


void compute_area(quadrilateral* quadarea )
    {   
        printf("------Iam inside of the area file--------\n\n");
        double u[3],v[3],w[3];
        u[0] = quadarea->node2.x - quadarea->node1.x; //VX1
        u[1] = quadarea->node2.y - quadarea->node1.y; //VY1
        u[2]=0;

        v[0] = quadarea->node3.x - quadarea->node2.x;     //VX2
        v[1] = quadarea->node3.y - quadarea->node2.y;     //VY2
        v[2]=0;
        void cross_prod(double u[], double v[], double w[]);
        cross_prod(u,v,w);
        quadarea->area = fabs(w[2]);
        u[0] = quadarea->node3.x - quadarea->node1.x;     //VX3
        u[1] = quadarea->node3.y - quadarea->node1.y;     //VY3
        
        v[0] = quadarea->node4.x - quadarea->node3.x;     //VX4
        v[1] = quadarea->node4.y - quadarea->node3.y;      //VY4



        void cross_prod(double u[], double v[], double w[]);
        cross_prod(u,v,w);
        // double tri1=0.5*fabs(w[2]);
        quadarea->area += fabs(w[2]);

        
    }void cross_prod(double u[], double v[], double w[])
    {
        w[0] = u[1]*v[2] - u[2]*v[1];
        w[1] = u[2]*v[0] - u[0]*v[2];
        w[2] = u[0]*v[1] - u[1]*v[0];
        //w[3] = u[3]*v[4] - u[4]*v[3];
    }