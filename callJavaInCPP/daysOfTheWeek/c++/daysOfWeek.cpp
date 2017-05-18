#include <jni.h>
#include <string>
#include <iostream>

int main() {
	
	JavaVMOption options[1];
	JNIEnv *env;
	JavaVM *jvm;
	JavaVMInitArgs vm_args;

	long status;
	jclass cls;
	jmethodID mid;
	
	std::string path = "-Djava.class.path=../../java/";
	options[0].optionString = const_cast<char *>(path.c_str());
	vm_args.version = JNI_VERSION_1_8;
	vm_args.nOptions = 1;
	vm_args.options = options;

	status = JNI_CreateJavaVM(&jvm, (void **)&env, &vm_args);
	
	if(status != JNI_ERR) {
		cls = env->FindClass("DaysOfTheWeek");
		if(cls != 0) {
			mid = env->GetStaticMethodID(cls,"getDaysOfTheWeek","()Ljava/util/List;");
			if(mid != 0) {
				jobject listOfWeek = (jobject)env->CallStaticObjectMethod(cls,mid);
				jclass list = env->FindClass("java/util/List");
				jmethodID toArray = env->GetMethodID(list, "toArray", "()[Ljava/lang/Object;");
				jobjectArray array = (jobjectArray)env->CallObjectMethod(listOfWeek,toArray);
				int size = env->GetArrayLength(array);
			
				for(int i=0; i<size; i++) {
					jstring day = (jstring)env->GetObjectArrayElement(array,i);
					const std::string strObj = const_cast<char*>(env->GetStringUTFChars(day, NULL));
					std::cout << strObj << std::endl;
				}
				std::cout << "number of data : " << size << std::endl;	
			}
		}
		jvm->DestroyJavaVM();
	} else {
		return -1;
	}
}	

