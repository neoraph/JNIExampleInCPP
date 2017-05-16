# JNIExampleInCPP
Rewrite the example of this blog (https://chandruscm.wordpress.com/2015/08/10/how-to-use-jni-java-native-interface-with-cc/) which gets this github repository (https://github.com/chandruscm/JNIexamples) in C++

<br>
It is nice example, however, it is written in C and some of functions does not work well in C++.

Thank you Chandruscm, I rewrite it in order to train JNI and use C++11.


How to generate the header file :

- After compiling the java file (javac <theFile>.java), generate the header file by using the command line javah -jni <theFile>
- once you get the header file (<theFile>.h), copy it in c++/include

Compiling C++ part
- Create a build folder in c++ folder and go inside
- From here, do the following steps:
cmake ..
then 
make
You will generate the <yourfile>.so

Execute the program :

Go back to the java folder

You have to link the library to the system in order that Java can access it. 3 ways to do that :

1) copy the library to /usr/lib
2) export the LD_LIBRARY_PATH :
  export LD_LIBRARY_PATH = $LD_LIBRARY_PATH:<path_of_the_library>
3) run java with java -Djava.library.path=<path_of_the_library> <exe>










