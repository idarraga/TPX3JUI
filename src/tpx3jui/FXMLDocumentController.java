/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tpx3jui;

import java.awt.AWTException;
import java.awt.Color;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.ResourceBundle;
import javafx.beans.value.ChangeListener;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.control.Skin;
import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.Paint;
import javafx.scene.text.Text;
import sun.awt.RepaintArea;

/**
 *
 * @author idarraga
 */
public class FXMLDocumentController implements Initializable {

    @FXML
    private Label statusLabel;

    @FXML
    private AnchorPane anchor;

    // List of sliders
    @FXML
    private Slider sliderDac1;

    @FXML
    private void handleButtonAction(ActionEvent event) {
        //System.out.println("You clicked me!");
        statusLabel.setText("Link status: Connected");
    }

    @FXML
    private void handleConnectAction(ActionEvent event) {
        
         if (!m_Dacs.IsConnected()) {

            statusLabel.setText("... connecting, wait for timeout");
            //anchor.getScene().getCamera().notify();
            
            // Connection
            if (m_SpidrDaq.ChipConnect()) {
                statusLabel.setText("Link Status: Connected.");
                statusLabel.setTextFill(Paint.valueOf("BLUE"));
                //statusLabel.setForeground(Color.blue);
                m_Dacs.SetIsConnected();

            } else {
                statusLabel.setText("Link Status: Failed connecting.");
                statusLabel.setTextFill(Paint.valueOf("RED"));
                //statusLabel.setForeground(Color.red);
                m_Dacs.SetIsNotConnected();
            }

        } else {
             // if its already reported as connected check if its alive
             
        }
        
    }
    
    @FXML
    private void handleDisconnectAction(ActionEvent event) {

        if ( m_Dacs.IsConnected() ) {

            if (m_SpidrDaq.ChipDisconnect()) {
                statusLabel.setText("Link Status: Disconnected.");
                statusLabel.setTextFill(Paint.valueOf("BLACK"));
                m_Dacs.SetIsNotConnected();
            }

        } // and if it is already disconnected do nothing

    }

    @FXML
    private void handleReconnectAction(ActionEvent event) {
        
        // if is connected, disconnect first
        if (m_Dacs.IsConnected()) {
            handleDisconnectAction(event);
            handleConnectAction(event);
        } else {
            handleConnectAction(event);
        }
        
    }
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        /*
        sliderDac1.valueProperty().addListener( new ChangeListener<Number>() {            
        @Override
        public void changed(ObservableValue<? extends Number> observable,
            Number oldValue, Number newValue) {
            System.out.println("Slider dropped !");
        }
        });
               */ 
    }

    /**
     * Class constructor
     */
    public FXMLDocumentController() {

        initVars();

    }

    private void initVars() {

        System.out.print("Initializing ... \n");
        m_Dacs = new TPX3DaqData();
        m_SpidrDaq = new SpidrDaqJ();
        

    }

    // my vars
    private TPX3DaqData m_Dacs;
    private SpidrDaqJ m_SpidrDaq;

}
