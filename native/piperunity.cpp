#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG "PiperUnity"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C"
JNIEXPORT jstring JNICALL
Java_com_sarmad_pipertts_PiperTTSBridge_nativeSynthesize(
    JNIEnv* env,
    jobject thiz,
    jstring text,
    jstring modelPath,
    jstring configPath,
    jstring espeakDataPath,
    jstring outputPath
)
{
    const char* textChars = env->GetStringUTFChars(text, nullptr);
    const char* outputChars = env->GetStringUTFChars(outputPath, nullptr);

    LOGI("nativeSynthesize called. Text: %s", textChars);

    // For now this is a test only.
    // Real Piper code will generate wav here.
    std::string resultPath = outputChars;

    env->ReleaseStringUTFChars(text, textChars);
    env->ReleaseStringUTFChars(outputPath, outputChars);

    return env->NewStringUTF(resultPath.c_str());
}
