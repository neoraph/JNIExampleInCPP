#include <jni.h>
#include <jni_md.h>
#include <vector>
#include <string>
#include <stdio.h>

extern "C" {
JNIEXPORT jobjectArray JNICALL Java_DaysOfTheWeek_displayDays(JNIEnv *env, jobject jobj) {
	
	std::vector<std::string> days;
	days.emplace_back("monday");
	days.emplace_back("tuesday"),
	days.emplace_back("wednesday"),
	days.emplace_back("thursday"),
	days.emplace_back("friday"),
	days.emplace_back("saturday"),
	days.emplace_back("sunday");
			
	jstring str;
	jobjectArray day = 0;
	jsize len = 7;
	jstring jstr = env->NewStringUTF("");

	day = env->NewObjectArray(len, env->FindClass("java/lang/String"),0);
	
	int i = 0;	

	for(std::string d : days) { 
		str = env->NewStringUTF(d.data());
		env->SetObjectArrayElement(day, i, str); 
		i++;
	}
	return day; 
}
}
