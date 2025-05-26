void ATLASpix_spatial_residuals() {
    // Define the name of the input files:
    string fileName1 = "../output/10_read_data.root";
    string fileName2 = "../output/09_read_data_aligned.root";

    // Open the files
    TFile *f1 = TFile::Open(fileName1.c_str());
    TFile *f2 = TFile::Open(fileName2.c_str());

    // Check if files opened correctly
    if (!f1 || f1->IsZombie()) {
        std::cerr << "Error: Could not open file " << fileName1 << std::endl;
        return;
    }
    if (!f2 || f2->IsZombie()) {
        std::cerr << "Error: Could not open file " << fileName2 << std::endl;
        return;
    }

    // Set the name of the histogram we want to draw:
    string histName1 = "AnalysisDUT/ATLASpix_0/residualsX";
    string histName2 = "AnalysisDUT/ATLASpix_0/residualsY";

    // Read the histograms from the files
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(histName2.c_str()));

    // Create a new canvas
    TCanvas* c1 = new TCanvas("c1", "Telescope Alignment", 1000, 1000);

    // Customize histograms
    h1->SetTitle("residuals");
    h1->GetXaxis()->SetTitle("y/x_{track} [mm]");
    h1->GetYaxis()->SetTitle("number of events");
    h1->SetLineColor(kRed);

    // Set fixed y-axis range (0 to 120)
    h1->SetMinimum(0);
    h1->SetMaximum(120);
    h2->SetMinimum(0);
    h2->SetMaximum(120);

    // Draw histograms
    h1->Draw();
    h2->Draw("same");

    // Adjust margins and disable stats box
    gPad->SetRightMargin(0.13);
    gStyle->SetOptStat(0);

    // Save the canvas to a PDF
    c1->SaveAs("PDFs/ATLASpix_spatial_residuals.pdf");
}
