#include <vector>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;

int busquedaBinaria(vector<int>& v, int x);
int busquedaJumpSearch(vector<int>& v, int x);
int buscar(vector<int> v, int x);
void calcularTiempoDeFuncion();
vector<int> construir_vector(int size, string mode);
int indicePico(vector<int>& v);
int puntoFijo(vector<int> v);
int encontrarRotado(vector<int> v, int x);
int menorMasGrande(vector<int> v, int x);
vector<int> masCercanoK(vector<int> v, int k,  int x);
int busquedaBinariaAscendente(vector<int>& v, int x);
int busquedaBinariaDescendente(vector<int>& v, int x);
int busquedaJumpSearchAscendente(vector<int>& v, int x);
int busquedaJumpSearchDescendente(vector<int>& v, int x);
bool esBorde(vector<int>& v, int indice);
bool esPico(vector<int>& v, int indice);
