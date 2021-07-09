// Written by Jack Gannon

// main.cpp

/***************************************/
/***************INCLUDES****************/
/***************************************/

#include <iostream>
#include <fstream> // Used for file manipulation
#include <complex> // Used for math

using namespace std;

// File Formatting

float width;    // Width dimensions
float height;   // Height dimesions

// Mandelbrot Set Code

int value ( int x, int y ){
    complex<float> point((float)x/width-1.5, (float)y/height-0.5);
    
complex<float> z(0, 0);
    unsigned int nb_iter = 0;
    while (abs (z) < 2 && nb_iter <= 34) {
           z = z * z + point;
           nb_iter++;
    }
    if (nb_iter < 200) return (255*nb_iter)/33;
    else return 0;
}

int main(){
    cout << "Enter the width of your image: ";  // User input for Width
    cin >> width;                                   // Setting Width variable

    cout << "Enter the height of your image: "; // User input for Height
    cin >> height;                                  // Setting Height variable

    ofstream mandel_image ("mandelbrot.ppm");
    if (mandel_image.is_open ()){
        mandel_image << "P3\n" << width << " " << height << " 255\n";
        for (int i = 0; i < width; i++){
            for (int j = 0; j < height; j++){
                  int val = value(i, j); 
                  mandel_image << val<< ' ' << 0 << ' ' << 0 << "\n";
            }
        }
        mandel_image.close();
    }
    else cout << "Could not open the file.";
    return 0;
}

