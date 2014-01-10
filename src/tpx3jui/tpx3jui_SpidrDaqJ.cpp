#ifndef __cplusplus
#define __cplusplus 
#endif

#include "tpx3jui_SpidrDaqJ.h"

// TPX3
#include "SpidrController.h"
#include "SpidrDaq.h"
#include "tpx3defs.h"
#include "dacsdescr.h"

#include <string>

using namespace std;


// The globals
SpidrController * g_spidrController;
SpidrDaq        * g_daq;

JNIEXPORT void JNICALL Java_tpx3jui_SpidrDaqJ_resetDevice
(JNIEnv *, jobject, jint dev_nr) {

	g_spidrController->resetDevice((int) dev_nr);

}

JNIEXPORT void JNICALL Java_tpx3jui_SpidrDaqJ_resetDevices
(JNIEnv *, jobject) {

	g_spidrController->resetDevices();

}

JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getDeviceId
(JNIEnv *, jobject, jint dev_nr) {

	int devId;
	g_spidrController->getDeviceId((int)dev_nr, &devId);

	return (jint)(devId);
}

JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setSenseDac
  (JNIEnv *, jobject, jint dev_nr, jint dac_code) {

	bool ret = g_spidrController->setSenseDac( dev_nr, dac_code );

	return (jboolean) ret;
}

JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getDac
(JNIEnv *, jobject, jint dev_nr, jint dac_code) {

	int dac_val;
	g_spidrController->getDac((int)dev_nr, (int)dac_code, &dac_val);

	return (jint) dac_val;
}

JNIEXPORT void JNICALL Java_tpx3jui_SpidrDaqJ_setDac
(JNIEnv *, jobject, jint dev_nr, jint dac_code, jint dac_val) {

	g_spidrController->setDac((int)dev_nr, (int)dac_code, (int)dac_val);

}


JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_ChipConnect
(JNIEnv *, jobject) {

	jboolean conn = false;

	g_spidrController =
			new SpidrController( 192,
					168,
					100,
					10,
					50000 );
	if( g_spidrController->isConnected() ) {
		conn = true;
	}

	return conn;
}

JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_ChipDisconnect
(JNIEnv *, jobject){

	if ( g_spidrController ) {
		delete g_spidrController;
		g_spidrController = 0;
	}

	return true;
}

JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getDeviceCount
(JNIEnv *, jobject) {

	int devCount;

	g_spidrController->getDeviceCount( &devCount );

	return (jint) (devCount);

}


JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getDacCount
  (JNIEnv *, jobject) {
	return (jint) TPX3_DAC_COUNT_TO_SET;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    sequentialReadout
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_sequentialReadout
  (JNIEnv *, jobject, jint tokens){

	bool ret = g_spidrController->sequentialReadout( (int) tokens );

	return (jboolean) ret;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    datadrivenReadout
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_datadrivenReadout
  (JNIEnv *, jobject){

	bool ret = g_spidrController->datadrivenReadout();

	return (jboolean) ret;
}


/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    pauseReadout
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_pauseReadout
  (JNIEnv *, jobject) {

	bool ret = g_spidrController->pauseReadout();

	return (jboolean) ret;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    dacName
 * Signature: (I)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_tpx3jui_SpidrDaqJ_dacName
  (JNIEnv * env, jobject, jint dac_code) {

	string name = g_spidrController->dacName( dac_code );

	return env->NewStringUTF( name.c_str() );
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    dacMax
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_dacMax
  (JNIEnv *, jobject, jint dac_code){

	int max = g_spidrController->dacMax( dac_code );

	return (jint) max;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getAdc
 * Signature: (III)Z
 */
JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getAdc
  (JNIEnv *, jobject, jint dev_nr, jint nr_of_samples) {

	int adc_val;
	g_spidrController->getAdc( (int)dev_nr, &adc_val, (int)nr_of_samples );

	return (jint)(adc_val);
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getRemoteTemp
 * Signature: (I)Z
 */
JNIEXPORT jint JNICALL Java_tpx3jui_SpidrDaqJ_getRemoteTemp
  (JNIEnv *, jobject){

	int val;
	g_spidrController->getRemoteTemp( &val );

	return val;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getLocalTemp
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getLocalTemp
  (JNIEnv *, jobject, jint) {
	return true;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getAvdd
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getAvdd
  (JNIEnv *, jobject, jint, jint, jint) {

	return true;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getDvdd
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getDvdd
  (JNIEnv *, jobject, jint, jint, jint) {

	return true;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getBiasVoltage
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getBiasVoltage
  (JNIEnv *, jobject, jint) {
	return true;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getVdda
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getVdda
  (JNIEnv *, jobject, jint) {

	return true;
}
