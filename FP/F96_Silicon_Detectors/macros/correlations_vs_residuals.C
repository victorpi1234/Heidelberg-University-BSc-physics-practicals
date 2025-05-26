// Important: The name of the file needs to
// be identical to the name of the function:
void correlations_vs_residuals() {

    // Define the name of the input files:
    string fileName = "../output/05_read_data_prealign.root";
    string fileName2 = "../output/06_read_data.root";

    // Open the files
    TFile *f1 = TFile::Open(fileName.c_str());
    TFile *f2 = TFile::Open(fileName2.c_str());

    // Check if files opened correctly
    if (!f1 || f1->IsZombie()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return;
    }
    if (!f2 || f2->IsZombie()) {
        std::cerr << "Error: Could not open file " << fileName2 << std::endl;
        return;
    }

    // Create a new canvas (background to paint on):
    TCanvas* c1 = new TCanvas("c1", "c1", 1400, 1400);
    c1->Divide(2, 7); // Create a 2-column, 7-row grid

    for (int i = 0; i <= 6; i++) {
        // Construct histogram names dynamically
        string histName1 = "Correlations/Timepix3_" + std::to_string(i) + "/correlationX";
        string histName2 = "Tracking4D/Timepix3_" + std::to_string(i) + "/residualsX";

        // Read histograms from file
        TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
        TH1F* h2 = static_cast<TH1F*>(f2->Get(histName2.c_str()));

        if (!h1) {
            std::cerr << "Error: Histogram " << histName1 << " not found!" << std::endl;
            continue;
        }
        if (!h2) {
            std::cerr << "Error: Histogram " << histName2 << " not found!" << std::endl;
            continue;
        }

        // Plot correlation histogram
        c1->cd(2 * i + 1);
        h1->SetTitle(("Timepix3_" + std::to_string(i) + " correlations X").c_str());
        h1->GetXaxis()->SetTitle("x_{ref} [mm]");
        h1->GetYaxis()->SetTitle("# events");
        h1->SetLineColor(kRed);
        h1->Draw();
        gStyle->SetOptStat(0);

        // Plot residuals histogram
        c1->cd(2 * i + 2);
        h2->SetTitle(("Timepix3_" + std::to_string(i) + " residuals X").c_str());
        h2->GetXaxis()->SetTitle("x_{track} [mm]");
        h2->GetYaxis()->SetTitle("# events");
        h2->SetLineColor(kRed);
        h2->Draw();
        gStyle->SetOptStat(0);
    }

    // Adjust margin so z-axis label is not cut off:
    gPad->SetRightMargin(0.13);

    // Save the canvas to PDF:
    c1->SaveAs("PDFs/residuals_vs_correlations.pdf");
}
