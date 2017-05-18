#include <jni.h>
#include <iostream>
#include <string>


int main() {
	JavaVMOption options[1];
	JNIEnv* env;
	JavaVM* jvm;
	JavaVMInitArgs vm_args;

	long status;
	jclass cls;
	jmethodID mid;

	std::string path = "-Djava.class.path=../../java/";
	options[0].optionString = const_cast<char *>(path.c_str());
	vm_args.version = JNI_VERSION_1_8;
	vm_args.nOptions = 1;
	vm_args.options = options;

	status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);

	if(status != JNI_ERR) { 
		cls = env->FindClass("Reverse");
		if(cls != 0) { 
			mid = env->GetStaticMethodID(cls,"reverse","(Ljava/lang/String;)Ljava/lang/String;");
			if(mid != 0) {
				jstring param = env->NewStringUTF("reverse");
				jstring result = (jstring)env->CallStaticObjectMethod(cls, mid, param);
				std::string nativeString(env->GetStringUTFChars(result,0));
				std::cout << "Result from Java : " << nativeString << std::endl;
			}
		}
				
		jvm->DestroyJavaVM();
		return 0;
	} else {
		return -1;
	}
}
