#include <jni.h>
#include <iostream>

extern "C" {
JNIEXPORT jintArray JNICALL Java_Fibonacci_returnFibo(JNIEnv* env, jobject jobj, jint n) {
	jintArray fiboarray = env->NewIntArray(n);

	int first = 0;
	int second = 1;
	int next;
	int i;
	int fibo[n];

	for(i=0;i<n;i++) {
		if(i<=1)
			next = i;
		else {
			next = first + second;
			first = second;
			second = next;
		}
		fibo[i] = next;
	}

	env->SetIntArrayRegion(fiboarray,0,n,fibo);

	return fiboarray;
}
}
