#include <jni.h>
#include <algorithm>
#include <string>

extern "C" {

JNIEXPORT jstring JNICALL Java_Reverse_reverse(JNIEnv *env, jobject jobj, jstring str) {
	
	const char* org = env->GetStringUTFChars(str, NULL);
	std::string rev(org);
	std::reverse(rev.begin(), rev.end());
	
	return env->NewStringUTF(rev.data());
	
}

}
