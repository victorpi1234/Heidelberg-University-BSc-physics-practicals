
// Important: The name of the file needs to
// be identical to the name of the function:
void trackChi2ndof() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName = "../output/06_read_data.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName1 = "Tracking4D/trackChi2ndof";

    // Read the histograms from the file and assign it to a variable called h1:
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));

    if (!h1) {
    std::cerr << "Error: Histogram " << histName1 << " not found!" << std::endl;
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
    h1->SetTitle("Track #Chi^{2}/ndof");
    h1->GetXaxis()->SetTitle(" #Chi^{2}/ndof");
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
    gStyle->SetOptStat(111111);


     

    // Adjust margin so z-axis label is not cut off:
    gPad->SetRightMargin(0.13);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("PDFs/clusterTot.pdf");
}
