/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <linux/jni_md.h>
/* Header for class tpx3jui_SpidrDaqJ */

#ifndef _Included_tpx3jui_SpidrDaqJ
#define _Included_tpx3jui_SpidrDaqJ
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    ChipConnect
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_ChipConnect
  (JNIEnv *, jobject);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    ChipDisconnect
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_ChipDisconnect
  (JNIEnv *, jobject);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    AcqOnOff
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_AcqOnOff
  (JNIEnv *, jobject);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getDeviceCount
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getDeviceCount
  (JNIEnv *, jobject);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getDacCount
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getDacCount
  (JNIEnv *, jobject);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    resetDevice
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_tpx3jui_SpidrDaqJ_resetDevice
  (JNIEnv *, jobject, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    resetDevices
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_tpx3jui_SpidrDaqJ_resetDevices
  (JNIEnv *, jobject);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getDeviceId
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getDeviceId
  (JNIEnv *, jobject, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setSenseDac
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setSenseDac
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getDac
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getDac
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setDac
 * Signature: (III)V
 */
JNIEXPORT void JNICALL Java_tpx3jui_SpidrDaqJ_setDac
  (JNIEnv *, jobject, jint, jint, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    dacName
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_tpx3jui_SpidrDaqJ_dacName
  (JNIEnv *, jobject, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    dacMax
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_dacMax
  (JNIEnv *, jobject, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getTpPeriodPhase
 * Signature: (I[I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getTpPeriodPhase
  (JNIEnv *, jobject, jint, jintArray);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setTpPeriodPhase
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setTpPeriodPhase
  (JNIEnv *, jobject, jint, jint, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getTpNumber
 * Signature: (I[I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getTpNumber
  (JNIEnv *, jobject, jint, jintArray);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setTpNumber
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setTpNumber
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setCtprBit
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setCtprBit
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setCtprBits
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setCtprBits
  (JNIEnv *, jobject, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setCtpr
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setCtpr
  (JNIEnv *, jobject, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getCtpr
 * Signature: (I[C)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getCtpr
  (JNIEnv *, jobject, jint, jcharArray);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    resetPixelConfig
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_tpx3jui_SpidrDaqJ_resetPixelConfig
  (JNIEnv *, jobject);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setPixelThreshold
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setPixelThreshold
  (JNIEnv *, jobject, jint, jint, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setPixelTestEna
 * Signature: (IIZ)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setPixelTestEna
  (JNIEnv *, jobject, jint, jint, jboolean);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setPixelMask
 * Signature: (IIZ)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setPixelMask
  (JNIEnv *, jobject, jint, jint, jboolean);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setPixelConfig
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setPixelConfig
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getPixelConfig
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getPixelConfig
  (JNIEnv *, jobject, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    resetPixels
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_resetPixels
  (JNIEnv *, jobject, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    pixelConfig
 * Signature: ()[C
 */
JNIEXPORT jcharArray JNICALL Java_tpx3jui_SpidrDaqJ_pixelConfig
  (JNIEnv *, jobject);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    sequentialReadout
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_sequentialReadout
  (JNIEnv *, jobject, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    datadrivenReadout
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_datadrivenReadout
  (JNIEnv *, jobject);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    pauseReadout
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_pauseReadout
  (JNIEnv *, jobject);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getAdc
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getAdc
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getRemoteTemp
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getRemoteTemp
  (JNIEnv *, jobject);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getLocalTemp
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getLocalTemp
  (JNIEnv *, jobject, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getAvdd
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getAvdd
  (JNIEnv *, jobject, jint, jint, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getDvdd
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getDvdd
  (JNIEnv *, jobject, jint, jint, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getBiasVoltage
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getBiasVoltage
  (JNIEnv *, jobject, jint);

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getVdda
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getVdda
  (JNIEnv *, jobject, jint);

#ifdef __cplusplus
}
#endif
#endif
