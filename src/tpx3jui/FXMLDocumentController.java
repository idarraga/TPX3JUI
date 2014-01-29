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
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.concurrent.Service;
import javafx.concurrent.Task;
import javafx.concurrent.*;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ProgressIndicator;
//import javafx.scene.control.ProgressBar;
import javafx.scene.control.Slider;
import javafx.scene.control.Skin;
import javafx.scene.control.TextField;
import javafx.scene.input.DragEvent;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseDragEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.Paint;
import javafx.scene.text.Text;
//import sun.nio.ch.DefaultAsynchronousChannelProvider;
//import sun.awt.RepaintArea;

/**
 *
 * @author idarraga
 */
public class FXMLDocumentController implements Initializable {

    @FXML
    private Label statusLabel;

    @FXML
    private Label acqInfoLabel;

    @FXML
    private AnchorPane anchor;

    @FXML
    private Button senseDACButton;

    @FXML
    private Button DACScanButton;

    @FXML
    private ProgressIndicator DACScanProgressIndicator;

    @FXML
    private LineChart dacsLineChart;

    Task worker;
    private List<XYChart.Series> seriesList = new ArrayList<XYChart.Series>();
    XYChart.Series seriesDAC1 = new XYChart.Series();

    // Constants
    private final int __N_DACS = 18;
    private final int __N_DACSCAN_STEP_MAGICNUMBER = 40;
    private final int __DEVICEID = 0;
    // Ref = 1.5V. DAC Granularity is (12bits := 8191 steps) 0.000183127823220608V
    private final double __V_PER_STEP = 0.000183127823220608;

    // List of sliders
    private List<Slider> sliderDacList = new ArrayList<Slider>();
    @FXML
    private Slider sliderDac1;
    @FXML
    private Slider sliderDac2;
    @FXML
    private Slider sliderDac3;
    @FXML
    private Slider sliderDac4;
    @FXML
    private Slider sliderDac5;
    @FXML
    private Slider sliderDac6;
    @FXML
    private Slider sliderDac7;
    @FXML
    private Slider sliderDac8;
    @FXML
    private Slider sliderDac9;
    @FXML
    private Slider sliderDac10;
    @FXML
    private Slider sliderDac11;
    @FXML
    private Slider sliderDac12;
    @FXML
    private Slider sliderDac13;
    @FXML
    private Slider sliderDac14;
    @FXML
    private Slider sliderDac15;
    @FXML
    private Slider sliderDac16;
    @FXML
    private Slider sliderDac17;
    @FXML
    private Slider sliderDac18;

    // TextFiels for Dacs
    private List<TextField> textDacList = new ArrayList<TextField>();
    @FXML
    private TextField textDac1;
    @FXML
    private TextField textDac2;
    @FXML
    private TextField textDac3;
    @FXML
    private TextField textDac4;
    @FXML
    private TextField textDac5;
    @FXML
    private TextField textDac6;
    @FXML
    private TextField textDac7;
    @FXML
    private TextField textDac8;
    @FXML
    private TextField textDac9;
    @FXML
    private TextField textDac10;
    @FXML
    private TextField textDac11;
    @FXML
    private TextField textDac12;
    @FXML
    private TextField textDac13;
    @FXML
    private TextField textDac14;
    @FXML
    private TextField textDac15;
    @FXML
    private TextField textDac16;
    @FXML
    private TextField textDac17;
    @FXML
    private TextField textDac18;

    private List<Label> labelDacList = new ArrayList<Label>();
    @FXML
    private Label labelDac1;
    @FXML
    private Label labelDac2;
    @FXML
    private Label labelDac3;
    @FXML
    private Label labelDac4;
    @FXML
    private Label labelDac5;
    @FXML
    private Label labelDac6;
    @FXML
    private Label labelDac7;
    @FXML
    private Label labelDac8;
    @FXML
    private Label labelDac9;
    @FXML
    private Label labelDac10;
    @FXML
    private Label labelDac11;
    @FXML
    private Label labelDac12;
    @FXML
    private Label labelDac13;
    @FXML
    private Label labelDac14;
    @FXML
    private Label labelDac15;
    @FXML
    private Label labelDac16;
    @FXML
    private Label labelDac17;
    @FXML
    private Label labelDac18;

