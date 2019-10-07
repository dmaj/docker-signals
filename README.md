# docker-signals

Some test programs to test the signal handling in Docker.

showsig:
The program "showsig" registers for all available signals. An incoming signal is output on the console.

It's a good idea to compile this program as a static binary:
gcc -o showsig showsig.c -static -I.

showsig has learned colors: red, green, blue, yellow, magenta, cyan
