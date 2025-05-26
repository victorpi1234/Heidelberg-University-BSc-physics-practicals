
// Important: The name of the file needs to
// be identical to the name of the function:
void telescope_alignment() {

    // Define the name of the input file:
    // * "../output" means go into parent directory and then into 'output'
    string fileName = "../output/06_read_data.root";

    // Open the file
    TFile *f1 = TFile::Open(fileName.c_str());

    // Set the name of the histogram we want to draw:
    // * make sure that the name matches exactly to the one you see in the TBrowser
    string histName1 = "Tracking4D/Timepix3_0/residualsX";
    string histName2 = "Tracking4D/trackChi2ndof";

    // Read the histograms from the file and assign it to a variable called h1:
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(histName2.c_str()));


    // Create a new canvas (background to paint on, like when painting a portrait):
    // 1000, 600 defines the size
    TCanvas* c1 = new TCanvas("c1","c1",1000,600);

    // Split canvas into 2x1:
    c1->Divide(2,1);

    // Access first section on canvas:
    c1->cd(1);

    // Rename the histogram and the axis labels:
    h1->SetTitle("Timepix3_0 Residual X ");
    h1->GetXaxis()->SetTitle("x_{track}");
    h1->GetYaxis()->SetTitle("# events");

    // Draw the histogram:
    h1->Draw();

    // Change the y-axis to log scale:
    // gPad->SetLogy();

    // Remove the so-called stat box from the top right:
    gStyle->SetOptStat(1111);

    // Adjust margin so z-axis label is not cut off:
    gPad->SetRightMargin(0.13);

    // Access first section on canvas:
    c1->cd(2);

    // Rename the histogram and the axis labels:
    h2->SetTitle("Track #Chi^2/ndof");
    h2->GetXaxis()->SetTitle("#Chi^{2}/ndof");
    h2->GetYaxis()->SetTitle("# events");

    // Draw the histogram:
    h2->Draw();

    // Remove the so-called stat box from the top right:
    gStyle->SetOptStat(0);

    // Adjust margin so z-axis label is not cut off:
    gPad->SetRightMargin(0.13);

    // Save the canvas (i.e. everything drawn onto it) to PDF:
    c1->SaveAs("PDFs/telescope_alignment.pdf");
}
