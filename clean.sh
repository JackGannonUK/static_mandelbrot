echo "Clean Files? [Y/N]: "
read input
if [[ $input == "Y" || $input == "y" ]]; then
    cd 'build'
    rm mandelbrot.out
    cd 'image_output'
    rm mandelbrot.ppm
else
    echo "Okay."
fi