#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
    double L=1; 
    double t = 0.0;
    double t_max=2.0;
    double delta_x=0.01;
    double delta_t=0.01;
    int n_sidex=L/(delta_x)+1;
    int nu_t=t_max/(delta_t)+1;
    double e=1.0;
    double Beta = 1.0;
    double u[2][n_sidex];
    ofstream outfile;
    
    
    for(int i=0;i<n_sidex;i++){
        u[0][i]=sin(4*M_PI*i*delta_x)/20.0;
    }

    outfile.open("ejemplo.dat");
    for (int j=0; j<nu_t; j++){
        for(int i=1; i<n_sidex-1; i++){
            u[1][i]=u[0][i]- (Beta/4)*(pow(u[0][i+1],2)-pow(u[0][i-1],2)) +(pow(Beta,2)/8)*( (u[0][i+1]+u[0][i])*(pow(u[0][i+1],2)-pow(u[0][i],2)) -(u[0][i]+u[0][i-1])*(pow(u[0][i],2)-pow(u[0][i-1],2)));
        }

        for(int i=0;i<n_sidex;i++){
        outfile << u[0][i] << " ";
        }
        outfile << "\n";

        for(int i=1;i<n_sidex-1;i++){
            u[0][i]=u[1][i];
        }
        
    }
    outfile.close();
    return 0;
}

