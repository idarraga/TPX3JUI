#ifndef __cplusplus
#define __cplusplus 
#endif

#include "tpx3jui_SpidrDaqJ.h"

// TPX3
#include "SpidrController.h"
#include "SpidrDaq.h"
#include "tpx3defs.h"

// The globals
SpidrController * g_spidrController;
SpidrDaq        * g_daq;

JNIEXPORT void JNICALL Java_my_dacs_SpidrDaqJ_resetDevice
(JNIEnv *, jobject, jint dev_nr) {

	g_spidrController->resetDevice((int) dev_nr);

}

JNIEXPORT void JNICALL Java_my_dacs_SpidrDaqJ_resetDevices
(JNIEnv *, jobject) {

	g_spidrController->resetDevices();

}

JNIEXPORT jint JNICALL Java_my_dacs_SpidrDaqJ_getDeviceId
(JNIEnv *, jobject, jint dev_nr) {

	int devId;
	g_spidrController->getDeviceId((int)dev_nr, &devId);

	return (jint)(devId);
}

JNIEXPORT jint JNICALL Java_my_dacs_SpidrDaqJ_getDac
(JNIEnv *, jobject, jint dev_nr, jint dac_code) {

	int dac_val;
	g_spidrController->getDac((int)dev_nr, (int)dac_code, &dac_val);

	return (jint) dac_val;
}

JNIEXPORT void JNICALL Java_my_dacs_SpidrDaqJ_setDac
(JNIEnv *, jobject, jint dev_nr, jint dac_code, jint dac_val) {

	g_spidrController->setDac((int)dev_nr, (int)dac_code, (int)dac_val);

}


JNIEXPORT jboolean JNICALL Java_my_dacs_SpidrDaqJ_ChipConnect
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

JNIEXPORT jboolean JNICALL Java_my_dacs_SpidrDaqJ_ChipDisconnect
(JNIEnv *, jobject){

	if ( g_spidrController ) {
		delete g_spidrController;
		g_spidrController = 0;
	}

	return true;
}

JNIEXPORT jint JNICALL Java_my_dacs_SpidrDaqJ_getDeviceCount
(JNIEnv *, jobject) {

	int devCount;

	g_spidrController->getDeviceCount( &devCount );

	return (jint) (devCount);

}


JNIEXPORT jint JNICALL Java_my_dacs_SpidrDaqJ_getDacCount
  (JNIEnv *, jobject) {
	return (jint) TPX3_DAC_COUNT_TO_SET;
}

/*
 * Class:     my_dacs_SpidrDaqJ
 * Method:    sequentialReadout
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_my_dacs_SpidrDaqJ_sequentialReadout
  (JNIEnv *, jobject, jint tokens){

	bool ret = g_spidrController->sequentialReadout( (int) tokens );

	return (jboolean) ret;
}

/*
 * Class:     my_dacs_SpidrDaqJ
 * Method:    datadrivenReadout
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_my_dacs_SpidrDaqJ_datadrivenReadout
  (JNIEnv *, jobject){

	bool ret = g_spidrController->datadrivenReadout();

	return (jboolean) ret;
}


/*
 * Class:     my_dacs_SpidrDaqJ
 * Method:    pauseReadout
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_my_dacs_SpidrDaqJ_pauseReadout
  (JNIEnv *, jobject) {

	bool ret = g_spidrController->pauseReadout();

	return (jboolean) ret;
}


