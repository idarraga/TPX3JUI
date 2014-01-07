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
    
    public native void     resetDevice      ( int  dev_nr );
    public native void     resetDevices     ( );
    public native int      getDeviceId      ( int  dev_nr );
    //public native int *    getDeviceIds    ( );
    //bool        setSenseDac      ( int  dev_nr, int  dac_code );
    //bool        setExtDac        ( int  dev_nr, int  dac_code, int  dac_val );
    public native int      getDac           ( int  dev_nr, int  dac_code );
    public native void     setDac           ( int  dev_nr, int  dac_code, int  dac_val );
     
    // Data-acquisition
    public native boolean sequentialReadout ( int tokens );
    public native boolean datadrivenReadout ();
    public native boolean pauseReadout      ();
  
    // Vars
    private TPX3DaqData _daqData;
    
}


