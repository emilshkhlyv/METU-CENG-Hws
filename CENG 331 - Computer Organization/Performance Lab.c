/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
/* 
 * Please fill in the following student struct 
 */
team_t team = {
    "2280386",              /* Student ID */
    "Emil Shikhaliyev",     /* full name */
    "emil.shikhaliyev@metu.edu.tr",  /* email address */
    "",                   /* leave blank */
    ""                    /* leave blank */
};


/***************
 * Sobel KERNEL
 ***************/

/******************************************************
 * Your different versions of the sobel functions  go here
 ******************************************************/

/* 
 * naive_sobel - The naive baseline version of Sobel 
 */
char naive_sobel_descr[] = "sobel: Naive baseline implementation";
void naive_sobel(int dim,int *src, int *dst) {
    int i,j,k,l;
    int ker[3][3] = {{-1, 0, 1}, 
                     {-2, 0, 2}, 
                     {-1, 0, 1}};  

    for(i = 0; i < dim; i++)
        for(j = 0; j < dim; j++) 
        {	
	        dst[j*dim+i]=0;
            if(!((i == 0) || (i == dim-1) || (j == 0) || (j == dim-1)))
            {
                for(k = -1; k <= 1; k++)
                {
                    for(l = -1; l <= 1; l++) 
                    {
                        dst[j*dim+i]=dst[j*dim+i]+src[(j + l)*dim+(i + k)] * ker[(l+1)][(k+1)]; 
                    }  
                }
            }
        }
}

/* 
 * sobel - Your current working version of sobel
 * IMPORTANT: This is the version you will be graded on
 */

char sobelv2v[] = "sobelv2";
void sobelv2(int dim,int *src, int *dst)
{
    int i = 0;
    int j = 0;

    int k0 = -1 ; int k1 = 0 ; int k2 = 1 ;
    int k3 = -2 ; int k4 = 0 ; int k5 = 2 ;
    int k6 = -1 ; int k7 = 0 ; int k8 = 1 ;


    for(; i < dim; j+=dim){
        dst[i] = 0;
        dst[j] = 0;
        ++i;
    }

    i = j-1;
    j -= (dim+1);

    for(; j > 0; j-= dim){
        dst[j] = 0;
        dst[i] = 0;
        --i; 
    }

    int *si;
    int *sij;
    int *dj;
    int r = dim -2;
    int *srced;
    srced = src;
    int adr, adl;
    for(i = r; i > 2; i -= 3)
    {
        //1st
        si = srced;
        dj = (dst+dim)+1; 
        for(j = r; j > 14; j-=15)
        {
            //1st
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);
            
            //2nd
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //3rd
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //4th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //5th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //6th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //7th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //8th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //9th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);
            
            //10th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //11th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //12th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //13th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //14th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //15th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);
        }
        switch(j)
        {
            case 14:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 13:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 12:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[151]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 11:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);        
            case 10:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 9:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);            
            case 8:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 7:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 6:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 5:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 4:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 3:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 2:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 1:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
                    break;
        }
        dst += dim;
        srced += dim;

        //2nd
        si = srced;
        dj = (dst+dim)+1; 
        for(j = r; j > 14; j-=15)
        {
            //1st
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);
            
            //2nd
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //3rd
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //4th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //5th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //6th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //7th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //8th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //9th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);
            
            //10th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //11th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //12th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //13th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //14th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //15th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);
        }
        switch(j)
        {
            case 14:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 13:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 12:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[151]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 11:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);        
            case 10:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 9:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);            
            case 8:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 7:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 6:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 5:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 4:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 3:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 2:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 1:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
                    break;
        }
        dst += dim;
        srced += dim;     

        //3rd
        si = srced;
        dj = (dst+dim)+1; 
        for(j = r; j > 14; j-=15)
        {
            //1st
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);
            
            //2nd
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //3rd
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //4th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //5th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //6th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //7th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //8th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //9th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);
            
            //10th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //11th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //12th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //13th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //14th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);

            //15th
            sij = si;

            adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
            adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
            adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
            
            ++si;
            *dj++ = (adr + adl);
        }
        switch(j)
        {
            case 14:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 13:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 12:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[151]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 11:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);        
            case 10:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 9:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);            
            case 8:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 7:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 6:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 5:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 4:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 3:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 2:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
            case 1:
                    sij = si;

                    adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                    sij += dim;
                    adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                    sij += dim;
                    adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                    
                    ++si;
                    *dj++ = (adr + adl);
                    break;
        }
        dst += dim;
        srced += dim;  
    }   
    switch(i)
    {
        case 2:
            si = srced;
            dj = (dst+dim)+1; 
            for(j = r; j > 14; j-=15)
            {
                //1st
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);
                
                //2nd
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //3rd
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //4th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //5th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //6th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //7th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //8th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //9th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);
                
                //10th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //11th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //12th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //13th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //14th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //15th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);
            }
            switch(j)
            {
                case 14:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 13:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 12:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[151]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 11:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);        
                case 10:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 9:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);            
                case 8:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 7:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 6:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 5:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 4:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 3:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 2:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 1:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                        break;
            }
            dst += dim;
            srced += dim;
        case 1:
            si = srced;
            dj = (dst+dim)+1; 
            for(j = r; j > 14; j-=15)
            {
                //1st
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);
                
                //2nd
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //3rd
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //4th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //5th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //6th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //7th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //8th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //9th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);
                
                //10th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //11th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //12th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //13th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //14th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);

                //15th
                sij = si;

                adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;   sij += dim;
                adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;   sij += dim;
                adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                
                ++si;
                *dj++ = (adr + adl);
            }
            switch(j)
            {
                case 14:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 13:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 12:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[151]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 11:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);        
                case 10:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 9:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);            
                case 8:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 7:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 6:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 5:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 4:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 3:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 2:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                case 1:
                        sij = si;

                        adr = sij[0]*k0;    adl = sij[1]*k1;    adr += sij[2]*k2;
                        sij += dim;
                        adl += sij[0]*k3;   adr += sij[1]*k4;   adl += sij[2]*k5;
                        sij += dim;
                        adr += sij[0]*k6;   adl += sij[1]*k7;   adr += sij[2]*k8;
                        
                        ++si;
                        *dj++ = (adr + adl);
                        break;
            }
            dst += dim;
            srced += dim;
    } 
}



