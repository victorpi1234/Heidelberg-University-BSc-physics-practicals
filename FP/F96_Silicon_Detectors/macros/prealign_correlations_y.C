
// Important: The name of the file needs to
// be identical to the name of the function:
void prealign_correlations_y() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName = "../output/04_read_data.root";
    string fileName2 = "../output/05_read_data_prealign.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName.c_str());
    TFile *f2 = TFile::Open(fileName2.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName1 = "Correlations/Timepix3_0/correlationY";
    string histName2 = "Correlations/Timepix3_1/correlationY";
    string histName3 = "Correlations/Timepix3_2/correlationY";
    string histName4 = "Correlations/Timepix3_3/correlationY";
    string histName5 = "Correlations/Timepix3_4/correlationY";
    string histName6 = "Correlations/Timepix3_5/correlationY";
    string histName7 = "Correlations/Timepix3_6/correlationY";

    string histName8 = "Correlations/Timepix3_0/correlationY";
    string histName9 = "Correlations/Timepix3_1/correlationY";
    string histName10 = "Correlations/Timepix3_2/correlationY";
    string histName11 = "Correlations/Timepix3_3/correlationY";
    string histName12 = "Correlations/Timepix3_4/correlationY";
    string histName13 = "Correlations/Timepix3_5/correlationY";
    string histName14 = "Correlations/Timepix3_6/correlationY";
    
    

    // Read the histograms from the file and assign it to a variable called h14:
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(histName2.c_str()));
    TH1F* h3 = static_cast<TH1F*>(f1->Get(histName3.c_str()));
    TH1F* h4 = static_cast<TH1F*>(f1->Get(histName4.c_str()));
    TH1F* h5 = static_cast<TH1F*>(f1->Get(histName5.c_str()));
    TH1F* h6 = static_cast<TH1F*>(f1->Get(histName6.c_str()));
    TH1F* h7 = static_cast<TH1F*>(f1->Get(histName7.c_str()));

    TH1F* h8 = static_cast<TH1F*>(f2->Get(histName8.c_str()));
    TH1F* h9 = static_cast<TH1F*>(f2->Get(histName9.c_str()));
    TH1F* h10 = static_cast<TH1F*>(f2->Get(histName10.c_str()));
    TH1F* h11 = static_cast<TH1F*>(f2->Get(histName11.c_str()));
    TH1F* h12 = static_cast<TH1F*>(f2->Get(histName12.c_str()));
    TH1F* h13 = static_cast<TH1F*>(f2->Get(histName13.c_str()));
    TH1F* h14 = static_cast<TH1F*>(f2->Get(histName14.c_str()));

    if (!h1) {
    std::cerr << "Error: Histogram " << histName1 << " not found!" << std::endl;
    return;
    }
    if (!h2) {
    std::cerr << "Error: Histogram " << histName2 << " not found!" << std::endl;
    return;
    }

    // Create a new canvas (background to paint on, like when painting a portrait):
    // 1000, 600 defines the size
    TCanvas* c1 = new TCanvas("c1","c1",1000,4000);

    // Split canvas into 2x2:
    c1->Divide(2,7);

        // Access first section on canvas:
        c1->cd(1);


            // Rename the histogram and the axis labels:
            h1->SetTitle("Timepix3_0 initial correlations");
            h1->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
            h1->GetYaxis()->SetTitle("# events");

            // Change line color:
            // * see here for all available colors:
            // * https://root.cern.ch/doc/master/classTColor.html
            h1->SetLineColor(kRed);

            // Draw the histogram:
            h1->Draw();

            // Change the y-axis to log scale:
            // gPad->SetLogy();

            // Remove the so-called stat box from the top right:
            gStyle->SetOptStat(0);

            // Adjust margin so z-axis label is not cut off:
            gPad->SetRightMargin(0.13);

        c1->cd(3);

                // Rename the histogram and the axis labels:
                h2->SetTitle("Timepix3_1 initial correlations");
                h2->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
                h2->GetYaxis()->SetTitle("# events");

                // Change line color:
                // * see here for all available colors:
                // * https://root.cern.ch/doc/master/classTColor.html
                h2->SetLineColor(kRed);

                // Draw the histogram:
                h2->Draw();

                // Change the y-axis to log scale:
                // gPad->SetLogy();

                // Remove the so-called stat box from the top right:
                gStyle->SetOptStat(0);

                // Adjust margin so z-axis label is not cut off:
                gPad->SetRightMargin(0.13);

        c1->cd(5);

                // Rename the histogram and the axis labels:
                h3->SetTitle("Timepix3_2 initial correlations");
                h3->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
                h3->GetYaxis()->SetTitle("# events");

                // Change line color:
                // * see here for all available colors:
                // * https://root.cern.ch/doc/master/classTColor.html
                h3->SetLineColor(kRed);

                // Draw the histogram:
                h3->Draw();

                // Change the y-axis to log scale:
                // gPad->SetLogy();

                // Remove the so-called stat box from the top right:
                gStyle->SetOptStat(0);

                // Adjust margin so z-axis label is not cut off:
                gPad->SetRightMargin(0.13);

        c1->cd(7);

                // Rename the histogram and the axis labels:
                h4->SetTitle("Timepix3_3 initial correlations");
                h4->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
                h4->GetYaxis()->SetTitle("# events");

                // Change line color:
                // * see here for all available colors:
                // * https://root.cern.ch/doc/master/classTColor.html
                h4->SetLineColor(kRed);

                // Draw the histogram:
                h4->Draw();

                // Change the y-axis to log scale:
                // gPad->SetLogy();

                // Remove the so-called stat box from the top right:
                gStyle->SetOptStat(0);

                // Adjust margin so z-axis label is not cut off:
                gPad->SetRightMargin(0.13);

        c1->cd(9);

                // Rename the histogram and the axis labels:
                h5->SetTitle("Timepix3_4 initial correlations");
                h5->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
                h5->GetYaxis()->SetTitle("# events");

                // Change line color:
                // * see here for all available colors:
                // * https://root.cern.ch/doc/master/classTColor.html
                h5->SetLineColor(kRed);

                // Draw the histogram:
                h5->Draw();

                // Change the y-axis to log scale:
                // gPad->SetLogy();

                // Remove the so-called stat box from the top right:
                gStyle->SetOptStat(0);

                // Adjust margin so z-axis label is not cut off:
                gPad->SetRightMargin(0.13);

        c1->cd(11);

                // Rename the histogram and the axis labels:
                h6->SetTitle("Timepix3_5 initial correlations");
                h6->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
                h6->GetYaxis()->SetTitle("# events");

                // Change line color:
                // * see here for all available colors:
                // * https://root.cern.ch/doc/master/classTColor.html
                h6->SetLineColor(kRed);

                // Draw the histogram:
                h6->Draw();

                // Change the y-axis to log scale:
                // gPad->SetLogy();

                // Remove the so-called stat box from the top right:
                gStyle->SetOptStat(0);

                // Adjust margin so z-axis label is not cut off:
                gPad->SetRightMargin(0.13);

        c1->cd(13);

            // Rename the histogram and the axis labels:
            h7->SetTitle("Timepix3_6 initial correlations");
            h7->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
            h7->GetYaxis()->SetTitle("# events");

            // Change line color:
            // * see here for all available colors:
            // * https://root.cern.ch/doc/master/classTColor.html
            h7->SetLineColor(kRed);

            // Draw the histogram:
            h7->Draw();

            // Change the y-axis to log scale:
            // gPad->SetLogy();

            // Remove the so-called stat box from the top right:
            gStyle->SetOptStat(0);

            // Adjust margin so z-axis label is not cut off:
            gPad->SetRightMargin(0.13);



        // Access first section on canvas:
        c1->cd(2);


            // Rename the histogram and the axis labels:
            h8->SetTitle("Timepix3_0 initial correlations");
            h8->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
            h8->GetYaxis()->SetTitle("# events");

            // Change line color:
            // * see here for all available colors:
            // * https://root.cern.ch/doc/master/classTColor.html
            h8->SetLineColor(kRed);

            // Draw the histogram:
            h8->Draw();

            // Change the y-axis to log scale:
            // gPad->SetLogy();

            // Remove the so-called stat box from the top right:
            gStyle->SetOptStat(0);

            // Adjust margin so z-axis label is not cut off:
            gPad->SetRightMargin(0.13);

        c1->cd(4);

                // Rename the histogram and the axis labels:
                h9->SetTitle("Timepix3_1 initial correlations");
                h9->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
                h9->GetYaxis()->SetTitle("# events");

                // Change line color:
                // * see here for all available colors:
                // * https://root.cern.ch/doc/master/classTColor.html
                h9->SetLineColor(kRed);

                // Draw the histogram:
                h9->Draw();

                // Change the y-axis to log scale:
                // gPad->SetLogy();

                // Remove the so-called stat box from the top right:
                gStyle->SetOptStat(0);

                // Adjust margin so z-axis label is not cut off:
                gPad->SetRightMargin(0.13);

        c1->cd(6);

                // Rename the histogram and the axis labels:
                h10->SetTitle("Timepix3_2 initial correlations");
                h10->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
                h10->GetYaxis()->SetTitle("# events");

                // Change line color:
                // * see here for all available colors:
                // * https://root.cern.ch/doc/master/classTColor.html
                h10->SetLineColor(kRed);

                // Draw the histogram:
                h10->Draw();

                // Change the y-axis to log scale:
                // gPad->SetLogy();

                // Remove the so-called stat box from the top right:
                gStyle->SetOptStat(0);

                // Adjust margin so z-axis label is not cut off:
                gPad->SetRightMargin(0.13);

        c1->cd(8);

                // Rename the histogram and the axis labels:
                h11->SetTitle("Timepix3_3 initial correlations");
                h11->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
                h11->GetYaxis()->SetTitle("# events");

                // Change line color:
                // * see here for all available colors:
                // * https://root.cern.ch/doc/master/classTColor.html
                h11->SetLineColor(kRed);

                // Draw the histogram:
                h11->Draw();

                // Change the y-axis to log scale:
                // gPad->SetLogy();

                // Remove the so-called stat box from the top right:
                gStyle->SetOptStat(0);

                // Adjust margin so z-axis label is not cut off:
                gPad->SetRightMargin(0.13);

        c1->cd(10);

                // Rename the histogram and the axis labels:
                h12->SetTitle("Timepix3_4 initial correlations");
                h12->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
                h12->GetYaxis()->SetTitle("# events");

                // Change line color:
                // * see here for all available colors:
                // * https://root.cern.ch/doc/master/classTColor.html
                h12->SetLineColor(kRed);

                // Draw the histogram:
                h12->Draw();

                // Change the y-axis to log scale:
                // gPad->SetLogy();

                // Remove the so-called stat box from the top right:
                gStyle->SetOptStat(0);

                // Adjust margin so z-axis label is not cut off:
                gPad->SetRightMargin(0.13);

        c1->cd(12);

                // Rename the histogram and the axis labels:
                h13->SetTitle("Timepix3_5 initial correlations");
                h13->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
                h13->GetYaxis()->SetTitle("# events");

                // Change line color:
                // * see here for all available colors:
                // * https://root.cern.ch/doc/master/classTColor.html
                h13->SetLineColor(kRed);

                // Draw the histogram:
                h13->Draw();

                // Change the y-axis to log scale:
                // gPad->SetLogy();

                // Remove the so-called stat box from the top right:
                gStyle->SetOptStat(0);

                // Adjust margin so z-axis label is not cut off:
                gPad->SetRightMargin(0.13);

        c1->cd(14);

            // Rename the histogram and the axis labels:
            h14->SetTitle("Timepix3_6 initial correlations");
            h14->GetYaxis()->SetTitle("$x_{ref}$ [mm]");
            h14->GetYaxis()->SetTitle("# events");

            // Change line color:
            // * see here for all available colors:
            // * https://root.cern.ch/doc/master/classTColor.html
            h14->SetLineColor(kRed);

            // Draw the histogram:
            h14->Draw();

            // Change the y-axis to log scale:
            // gPad->SetLogy();

            // Remove the so-called stat box from the top right:
            gStyle->SetOptStat(0);

            // Adjust margin so z-axis label is not cut off:
            gPad->SetRightMargin(0.13);

// Save the canvas (i.e. everything drawn onto it) to PDF:
c1->SaveAs("PDFs/comparison_correlations_y.pdf");
}
