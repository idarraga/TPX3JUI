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

//#include <linux/j>

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

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getTpPeriodPhase
 * Signature: (I[I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getTpPeriodPhase
(JNIEnv * env, jobject, jint dev_nr, jintArray period__phase_2pars ) {

	//jsize len = env->GetArrayLength(period__phase);
	jboolean status = true;

	// Get the current values
	jboolean isCopy;
	jint * vals = env->GetIntArrayElements(period__phase_2pars, &isCopy);

	// Request the new ones
	status = g_spidrController->getTpPeriodPhase( (int)dev_nr, &vals[0], &vals[1] );

	// Set the new values in the array
	env->SetIntArrayRegion(period__phase_2pars, 0, 2, vals);

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setTpPeriodPhase
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setTpPeriodPhase
(JNIEnv *, jobject, jint dev_nr, jint period, jint phase) {

	jboolean status = true;
	status = g_spidrController->setTpPeriodPhase((int)dev_nr, (int)period, (int)phase);

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getTpNumber
 * Signature: (I[I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getTpNumber
(JNIEnv * env, jobject, jint dev_nr, jintArray number) {

	jboolean status = true;
	int l_number;
	status = g_spidrController->getTpNumber( (int)dev_nr, &l_number );

	// Set the values in the array
	jint * vals = new jint;
	*vals = (jint)l_number;
	env->SetIntArrayRegion(number, 0, 2, vals);

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setTpNumber
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setTpNumber
(JNIEnv *, jobject, jint dev_nr, jint number) {

	jboolean status = true;

	status = g_spidrController->setTpNumber( (int)dev_nr, (int)number );

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setCtprBit
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setCtprBit
(JNIEnv *, jobject, jint column, jint val = 1) {

	jboolean status = true;

	status = g_spidrController->setCtprBit( (int) column, (int)val );

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setCtprBits
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setCtprBits
(JNIEnv *, jobject, jint val) {

	jboolean status = true;

	status = g_spidrController->setCtprBits( (int)val );

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setCtpr
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setCtpr
(JNIEnv *, jobject, jint dev_nr) {

	jboolean status = true;

	status = g_spidrController->setCtpr( (int)dev_nr );

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getCtpr
 * Signature: (I[C)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getCtpr
(JNIEnv *, jobject, jint dev_nr, jcharArray ctpr) {

	jboolean status = true;

	//unsigned char ** l_ctpr;
	//status = g_spidrController->getCtpr( (int)dev_nr, l_ctpr );

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    resetPixelConfig
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_tpx3jui_SpidrDaqJ_resetPixelConfig
(JNIEnv *, jobject) {

	g_spidrController->resetPixelConfig();

}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setPixelThreshold
 * Signature: (III)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setPixelThreshold
(JNIEnv *, jobject, jint x, jint y, jint threshold) {

	jboolean status = true;

	status = g_spidrController->setPixelThreshold((int) x, (int) y, (int) threshold);

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setPixelTestEna
 * Signature: (IIZ)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setPixelTestEna
(JNIEnv *, jobject, jint x = ALL_PIXELS, jint y = ALL_PIXELS, jboolean b = true) {

	jboolean status = true;

	status = g_spidrController->setPixelTestEna( (int)x, (int)y, (bool)b );

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setPixelMask
 * Signature: (IIZ)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setPixelMask
(JNIEnv *, jobject, jint x = ALL_PIXELS, jint y = ALL_PIXELS, jboolean b = true) {

	jboolean status = true;

	status = g_spidrController->setPixelMask( (int)x, (int)y, (bool)b );

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    setPixelConfig
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_setPixelConfig
(JNIEnv *, jobject, jint dev_nr, jint cols_per_packet = 2) {

	jboolean status = true;

	status = g_spidrController->setPixelConfig( (int)dev_nr, (int) cols_per_packet );

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    getPixelConfig
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_getPixelConfig
(JNIEnv *, jobject, jint dev_nr) {

	jboolean status = true;

	status = g_spidrController->getPixelConfig( (int)dev_nr );

	return status;

}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    resetPixels
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_tpx3jui_SpidrDaqJ_resetPixels
(JNIEnv *, jobject, jint dev_nr) {

	jboolean status = true;

	status = g_spidrController->resetPixels( (int)dev_nr );

	return status;
}

/*
 * Class:     tpx3jui_SpidrDaqJ
 * Method:    pixelConfig
 * Signature: ()[C
 */
JNIEXPORT jcharArray JNICALL Java_tpx3jui_SpidrDaqJ_pixelConfig
(JNIEnv *, jobject) {

	jcharArray config;

	//unsigned char * l_config = g_spidrController->pixelConfig();

	return config;
}

