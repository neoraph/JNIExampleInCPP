#include <jni.h>
#include <memory>
#include <string>


int main(int argc, char **argv) {
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
		cls = env->FindClass("HelloWorldJNI");
		if(cls != 0) {
			mid = env->GetStaticMethodID(cls, "helloWorld","()V" );
			if(mid != 0) {
				env->CallStaticVoidMethod(cls, mid);
			}
		}
		
		jvm->DestroyJavaVM();
		return 0;
	} else {
		return -1;
	}
}
