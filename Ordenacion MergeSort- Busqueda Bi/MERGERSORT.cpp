#include<iostream>
#include<conio.h>
using namespace std;
int busquedaBinaria(int vector[],int dato, int inferior, int superior){
	int mitad;
	if(inferior>superior){
		return -1;
	}
	else{
		mitad = (inferior+superior)/2;
		if(dato==vector[mitad]){
			return mitad;
		}
		else if(dato>vector[mitad]){
			return busquedaBinaria(vector, dato, mitad+1, superior);
		}else{
			return busquedaBinaria(vector, dato, inferior, mitad-1);
		}
	}
}
void mezcla(int vector[],int izquierdo, int medio, int derecho){
	int* aux;
	int i,k,z;
	aux = new int [derecho-izquierdo+1];
	i = z = izquierdo;
	k = medio + 1;
	while(i<=medio && k<=derecho){
		if(vector[i] <= vector[k]){
			aux[z++] = vector[i++];
		}
		else{
			aux[z++] = vector[k++];
		}
	}
	while(i<=medio){
		aux[z++]=vector[i++];
	}
	while(k<=derecho){
		aux[z++] = vector[k++];
	}
	for(int i= izquierdo; i<=derecho; i++){
		vector[i]= aux[i];
	}
	delete aux;
}
void mergeSort(int vector[],int indPrimero, int indUltimo){
	int indCentral;
	if(indPrimero<indUltimo){
		indCentral = (indPrimero+indUltimo)/2;
		mergeSort(vector, indPrimero, indCentral);
		mergeSort(vector,indCentral+1,indUltimo);
		mezcla(vector,indPrimero,indCentral,indUltimo);
	}
}
int main(){
	int tamanVector,buscar;
	int arreglo[100];
	cout<<"Ingrese el tamaño del Vector: ";
	cin>>tamanVector;
	for(int i=0; i<tamanVector; i++){
		cout<<"Dato ["<<i<<"]: ";
		cin>>arreglo[i];
	}
	
	mergeSort(arreglo, 0,tamanVector-1);
	cout<<"Arreglo ordenado: ";
	for(int i=0; i<tamanVector; i++){
		cout<<arreglo[i]<<" ";
	}
	
	cout<<"\nElemento para buscar: ";
	cin>>buscar;
	
	int retor = busquedaBinaria(arreglo,buscar,0,tamanVector-1);
	if(retor == -1){
		cout<<"No se encontro el numero"<<endl ;
	}else{
		cout<<"Numero '"<<buscar<<"' encontrado en la posicion: "<<retor<<endl;
	}
	cout<<endl;
	getch();
	return 0;
}

