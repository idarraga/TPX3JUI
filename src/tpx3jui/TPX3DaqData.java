/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tpx3jui;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * Store in a Java class some minimum Daq information 
 * 
 * @author idarraga
 */
public class TPX3DaqData {

    TPX3DaqData() {
        _deviceCount = -1;
        _isConnected = 0;
    }

    public void SetDeviceCount(int d) { _deviceCount = d; };
    public int GetDeviceCount() { return _deviceCount; };

    public int GetDeviceIdAt(int idx) { return _deviceIds.get( idx ); };
    public int GetDeviceIdsListSize() { return _deviceIds.size(); };
    public void ClearDeviceIdsListSize() { _deviceIds.clear(); };
    public void AddIdToDeviceIdsListSize( int id) { _deviceIds.add( id ); };
    
    
    public void SetIsConnected() { _isConnected = 10; };
    public void SetIsNotConnected() { _isConnected = 0; };
    public boolean IsConnected() { if (_isConnected == 0 ) { return false; } else { return true; } };
    
    // Private
    private int _deviceCount;
    private List<Integer> _deviceIds = new ArrayList<Integer>();
    private int _isConnected;
}
