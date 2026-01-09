#include <iostream>
#include <fstream>
#include <cmath>
#include <random>

using namespace std;

int i, j, l;

const double PI = 3.14159265359;
const int N = 100; // Número de osciladores
double K;
const int TMAX = 1000;

int main(){
    ofstream fich; // Open the file for writing

// Antes de nada, damos el valor del número de osciladores que se acoplarán.

fich.open("Data1.txt");

double dthetdt[N], w[N], theta[N];
double media, gamma;
double r;
double sumre, sumim, phi;
double x, y;
const double dt = 0.005;

media=0; gamma=1;


// Generar valores usando la distribución de Lorentz
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis1(-PI, PI); // Rango de valores para x
    cauchy_distribution<> dis(media, gamma);

    normal_distribution<> dis1_bimodal(media - 3, gamma); // Primer pico
    normal_distribution<> dis2_bimodal(media + 3, gamma); // Segundo pico

    for (i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            w[i] = dis1_bimodal(gen);
            //while (abs(w[i])>2*PI/dt) {w[i] = w[i]/2;}
        } else {
            w[i] = dis2_bimodal(gen);
            //while (abs(w[i])>2*PI/dt) {w[i] = w[i]/2;}
        }
    }



//w[i]=tan(PI*(media-0.5));


for(K=7; K<7.1; K=K+10){



for(i=0; i<N; i++){
    x = dis1(gen);
    theta[i]=x;
}





for(l=0; l<TMAX; l++){

for(i=0; i<N; i++){
fich << theta[i] << "\t"; 
}









/*

//MEDIMOS EL COEFICIENTE DE CORRELACIÓN
// Probamos, ya que es de reiterar


//for(j=0;j<N;j++){
sumre = 0;
sumim = 0;
phi = 0;
    for(j=0;j<N;j++){
        sumre = sumre + cos(theta[j]);
        sumim = sumim + sin(theta[j]);
        phi = phi + theta[j];

    }

    phi = phi/N ;

//}

// HAY DOS 1/N QUE SE ELIMINAN ENTRE ELLOS

r = (sumre*cos(phi)+sumim*sin(phi))/N;//sqrt(x/y);     
//fich << r;                    
*/












for (i = 0; i < N; i++) {
    dthetdt[i] = w[i];
}

for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
        dthetdt[i] = dthetdt[i] + K / N * sin(theta[j] - theta[i]);
    }
}


for(i=0; i<N; i++){
    /*if (theta[i]>(0.99*PI)) { w[i]=abs(w[i])*-1;//dthetdt[i]=abs(dthetdt[i])*-1;
    } else if (theta[i]<(-0.99*PI)) {w[i]=abs(w[i]);//dthetdt[i]=abs(dthetdt[i]); 
    } else if (abs(dthetdt[i])<0.1) w[i]=(w[i])*-1;//(((-dthetdt[i])*theta[i]/abs(theta[i])<0) && (abs(dthetdt[i])<0.1)) {w[i]=(w[i])*-1; }
    */


    theta[i]=theta[i]+dthetdt[i]*dt;



    if (theta[i]>(0.99*PI)) { theta[i]=theta[i]-2*PI;//dthetdt[i]=abs(dthetdt[i])*-1;
    } else if (theta[i]<(-0.99*PI)) {theta[i]=theta[i]+2*PI;//dthetdt[i]=abs(dthetdt[i]); 
    }
}

/*for(i=0; i<N; i++){
    fich << dthetdt[i] << "\t"; 
}*/






fich << "\n";




}

fich << "\n";

}

cout << 1;
fich.close();
return 0;
}

