/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package tpx3jui;

/**
 *
 * @author idarraga
 * 
 * The native method names will be identical here as in the 
 *  SpidrController interface.
 */
public class SpidrDaqJ {
    
    static {

        System.out.print( "Libs --> " );
        System.out.print( System.getProperty("java.library.path") + "\n");
        System.loadLibrary("SpidrTpx3Lib");
        System.loadLibrary("SpidrDaqJ");

    }
    
    SpidrDaqJ () {
        

    }
    
    // Native but introduced by hand

    public native boolean ChipConnect();
    public native boolean ChipDisconnect();
    public native boolean AcqOnOff();
    
    
    public native int getDeviceCount();
    public native int getDacCount();
   
    
    // Native and exact as defined in the TPX3 lib
    
    // Configuration: device
    public native void     resetDevice      ( int  dev_nr );
    public native void     resetDevices     ( );
    public native int      getDeviceId      ( int  dev_nr );
    //public native int *    getDeviceIds    ( );
    public native boolean  setSenseDac      ( int  dev_nr, int  dac_code );
    //bool        setExtDac        ( int  dev_nr, int  dac_code, int  dac_val );
    public native int      getDac           ( int  dev_nr, int  dac_code );
    public native void     setDac           ( int  dev_nr, int  dac_code, int  dac_val );
    public native String   dacName          ( int  dac_code );
    public native int      dacMax           ( int  dac_code );
  
    /*
    // Configuration: device test pulses
  bool        getTpPeriodPhase ( int  dev_nr, int *period, int *phase );
  bool        setTpPeriodPhase ( int  dev_nr, int  period, int  phase );
  bool        getTpNumber      ( int  dev_nr, int *number );
  bool        setTpNumber      ( int  dev_nr, int  number );
  bool        setCtprBit       ( int  column, int val = 1 );
  bool        setCtprBits      ( int  val = 1 );
  bool        setCtpr          ( int  dev_nr );
  bool        getCtpr          ( int  dev_nr, unsigned char **ctpr );
*/
    
    // Data-acquisition
    public native boolean sequentialReadout ( int tokens );
    public native boolean datadrivenReadout ();
    public native boolean pauseReadout      ();
  
    // Monitoring
    public native int     getAdc                  ( int dev_nr, int  nr_of_samples ); // ref adc_val
    public native int     getRemoteTemp           ( ); // ref mdegrees
    public native boolean getLocalTemp            ( int mdegrees ); // ref mdegrees
    public native boolean getAvdd                 ( int mvolts, int mamps, int mwatts ); // ref all
    public native boolean getDvdd                 ( int mvolts, int mamps, int mwatts ); // ref all
    public native boolean getBiasVoltage          ( int volts ); // ref all
    public native boolean getVdda                 ( int mvolts ); // ref all
    
    // Vars
    private TPX3DaqData _daqData;
    
}


