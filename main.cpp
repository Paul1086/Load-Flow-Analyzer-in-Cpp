#include <iostream>
#include <math.h>
#include "ComplexMatrix.h"

using namespace std;

int main()
{
    ComplexMatrix y_matrix[10][10], pq[10], node_Voltage[10], numerator, denominator;
    int n, V_Unknown[10], Num_V_Unknown, PQ_Unknown[10], Num_PQ_Unknown, tmp=0, tmp1=0, tmp2=0;
    double a,b;

    // Elements in y_matrix

    cout << "Number of nodes : ";
    cin >> n;
    cout << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<=i; j++){
            //if (i==j){
            //    continue;
            //}
            //else{
                cout << "Enter admittance between nodes " << i+1 << " and " << j+1 << " :   ";
                cin >> a>>b;
                y_matrix[i][j].set(a,b);
                // cout << "Y" << "[" << i+1 << "][" << j+1  << "]" << " :   " << ybus[i][j].display();
                y_matrix[j][i] = y_matrix[i][j];
            //}
        }
    }


    // Displaying the y_matrix


    cout << endl << endl;
    cout << "The elements of Ybus matrix are :" << endl << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cout << "Y[" << i+1 << "][" << j+1 << "]  = ";
            y_matrix[i][j].display();
            cout << endl;
        }
    }


    //PQ and Voltage values at different nodes


    for (int i=0; i<n; i++){
        cout << "Enter scheduled power at node " << i+1 <<" (put p=1 and q=1 if unknown): " ;
        cin >> a >> b;
        if (a==1 && b==1){
            PQ_Unknown[tmp2++] = i;
            Num_PQ_Unknown = tmp2;
        }
        pq[i].set(a,-b);


        cout << "Enter voltage at node " << i+1 <<" (put p=1 and q=1 if unknown): " ;
        cin >> a >> b;
        if(a==1 && b==1){
            V_Unknown[tmp1++] = i;
            Num_V_Unknown = tmp1;
        }
        node_Voltage[i].set(a,b);
    }



    // Displaying PQ at different nodes


    cout << endl << endl;
    cout << "PQ Values at different nodes :" << endl << endl;
    cout << endl;
    for (int i=0; i<n; i++){
        cout << "PQ at Node " << i+1 << " : ";
        pq[i].display();
        cout << endl;
    }


    // Displaying Voltages at different nodes


    cout << endl << endl;
    cout << "Voltages at different nodes :" << endl << endl;
    cout << endl;
    for (int i=0; i<n; i++){
        cout << "Voltage at Node " << i+1 << " : ";
        node_Voltage[i].display();
        cout << endl;
    }



    cout << endl << endl;
    cout << "Start calculation for 10 iteration : "<< endl << endl;

    for (int i=0; i<10; i++){
        for (int j=0; j<Num_V_Unknown; j++){
            tmp = V_Unknown[j];
            numerator.set(0,0);
            denominator.set(0,0);
            for (int k=0; k<n; k++){
                if (k!=j){
                    numerator = numerator + (y_matrix[k][tmp]*node_Voltage[k]);
                    denominator = denominator + y_matrix[k][tmp];
                }
            }
            numerator = numerator + (pq[tmp]/(node_Voltage[tmp].conjugate()));
            node_Voltage[tmp] = numerator / denominator;
        }
        numerator.set(0,0);
        denominator.set(0,0);
    }


    for (int j=0; j<Num_PQ_Unknown; j++){
        tmp = PQ_Unknown[j];
        for (int k=0; k<n; k++){
            if (k!=j){
                numerator = numerator + (y_matrix[tmp][k]*node_Voltage[k]);
                denominator = denominator + y_matrix[tmp][k];
            }
        }
        pq[tmp]=(node_Voltage[tmp].conjugate ())*(node_Voltage[tmp]*denominator-numerator);
        pq[tmp] = pq[tmp].conjugate();
    }


    cout << "bus \t voltage \t power"<<endl;
    for (int i=0; i<n; i++){
        cout << i+1 << "\t";
        node_Voltage[i].display();
        cout << "\t";
        pq[i].display();
        cout << endl;
    }
    return 0;
}
