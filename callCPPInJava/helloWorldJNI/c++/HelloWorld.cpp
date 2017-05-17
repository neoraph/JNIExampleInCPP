#include <jni.h>
#include <jni_md.h>
#include <iostream>
#include "HelloWorld.h"

JNIEXPORT void JNICALL Java_HelloWorld_display (JNIEnv *, jobject) {
	std::cout << " C++ says HelloWorld!" << std::endl ;
}

