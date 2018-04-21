# Software Engineering Project - Bug World

### Build and Compile

1. create a new directory and cd to it
```shell
mkdir build
cd build
```
2. run cmake
```shell
cmake ..
```
3. run make
```shell
make
```

this will generate the binaries into the individual directories ie. asm in src/assembler

### Tests

after building and compiling:
```shell
cd build
make test 
```
will run the tests

### Dependencies

- [CPPUnit](https://sourceforge.net/projects/cppunit/)
- [CMake](https://cmake.org/)