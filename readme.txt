Repo for me to learn more about computer graphics. (Also good practice setting up my compiler toolchain lol)
This project expects SFML 2.6.0 to be in SFML_DIR, and Eigen 3.4.0 to be in Eigen3_INCLUDE_DIR.
It's also written in C++20 (probably not good C++20 though, I use 17 most of the time).

Example build commands (Windows):
cmake -S . -B ./build -G "NMake Makefiles" `
	-DCMAKE_BUILD_TYPE=Release `
	-D"SFML_DIR=./ext/SFML-2.6.0/lib/cmake/SFML" `
	-D"Eigen3_INCLUDE_DIR=./ext/eigen-3.4.0/cmake"