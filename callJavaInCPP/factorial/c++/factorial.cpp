#include <jni.h>
#include <iostream>

int main() {
	JavaVMOption options[1];
	JNIEnv *env;
	JavaVM *jvm;
	JavaVMInitArgs vm_args;

	long status;
	jclass cls;
	jmethodID mid;

	std::string path ="-Djava.class.path=../../java/";
	options[0].optionString = const_cast<char *>(path.c_str());
	vm_args.version=JNI_VERSION_1_8;
	vm_args.nOptions = 1;
	vm_args.options = options;
	status = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);

	if(status != JNI_ERR) {
		cls = env->FindClass("Factorial");
		if(cls != 0) {
			mid = env->GetStaticMethodID(cls, "calcFactorial","(Ljava/lang/Integer;)I");
			int number;
			std::cout << "Enter a number : ";
			std::cin >> number;
			std::cout << "You enter : " << number << std::endl;

			if(mid != 0) {
				jclass Integer = env->FindClass("java/lang/Integer");
				jmethodID init = env->GetMethodID(Integer,"<init>","(I)V");
				jmethodID intValue = env->GetMethodID(Integer,"intValue","()I");
				jobject param = env->NewObject(Integer,init,number);

				jobject resultObject =  env->CallStaticObjectMethod(cls, mid, param);

				auto r = env->CallIntMethod(resultObject,intValue); // TODO crash here...

				std::cout << "Factorial Result : " << r << std::endl;
				
			}

			
		}
		jvm->DestroyJavaVM();
		return 0;
	} else {
		return -1;	
	}
}
