// Important: The name of the file needs to
// be identical to the name of the function:
void ATLASpix_residuals() {

    // Define the name of the input files:
    string fileName1 = "../output/09_read_data.root";
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
    string histName1 = "AlignmentDUTResidual/ATLASpix_0/residualsX";
    string histName2 = "AnalysisDUT/ATLASpix_0/residualsX";
    string histName3 = "AlignmentDUTResidual/ATLASpix_0/residualsY";
    string histName4 = "AnalysisDUT/ATLASpix_0/residualsY";

    // Read the histograms from the files
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f2->Get(histName2.c_str()));
    TH1F* h3 = static_cast<TH1F*>(f1->Get(histName3.c_str()));
    TH1F* h4 = static_cast<TH1F*>(f2->Get(histName4.c_str()));

    // Create a new canvas with 2x2 divisions
    TCanvas* c1 = new TCanvas("c1", "Telescope Alignment", 1000, 1000);
    c1->Divide(2, 2);

    // Access first section on canvas
    c1->cd(1);
    h1->SetTitle("Initial Resdiduals X");
    h1->GetXaxis()->SetTitle("x_{track}");
    h1->GetYaxis()->SetTitle("# events");
    h1->SetLineColor(kRed);
    h1->Draw();
    // Adjust margins
    gPad->SetRightMargin(0.13);

    // Access first section on canvas
    c1->cd(2);
    h2->SetTitle("Final Resdiduals X");
    h2->GetXaxis()->SetTitle("x_{track}");
    h2->GetYaxis()->SetTitle("# events");
    h2->SetLineColor(kRed);
    h2->Draw();
    // Adjust margins
    gPad->SetRightMargin(0.13);

    // Access first section on canvas
    c1->cd(3);
    h3->SetTitle("Initial Resdiduals Y");
    h3->GetXaxis()->SetTitle("x_{track}");
    h3->GetYaxis()->SetTitle("# events");
    h3->SetLineColor(kRed);
    h3->Draw();
    // Adjust margins
    gPad->SetRightMargin(0.13);

    // Access first section on canvas
    c1->cd(4);
    h4->SetTitle("Final Resdiduals Y");
    h4->GetXaxis()->SetTitle("x_{track}");
    h4->GetYaxis()->SetTitle("# events");
    h4->SetLineColor(kRed);
    h4->Draw();
    // Adjust margins
    gPad->SetRightMargin(0.13);

    // Save the canvas to a PDF
    c1->SaveAs("PDFs/ATLASpix_residuals.pdf");
}
