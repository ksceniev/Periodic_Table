#include <stdio.h>
#include <stdlib.h>

int iget_closest(int v[], int n, int t){
    int i, lw, hh;
    lw = v[0], hh = v[n-1];
    for(i = 0; i < n; i++){
        if(v[i] < lw) lw = v[i];
        if(v[i] > hh) hh = v[i];
    }
    
    if(t <= lw) return lw;
    if(t >= hh) return hh;

    int bgst_d = abs(t-hh), num = v[0];
    if(t > lw && t < hh){
        for(i = 0; i < n; i++){

            if(abs(t-v[i]) <= bgst_d){
                num = v[i];
                bgst_d = abs(t-v[i]);
            }
        }

        return num;
    }
}

float fget_closest(float v[], int n, float t){
    float lw, hh;
    int i;
    
    lw = v[0], hh = v[n-1];
    for(i = 0; i < n; i++){
        if(v[i] < lw) lw = v[i];
        if(v[i] > hh) hh = v[i];
    }
    
    if(t <= lw) return lw;
    if(t >= hh) return hh;

    float bgst_d = abs(t-hh), num = v[0];
    if(t > lw && t < hh){
        for(i = 0; i < n; i++){

            if(abs(t-v[i]) <= bgst_d){
                num = v[i];
                bgst_d = abs(t-v[i]);
            }
        }

        return num;
    }
}
