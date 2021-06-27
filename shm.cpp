#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{

//******
//removes csv file from previous execution of this program
//******
    remove("shm.csv"); 

//******
//defining initial values for execution
//******
    double k, m, x0, v0, deltat, g, n;

    std::cout << "Introduce spring constant (N/m): ";
    std::cin >> k;
    std::cout << "Introduce mass (kg): ";
    std::cin >> m;
    std::cout << "Introduce initial position (m): ";
    std::cin >> x0;
    std::cout << "Introduce initial velocity (m/s): ";
    std::cin >> v0;
    std::cout << "Introduce time interval between calculated values (s): ";
    std::cin >> deltat;
    std::cout << "For how many time intervals would you like to calculate values? ";
    std::cin >> n;
    cout << "\n";
    cout << "\n";
    cout << "Position, Velocity, and Acceleration of Spring per Time Interval";
    cout << "\n";
    cout << "\n";
    
//******
//defining variables to use in calculations for the table (csv file)
//******
    double x, v, a, t;
    x = x0;
    v = v0;
    a = -k*x/m;

//******
//spool table headers for screen output
//******
    std::cout << setw(0) << "Time" << setw(20) << "Position" << setw(20) << "Velocity" << setw(21) << "Acceleration\n";

//******
//creates csv file and situates headers
//******
fstream fout;
    fout.open("shm.csv", ios::out | ios::app);
        fout << "Time (s)" << ","
             << "Position (m)" << ","
             << "Velocity (m/s)" << ","
             << "Acceleration (m/s/s)"
             << "\n";

//******
//loop for screen output and csv file calculations
//******
    for( int g = 0; g < n; g++ ) {
        t = deltat * g;
        a = -k*x/m;
        v = deltat*a + v;
        x = v*deltat + x;
        //spool data on screen
        std::cout << setw(3) << t << setw(20) << x << setw(20) << v << setw(20) << a << "\n";       

        // Insert the data to file
        fout << t << ","
             << x << ","
             << v << ","
             << a
             << "\n";
    }
}