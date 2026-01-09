#include <iostream>
#include <fstream>
#include <cmath>
#include <random>

using namespace std;

int i, j, l;

const double PI = 3.14159265359;
const int N = 10; // Número de osciladores
const double K=0.1;
const int TMAX = 10000;

int main(){
    ofstream fich; // Open the file for writing

// Antes de nada, damos el valor del número de osciladores que se acoplarán.

fich.open("Data.txt");

double dthetdt[N], w[N], theta[N];
double media, gamma;

media=0; gamma=1;


// Generar valores usando la distribución de Lorentz
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis1(-PI, PI); // Rango de valores para x
    cauchy_distribution<> dis(media, gamma);

    for (i = 0; i < N; ++i) {
        double x = dis(gen); // Generar un valor aleatorio para x
        w[i] = x;//1.0 / PI * gamma / ((x - media) * (x - media) + gamma * gamma);
        while (abs(w[i])>PI) {w[i] = w[i]/10;}
    }



for(i=0; i<N; i++){
    double x = dis1(gen);
    theta[i]=x;
}
//w[i]=tan(PI*(media-0.5));

for(l=0; l<TMAX; l++){

for(i=0; i<N; i++){
    dthetdt[i] = 0;
}


for(i=0; i<N; i++){
    for(j=0; j<N; j++){   
    dthetdt[i]=dthetdt[i]+w[i]+K/N*sin(theta[j]-theta[i]);
    }
}

for(i=0; i<N; i++){
    theta[i]=theta[i]+dthetdt[i]*0.01;
    if (theta[i]>(0.99*PI)) w[i]=abs(w[i])*-1;
    if (theta[i]<(-0.99*PI)) w[i]=abs(w[i]);
    fich << theta[i] << "\t"; 
}

/*for(i=0; i<N; i++){
    fich << dthetdt[i] << "\t"; 
}*/





//MEDIMOS EL COEFICIENTE DE CORRELACIÓN
// Probamos, ya que es de reiterar
/*double r;
double sumre, sumim, phi;

for(j=0;j<N;j++){
sumre = 0;
sumim = 0;
phi = 0;
    for(i=0;i<N;i++){
        sumre = sumre + cos(theta[j]);
        sumim = sumim + sin(theta[j]);
        phi = phi + theta[j];

    }

    phi = 1.0/N*phi ;

}

// HAY DOS 1/N QUE SE ELIMINAN ENTRE ELLOS

double x,y;
x = (sumre*sumre+sumim*sumim);
y = (sin(phi)*sin(phi)+cos(phi)*cos(phi));

r = 1.0/N*sqrt(x/y);
fich << r;*/

fich << "\n";




}

cout << 1;
fich.close();
return 0;
}

