
## Limitations encountered

I couldnot write down a makefile that would create c objects to compile the code.
It gives me a segmentation fault 
The problem due to the use of popen ( ) and the way i structured my code using .h 

# CMAKE

I decided to automate the production of the makefile using CMAKE.
WIth CMAKE, i had to add the math library which is a static library with symbol m.
The makefile was successful and could create objects and final binary through cmake.


## Execution of CMAKE

mkdir build 
cd build
cmake -S .. -B .  

-S is the source where your c files exist
-B is the build directory 
