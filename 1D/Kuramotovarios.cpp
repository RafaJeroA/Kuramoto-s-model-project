#include <iostream>
#include <fstream>
#include <cmath>
#include <random>

using namespace std;

int i, j, l, q;

const double PI = 3.14159265359;
const double dt = 0.001;
const int N = 100; // Número de osciladores
double K;
const int TMAX = 10000;
double x,y;

int main(){
    ofstream fich[21]; // Open the file for writing

// Antes de nada, damos el valor del número de osciladores que se acoplarán.



fich[1].open("Data1.txt");
fich[2].open("Data2.txt");
fich[3].open("Data3.txt");
fich[4].open("Data4.txt");
fich[5].open("Data5.txt");
fich[6].open("Data6.txt");
fich[7].open("Data7.txt");
fich[8].open("Data8.txt");
fich[9].open("Data9.txt");
fich[10].open("Data10.txt");
fich[11].open("Data11.txt");
fich[12].open("Data12.txt");
fich[13].open("Data13.txt");
fich[14].open("Data14.txt");
fich[15].open("Data15.txt");
fich[16].open("Data16.txt");
fich[17].open("Data17.txt");
fich[18].open("Data18.txt");
fich[19].open("Data19.txt");
fich[20].open("Data20.txt");

double dthetdt[N], w[N], theta[N];
double media, gamma;
double r;
double sumre, sumim, phi;

media=0; gamma=1;


// Generar valores usando la distribución de Lorentz



//w[i]=tan(PI*(media-0.5));

for(q=1; q<21; q++){
for(K=0; K<100.1; K=K+5){

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis1(-PI, PI); // Rango de valores para x
    cauchy_distribution<> dis(media, gamma);

    for (i = 0; i < N; i++) {
        x = dis(gen); // Generar un valor aleatorio para x
        w[i] = x;//1.0 / PI * gamma / ((x - media) * (x - media) + gamma * gamma);
        while (abs(w[i])>0.1*PI/dt) {w[i] = w[i]/2;}
    }



for(i=0; i<N; i++){
    x = dis1(gen);
    theta[i]=x;
}





for(l=0; l<TMAX+1; l++){

//for(i=0; i<N; i++){
//fich[q] << theta[i] << "\t"; 
//}











//MEDIMOS EL COEFICIENTE DE CORRELACIÓN
// Probamos, ya que es de reiterar


for(j=0;j<N;j++){
sumre = 0;
sumim = 0;
phi = 0;
    for(j=0;j<N;j++){
        sumre = sumre + (cos(theta[j]));
        sumim = sumim + (sin(theta[j]));
        phi = phi + (theta[j]);

    }

    phi = phi/N ;

}

// HAY DOS 1/N QUE SE ELIMINAN ENTRE ELLOS

r = abs(((sumre*cos(phi)))+(sumim*sin(phi)))/N;//sqrt(x/y);  
if(l%100==0)   {
fich[q] << r;   }                 













for (i = 0; i < N; i++) {
    dthetdt[i] = w[i];
}

for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
        dthetdt[i] = dthetdt[i] + K / N * sin(theta[j] - theta[i]);
    }
}


for(i=0; i<N; i++){
    
    // Esto es un tipo de modelo que no se suele usar en Kuramoto
    /*if (theta[i]>(0.99*PI)) { w[i]=abs(w[i])*-1;//dthetdt[i]=abs(dthetdt[i])*-1;
    } else if (theta[i]<(-0.99*PI)) {w[i]=abs(w[i]);//dthetdt[i]=abs(dthetdt[i]); 
    } else if (abs(dthetdt[i])<0.1) w[i]=(w[i])*-1;//(((-dthetdt[i])*theta[i]/abs(theta[i])<0) && (abs(dthetdt[i])<0.1)) {w[i]=(w[i])*-1; }
    */
     //(((-dthetdt[i])*theta[i]/abs(theta[i])<0) && (abs(dthetdt[i])<0.1)) {w[i]=(w[i])*-1; }
    

    theta[i]=theta[i]+dthetdt[i]*dt;

    if (theta[i]>(0.99*PI)) { theta[i]=theta[i]-2*PI;//dthetdt[i]=abs(dthetdt[i])*-1;
    } else if (theta[i]<(-0.99*PI)) {theta[i]=theta[i]+2*PI;//dthetdt[i]=abs(dthetdt[i]); 
    }
}

/*for(i=0; i<N; i++){
    fich[q] << dthetdt[i] << "\t"; 
}*/





if(l%100==0)   {
fich[q] << "\n";}




}

fich[q] << "\n";

}



cout << 1;
fich[q].close();
}
return 0;
}

