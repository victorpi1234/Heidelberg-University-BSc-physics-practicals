
// Important: The name of the file needs to
// be identical to the name of the function:
void clustering4D_macro() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName = "../output/03_read_data.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName1 = "Clustering4D/Timepix3_2/clusterSize";
    string histName2 = "Clustering4D/ATLASpix_0/clusterSize";

    // Read the histograms from the file and assign it to a variable called h1:
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(histName2.c_str()));

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
    TCanvas* c1 = new TCanvas("c1","c1",1000,600);

    // Split canvas into 2x1:
    // c1->Divide(2,1);

    // Access first section on canvas:
    // c1->cd(1);

    // Rename the histogram and the axis labels:
    h1->SetTitle("Timepix3_2 and ATLASpix_0 Cluster size");
    h1->GetXaxis()->SetTitle("cluster size");
    h1->GetYaxis()->SetTitle("# events");

    // Change line color:
    // * see here for all available colors:
    // * https://root.cern.ch/doc/master/classTColor.html
    h1->SetLineColor(kRed);
    h2->SetLineColor(kBlue);

    // Draw the histogram:
    h1->Draw();
    h2->Draw("same");

    // Change the y-axis to log scale:
    // gPad->SetLogy();

    // Remove the so-called stat box from the top right:
    gStyle->SetOptStat(0);

    // Create a legend:
    //         This defines the position: (xmin, ymin, xmax, ymax)
    TLegend *leg = new TLegend(0.6,0.7,0.9,0.9);
    //                 This defines the text in the legend:
    leg->AddEntry(h1,"sensor: Timepix3_2");
    leg->AddEntry(h2,"sensor: ATLASpix_0");
    // Draw the legend:
    leg->Draw();

     

    // Adjust margin so z-axis label is not cut off:
    gPad->SetRightMargin(0.13);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("PDFs/cluster_size_comparison.pdf");
}
