/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package tpx3jui;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Label;

/**
 *
 * @author idarraga
 */
public class FXMLDocumentController implements Initializable {
    
    @FXML
    private Label statusLabel;
    
    @FXML
    private void handleButtonAction(ActionEvent event) {
        //System.out.println("You clicked me!");
        statusLabel.setText("Link status: Connected");
    }
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    
}
