#include <jni.h>

extern "C" {

JNIEXPORT jint JNICALL Java_Factorial_fact(JNIEnv* env, jobject jobj, jint num) {
	jint result = 1;
	
	while (num) { 
		result*=num;
		num--;
	}

	return result;
}

}