    private List<Label> labelDacSenseList = new ArrayList<Label>();
    @FXML
    private Label labelDacSense1;
    @FXML
    private Label labelDacSense2;
    @FXML
    private Label labelDacSense3;
    @FXML
    private Label labelDacSense4;
    @FXML
    private Label labelDacSense5;
    @FXML
    private Label labelDacSense6;
    @FXML
    private Label labelDacSense7;
    @FXML
    private Label labelDacSense8;
    @FXML
    private Label labelDacSense9;
    @FXML
    private Label labelDacSense10;
    @FXML
    private Label labelDacSense11;
    @FXML
    private Label labelDacSense12;
    @FXML
    private Label labelDacSense13;
    @FXML
    private Label labelDacSense14;
    @FXML
    private Label labelDacSense15;
    @FXML
    private Label labelDacSense16;
    @FXML
    private Label labelDacSense17;
    @FXML
    private Label labelDacSense18;

    private void initVars() {

        System.out.print("Initializing ... \n");
        m_Dacs = new TPX3DaqData();
        m_SpidrDaq = new SpidrDaqJ();

    }

    private void senseDAC() {

        for (int i = 0; i < __N_DACS; i++) {
            m_SpidrDaq.setSenseDac(__DEVICEID, i + 1);
            int sensedVal = m_SpidrDaq.getAdc(__DEVICEID, 10); // second par is nSampligns
            // ACD is 12 bits and voltage reference is 1.5
            // Granularity is (12bits := 8191 steps) 0.000183127823220608 V
            double sensedValV = sensedVal * __V_PER_STEP;
            String formattedSense = String.format("%.3fV", sensedValV);
            labelDacSenseList.get(i).setText(formattedSense);
        }
    }

