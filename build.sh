cd 'src'
g++ -w main.cpp -o ../build/mandelbrot.out
cd ..
cd 'build'
./mandelbrot.out
mv mandelbrot.ppm image_output/mandelbrot.ppm
echo "Open Output Image? [Y/N]: "
read input
if [[ $input == "Y" || $input == "y" ]]; then
    cd 'image_output'
    open 'mandelbrot.ppm'
else
    echo "Okay."
fi