char sobel_descr[] = "Dot product: Current working version";
void sobel(int dim,int *src,int *dst) 
{
    sobelv2(dim,src,dst);
}

/*********************************************************************
 * register_sobel_functions - Register all of your different versions
 *     of the sobel functions  with the driver by calling the
 *     add_sobel_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_sobel_functions() {
    add_sobel_function(&naive_sobel, naive_sobel_descr);   
    add_sobel_function(&sobel, sobel_descr);   
    /* ... Register additional test functions here */
}




/***************
 * MIRROR KERNEL
 ***************/

/******************************************************
 * Your different versions of the mirror func  go here
 ******************************************************/

/* 
 * naive_mirror - The naive baseline version of mirror 
 */
char naive_mirror_descr[] = "Naive_mirror: Naive baseline implementation";
void naive_mirror(int dim,int *src,int *dst) {
    
 	int i,j;

	for(j = 0; j < dim; j++)
		for(i = 0; i < dim; i++) {
			dst[RIDX(j,i,dim)]=src[RIDX(j,dim-1-i,dim)];
		}

}
/*
char mirrorv1v[] = "mirrorv1";
void mirrorv1(int dim,int *src,int *dst)
{
	int i = dim, j, *si, *dj;	
	si = src;
	for(; i--; src+=dim, dst+=dim, si = src)
	{
		dj = (dst+dim)-1;
		for(j= dim; j > 3; j-=4)
		{
			*dj-- = *(si++);
			*dj-- = *(si++);
			*dj-- = *(si++);
			*dj-- = *(si++);
		}		
		switch(j)
		{
			case 3:	*dj-- = *(si++);
			case 2:	*dj-- = *(si++);
			case 1:	*dj-- = *(si++); 
			case 0:	 break;
		}
	}
}*/

/* 
 * mirror - Your current working version of mirror
 * IMPORTANT: This is the version you will be graded on
 */
char mirror_descr[] = "Mirror: Current working version";
void mirror(int dim,int *src,int *dst) 
{
      int i = dim, j, *si, *dj, *srced;	

	srced = src;
	si = srced;
	for(; i--; srced+=dim, dst+=dim, si = srced)
	{
		dj = (dst+dim)-1;
		for(j= dim; j > 3; j-=4)
		{
			*dj-- = *(si++);
			*dj-- = *(si++);
			*dj-- = *(si++);
			*dj-- = *(si++);
		}		
		switch(j)
		{
			case 3:	*dj-- = *(si++);
			case 2:	*dj-- = *(si++);
			case 1:	*dj-- = *(si++); 
			case 0:	 break;
		}
	}
}

/*********************************************************************
 * register_mirror_functions - Register all of your different versions
 *     of the mirror functions  with the driver by calling the
 *     add_mirror_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_mirror_functions() {
    add_mirror_function(&naive_mirror, naive_mirror_descr);   
    add_mirror_function(&mirror, mirror_descr);   
    /* ... Register additional test functions here */
}