    @FXML
    private void handleSenseDACButtonAction(ActionEvent event) {

        
        m_SpidrDaq.setTpPeriodPhase(0, 1, 2);
        
        senseDAC();

        int[] period__phase_2pars = new int[2];
        m_SpidrDaq.getTpPeriodPhase(0, period__phase_2pars);
        System.out.println("data1 = " + String.valueOf( period__phase_2pars[0] ) + ", data2 = " + String.valueOf( period__phase_2pars[1] ) );
        
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
                // apply start up actions
                startUpActions();

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

        if (m_Dacs.IsConnected()) {

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

    // create a service.
    final Service DACDataGenerator = new Service<ObservableList<XYChart.Series>>() {

        @Override
        protected Task createTask() {

            return new Task<ObservableList<XYChart.Series>>() {
                @Override
                protected ObservableList<XYChart.Series> call() throws InterruptedException {

                    double sensedVal;
                    int max;
                    int dacsave;
                    int step = 0;
                    int totalIterations = 0;
                    // Calculate first the total number of iterations
                    for (int dacCode = 1; dacCode <= __N_DACS; dacCode++) {
                        max = m_SpidrDaq.dacMax(dacCode);
                        step = max / __N_DACSCAN_STEP_MAGICNUMBER;
                        if (step < 1) {
                            step = 1;
                        }
                        totalIterations += max / step;
                    }

                    ObservableList<XYChart.Series> allSeries = FXCollections.observableArrayList();
                    int prog_cntr = 1;
                    for (int dacCode = 1; dacCode <= __N_DACS - 1; dacCode++) {

                        // New series
                        XYChart.Series series1 = new XYChart.Series();
                        series1.setName(m_SpidrDaq.dacName(dacCode));

                        m_SpidrDaq.setSenseDac(__DEVICEID, dacCode);
                        // Save current dac value
                        dacsave = m_SpidrDaq.getDac(__DEVICEID, dacCode);
                        max = m_SpidrDaq.dacMax(dacCode);
                        step = max / __N_DACSCAN_STEP_MAGICNUMBER;
                        if (step < 1) {
                            step = 1;
                        }

                        for (int i = 0; i < max; i += step) {

                            updateProgress(prog_cntr, totalIterations);
                            prog_cntr += 1;

                            // set dac
                            m_SpidrDaq.setDac(__DEVICEID, dacCode, i);
                            // Actualize slider and text box
                            sliderDacList.get(dacCode - 1).setValue(i);
                            textDacList.get(dacCode - 1).setText(String.valueOf(i));
                            // Sense dac
                            sensedVal = m_SpidrDaq.getAdc(__DEVICEID, 10); // second par is nSampligns     
                            // to volts
                            sensedVal = sensedVal * __V_PER_STEP;
                            series1.getData().add(new XYChart.Data(i, sensedVal));

                        }

                        // Reset to original dac value
                        m_SpidrDaq.setDac(__DEVICEID, dacCode, dacsave);
                        // Actualize slider and text box
                        sliderDacList.get(dacCode - 1).setValue(dacsave);
                        textDacList.get(dacCode - 1).setText(String.valueOf(dacsave));

                        // Add Series
                        allSeries.add(series1);

                    }

                    DACScanButton.setDisable(false);

                    return allSeries;
                }
            };
        }
    };

    @FXML
    private void handleDACScanButtonAction(ActionEvent event) {

        DACScanButton.setDisable(true);
        dacsLineChart.dataProperty().bind(DACDataGenerator.valueProperty());

        if (!DACDataGenerator.isRunning()) {

            DACDataGenerator.reset();
            DACDataGenerator.start();

        }

    }

    @Override
    public void initialize(URL url, ResourceBundle rb) {

        // Setup dac control
        setupDacControl();

        // Decide what to do un the different states of the DACDataGenerator Service
        DACDataGenerator.stateProperty().addListener(new ChangeListener<Worker.State>() {
            @Override
            public void changed(ObservableValue<? extends Worker.State> observableValue, Worker.State oldState,
                    Worker.State newState
            ) {
                switch (newState) {
                    case SCHEDULED:
                        acqInfoLabel.setVisible(false);
                        DACScanProgressIndicator.progressProperty().bind(DACDataGenerator.progressProperty());  // workaround, we should be able to permanently bind to the progress, but unless we do this sometimes the progress does not always reach the end.
                        break;
                    case READY:
                    case RUNNING:
                        acqInfoLabel.setVisible(true);
                        acqInfoLabel.setText("Running DAC Scan ...");
                        break;
                    case SUCCEEDED:
                        acqInfoLabel.setVisible(true);
                        acqInfoLabel.setText("DAC Scan done.");
                        DACScanProgressIndicator.progressProperty().unbind();
                        DACScanProgressIndicator.setProgress(1);  // workaround, we should be able to permanently bind to the progress, but unless we do this sometimes the progress does not always reach the end. (even this workaround didn't work, so I have no idea about this...)

                        DACScanButton.setDisable(true);
                        dacsLineChart.dataProperty().bind(DACDataGenerator.valueProperty());

                        //if (!DACDataGenerator.isRunning()) {
                        //    DACDataGenerator.reset();
                        //    DACDataGenerator.start();
                        //}

                        break;
                    case CANCELLED:
                    case FAILED:
                        acqInfoLabel.setVisible(true);
                        acqInfoLabel.setText("Error running DAC Scan.");
                        break;
                }
            }
        }
        );

    }

    public void startUpActions() {

        // Fill DACs with startup values
        initDacControl();

    }

    public void initDacControl() {

        int dacval;
        int dacCode;
        for (int i = 0; i < __N_DACS; i++) {
            dacval = m_SpidrDaq.getDac(__DEVICEID, i + 1);
            dacCode = i + 1;
            sliderDacList.get(i).setValue(dacval);
            textDacList.get(i).setText(String.valueOf(dacval));

            // Set max properly for sliders
            sliderDacList.get(i).setMin(0);
            System.out.println("[" + String.valueOf(i) + "] max = " + String.valueOf(m_SpidrDaq.dacMax(dacCode)));
            sliderDacList.get(i).setMax(m_SpidrDaq.dacMax(dacCode));
        }

        senseDAC();

    }

    public void setupDacControl() {

        // While Dragging change the value but only set DACs when releasing the mouse click
        sliderDac1.setOnMouseDragged(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent m) {
                textDac1.setText(String.valueOf((int) sliderDac1.getValue()));
            }
        });
        sliderDac1.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent m) {
                m_SpidrDaq.setDac(__DEVICEID, 1, (int) sliderDac1.getValue());
            }
        });
        textDac1.setOnKeyReleased(new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent t) {
                if (t.getCode() == KeyCode.ENTER) {
                    // Extract the value from TextField
                    String text = textDac1.getText();
                    if (DacStringValid(text, sliderDac1)) {
                        int val = Integer.parseInt(text);
                        // move the slider first
                        sliderDac1.setValue(val);
                        // Set the Dac
                        m_SpidrDaq.setDac(__DEVICEID, 1, val);
                    }
                    System.out.println(m_SpidrDaq.dacName(1) + ": " + String.valueOf(text));
                }
            }
        });

        // While Dragging change the value but only set DACs when releasing the mouse click
        sliderDac2.setOnMouseDragged(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent m) {
                textDac2.setText(String.valueOf((int) sliderDac2.getValue()));
            }
        });
        sliderDac2.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent m) {
                m_SpidrDaq.setDac(__DEVICEID, 2, (int) sliderDac2.getValue());
            }
        });
        textDac2.setOnKeyReleased(new EventHandler<KeyEvent>() {
            @Override
            public void handle(KeyEvent t) {
                if (t.getCode() == KeyCode.ENTER) {
                    // Extract the value from TextField
                    String text = textDac2.getText();
                    if (DacStringValid(text, sliderDac2)) {
                        int val = Integer.parseInt(text);
                        // move the slider first
                        sliderDac2.setValue(val);
                        // Set the Dac
                        m_SpidrDaq.setDac(__DEVICEID, 2, val);
                    }
                    System.out.println(m_SpidrDaq.dacName(2) + ": " + String.valueOf(text));
                }
            }
        });

        sliderDacList.add(sliderDac1);
        sliderDacList.add(sliderDac2);
        sliderDacList.add(sliderDac3);
        sliderDacList.add(sliderDac4);
        sliderDacList.add(sliderDac5);
        sliderDacList.add(sliderDac6);
        sliderDacList.add(sliderDac7);
        sliderDacList.add(sliderDac8);
        sliderDacList.add(sliderDac9);
        sliderDacList.add(sliderDac10);
        sliderDacList.add(sliderDac11);
        sliderDacList.add(sliderDac12);
        sliderDacList.add(sliderDac13);
        sliderDacList.add(sliderDac14);
        sliderDacList.add(sliderDac15);
        sliderDacList.add(sliderDac16);
        sliderDacList.add(sliderDac17);
        sliderDacList.add(sliderDac18);

        textDacList.add(textDac1);
        textDacList.add(textDac2);
        textDacList.add(textDac3);
        textDacList.add(textDac4);
        textDacList.add(textDac5);
        textDacList.add(textDac6);
        textDacList.add(textDac7);
        textDacList.add(textDac8);
        textDacList.add(textDac9);
        textDacList.add(textDac10);
        textDacList.add(textDac11);
        textDacList.add(textDac12);
        textDacList.add(textDac13);
        textDacList.add(textDac14);
        textDacList.add(textDac15);
        textDacList.add(textDac16);
        textDacList.add(textDac17);
        textDacList.add(textDac18);

        labelDacList.add(labelDac1);
        labelDacList.add(labelDac2);
        labelDacList.add(labelDac3);
        labelDacList.add(labelDac4);
        labelDacList.add(labelDac5);
        labelDacList.add(labelDac6);
        labelDacList.add(labelDac7);
        labelDacList.add(labelDac8);
        labelDacList.add(labelDac9);
        labelDacList.add(labelDac10);
        labelDacList.add(labelDac11);
        labelDacList.add(labelDac12);
        labelDacList.add(labelDac13);
        labelDacList.add(labelDac14);
        labelDacList.add(labelDac15);
        labelDacList.add(labelDac16);
        labelDacList.add(labelDac17);
        labelDacList.add(labelDac18);

        labelDacSenseList.add(labelDacSense1);
        labelDacSenseList.add(labelDacSense2);
        labelDacSenseList.add(labelDacSense3);
        labelDacSenseList.add(labelDacSense4);
        labelDacSenseList.add(labelDacSense5);
        labelDacSenseList.add(labelDacSense6);
        labelDacSenseList.add(labelDacSense7);
        labelDacSenseList.add(labelDacSense8);
        labelDacSenseList.add(labelDacSense9);
        labelDacSenseList.add(labelDacSense10);
        labelDacSenseList.add(labelDacSense11);
        labelDacSenseList.add(labelDacSense12);
        labelDacSenseList.add(labelDacSense13);
        labelDacSenseList.add(labelDacSense14);
        labelDacSenseList.add(labelDacSense15);
        labelDacSenseList.add(labelDacSense16);
        labelDacSenseList.add(labelDacSense17);
        labelDacSenseList.add(labelDacSense18);

        // Labels
        for (int i = 0; i < __N_DACS; i++) {
            labelDacList.get(i).setText(m_SpidrDaq.dacName(i + 1));
        }

        // DACs chart
        dacsLineChart.setTitle("DAC scan");
        dacsLineChart.getXAxis().setAutoRanging(true);
        dacsLineChart.getXAxis().setLabel("DAC value");
        dacsLineChart.getYAxis().setAutoRanging(true);
        dacsLineChart.getYAxis().setLabel("Volts");
        dacsLineChart.setLegendVisible(true);
        //dacsLineChart.

    }

    public boolean DacStringValid(String s, Slider sl) {

        if (s.isEmpty()) {
            return false;
        }

        return true;
    }

    /**
     * Class constructor
     */
    public FXMLDocumentController() {

        initVars();

    }

    // my vars
    private TPX3DaqData m_Dacs;
    private SpidrDaqJ m_SpidrDaq;

}
