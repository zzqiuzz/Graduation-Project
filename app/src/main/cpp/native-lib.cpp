#include <jni.h>
#include <string>
#include <UnitTest.h>
#include <CaffeEvaWrapper.h>

extern "C"
{
jint
Java_com_example_zz_q_1cnn_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject instance) {

    bool rtnFlg;
    // create class objects for unit-test
    StopWatch stopWatchObj;
    CaffeEvaWrapper caffeEvaWrapperObj;

    // initialize constant variables
    const std::string kMainDirPath = "";
    const ENUM_CaffeModel kCaffeModel = ENUM_CaffeModel::AlexNet;
    const ENUM_CompMethod kCompMethod = ENUM_CompMethod::Aprx;
    const std::string kClsNameFilePath = "/storage/emulated/legacy/Q_CNN/Cls.Names/class_names.txt";
    const std::string kImgLablFilePath = "/storage/emulated/legacy/Q_CNN/Cls.Names/image_labels.txt";
    const std::string kBmpFilePath = "/storage/emulated/legacy/Q_CNN/Bmp.Files/ILSVRC2012_val_00000003.BMP";
    // initialize the structure for result storing
    CaffeEvaRslt caffeEvaRslt;
    caffeEvaRslt.clsCntPred = 5;

    // predict class labels for a single BMP image
    stopWatchObj.Reset();
    stopWatchObj.Resume();

    rtnFlg = caffeEvaWrapperObj.SetPath(
            kMainDirPath, kClsNameFilePath, kImgLablFilePath);
    rtnFlg = caffeEvaWrapperObj.SetModel(kCaffeModel, kCompMethod);
    rtnFlg = caffeEvaWrapperObj.Proc(kBmpFilePath, &caffeEvaRslt);
    stopWatchObj.Pause();
  //  printf("elapsed time: %.4f (s)\n", stopWatchObj.GetTime());
    // display the classification result
  //  printf("[INFO] input image: %s\n", kBmpFilePath.c_str());
  /*  if (caffeEvaRslt.hasGrthClsName) {
        printf("[INFO] Ground-truth class name: %s\n",
               caffeEvaRslt.clsNameGrth.c_str());
    }  // ENDIF: caffeEvaRslt

    for (int clsIdxPred = 0; clsIdxPred < caffeEvaRslt.clsCntPred; clsIdxPred++) {
        printf("[INFO] No. %d: %s (%d / %.4f)\n", clsIdxPred + 1,
               caffeEvaRslt.clsNameLst[clsIdxPred].c_str(),
               caffeEvaRslt.clsIdxLst[clsIdxPred],
               caffeEvaRslt.clsProbLst[clsIdxPred]);
    }  // ENDFOR: clsIdxPred  */
    return stopWatchObj.GetTime();//env->NewStringUTF(caffeEvaRslt.clsNameGrth.c_str());
}
jstring
Java_com_example_zz_q_1cnn_MainActivity_INFO(JNIEnv *env, jobject instance) {

// TODO
std::string hehe="[INFO] Ground-truth class name:";


return env->NewStringUTF(hehe.c_str());
}

jstring
Java_com_example_zz_q_1cnn_MainActivity_time(JNIEnv *env, jobject instance) {

// TODO
    std::string time="elapsed time:";

    return env->NewStringUTF(time.c_str());
}

jstring
Java_com_example_zz_q_1cnn_MainActivity_msg(JNIEnv *env, jobject instance) {

// TODO
    std::string msg="Please wait!Program's running!";


    return env->NewStringUTF(msg.c_str());
}


}
