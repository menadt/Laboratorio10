#include "ejercicios.h"
#include "time.h"
#include <ctime>
#include "stdlib.h"
#include <string>
#include<iostream>
#include <cmath>
#include <fstream>


using namespace std;

int busquedaBinaria(vector<int>& v, int x){
	int res=-1;
    if (v.size()>=1){
        if (v[0]<v[v.size()-1]) {
            res=busquedaBinariaAscendente(v, x);
        }
        else res= busquedaBinariaDescendente(v, x);
    }
    return res;
}

int busquedaBinariaAscendente(vector<int>& v, int x){
    int desde=0;
    int hasta=v.size();
    int medio=desde+(hasta-desde)/2;
    while (desde<=hasta){
        if (v[medio]==x){
            desde=hasta+1;
        }else{
            if (v[medio]<x){
                desde=medio+1;
                medio=desde+(hasta-desde)/2;
            }
            else {
                hasta=medio-1;
                medio=desde+(hasta-desde)/2;
            }
        }
    }
    if (v[medio]==x) return medio;
    else return -1;
}


int busquedaBinariaDescendente(vector<int>& v, int x){
    int desde=0;
    int hasta=v.size();
    int medio=desde+(hasta-desde)/2;
    while (desde<=hasta){
        if (v[medio]==x){
            desde=hasta+1;
        }else{
            if (v[medio]>x){
                desde=medio+1;
                medio=desde+(hasta-desde)/2;
            }
            else {
                hasta=medio-1;
                medio=desde+(hasta-desde)/2;
            }
        }
    }
    if (v[medio]==x) return medio;
    else return -1;
}

int busquedaJumpSearch(vector<int>& v, int x){
    int res=-1;
    if (v.size()>=1) {
        if (v[0]<v[v.size()-1]) res=busquedaJumpSearchAscendente(v,x);
        else res=busquedaJumpSearchDescendente(v,x);
    }
    return res;
}


int busquedaJumpSearchAscendente(vector<int>& v, int x){
    int salto=sqrt(v.size());
    int i=0;
    int anterior=0;
    while (v[i]!=x && i<v.size()){
        if (v[i]<x){
            anterior=i;
            i+=salto;
            if (i>=v.size()) {
                for (int j = anterior+1; j < v.size(); j++) {
                    if (v[j] == x) {
                        i = j;
                    }
                }
            }
        }else
        if (v[i]>x){
            for (int j=anterior;j<i;j++){
                if (v[j]==x){
                    i=j;
                }
            }if (v[i]!=x){
                i=v.size()+1;
            }
        }
    }
    if (v[i]==x) return i;
    else return -1;

}
int busquedaJumpSearchDescendente(vector<int>& v, int x){
    int salto=sqrt(v.size());
    int i=0;
    int anterior=0;
    while (v[i]!=x && i<v.size()){
        if (v[i]>x){
            anterior=i;
            i+=salto;
            if (i>=v.size()) {
                for (int j = anterior+1; j < v.size(); j++) {
                    if (v[j] == x) {
                        i = j;
                    }
                }
            }
        }else
        if (v[i]<x){
            for (int j=anterior;j<i;j++){
                if (v[j]==x){
                    i=j;
                }
            }if (v[i]!=x){
                i=v.size()+1;
            }
        }
    }
    if (v[i]==x) return i;
    else return -1;

}


int buscar(vector<int> v, int x){
    //return busquedaBinaria(v, x);
    return busquedaJumpSearch(v, x);
}


void calcularTiempoDeFuncion() {
    ofstream fout;
    fout.open("datos.csv");
    fout << "n;" <<"tiempo" <<endl;
    for (int i=100; i<=100000; i*=100){
        vector<int> v= construir_vector(i, "asc");
        clock_t begin = clock();
        buscar(v,9999);
        clock_t end = clock();
        double elapsed_msecs = double(end - begin) / CLOCKS_PER_SEC  * 1000; // mide el tiempo en milisegundos
        fout << i <<elapsed_msecs<<endl;
    }
    fout.close();
}

vector<int> construir_vector(int size, string mode){
    vector<int> res {};
    time_t t;
    srand((unsigned) time(&t));
    int base = rand() % 100;
    int step;
    for(int i = 0; i < size; i++){
        step = rand() % 100;
        if(mode == "asc") {
            res.push_back(base+step);
            base += step;
        }
        if(mode == "desc"){
            res.push_back(base-step);
            base -= step;
        }
        if(mode == "azar"){
            res.push_back(step);
        }
        if(mode == "iguales"){
            res.push_back(base);
        }
    }
    return res;
}



int indicePico(vector<int>& v){
    int res=-1;
	if (v.size()==1 || v.size()==2) res=0;
    if (v.size()==3 && esPico(v,1)) res=1;
    else {
        if (v.size() == 3 && v[1] < v[0]) {
            res = 0;
        } else {
            if (v.size() == 3) {
                res = 2;
            } else {
                int i = v.size() / 2;
                if (esPico(v, i)) res = i;
                else {
                    if (i + 1 < v.size() && esPico(v, i + 1)) res = i + 1;
                    else (i - 1 < v.size() && esPico(v, i - 1));
                    res = i - 1;
                }
            }
        }


        return res;
    }}

bool esBorde(vector<int>& v, int indice){
    if (v.size()-1==indice || indice==0) return true;
    else return false;
}

bool esPico(vector<int>& v, int indice){
    if (v[indice]>=v[indice-1] && v[indice]>=v[indice+1]) return true;
    else return false;
}

int puntoFijo(vector<int> v){
	int res=-1;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i]==i){
            res=i;
            i=v.size()+1;
        }
        else if (v[i]>i) i=v.size()+1;
    }
    return res;
}

int encontrarRotado(vector<int> v, int x){
	return -1;
}

int menorMasGrande(vector<int> v, int x){
	return -1;
}

vector<int> masCercanoK(vector<int> v, int k,  int x){
	return {};
}
