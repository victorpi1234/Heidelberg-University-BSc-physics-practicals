// Important: The name of the file needs to
// be identical to the name of the function:
void ATLASpix_hitmaps() {

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
    string histName1 = "Correlations/ATLASpix_0/hitmap_clusters";
    string histName2 = "AnalysisDUT/ATLASpix_0/clusterMapAssoc";


    // Read the histograms from the files
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f1->Get(histName2.c_str()));

    // Create a new canvas with 2x2 divisions
    TCanvas* c1 = new TCanvas("c1", "Telescope Alignment", 2000, 1000);
    c1->Divide(2, 1);

    // Access first section on canvas
    c1->cd(1);
    h1->SetTitle("hitmap of clusters");
    h1->GetXaxis()->SetTitle("x [px]");
    h1->GetYaxis()->SetTitle("y [px]");
    h1->SetLineColor(kRed);
    h1->Draw();
    // Adjust margins
    gPad->SetRightMargin(0.13);

    // Access first section on canvas
    c1->cd(2);
    h2->SetTitle("Cluster Map Association");
    h2->GetXaxis()->SetTitle("cluster col");
    h2->GetYaxis()->SetTitle("cluster row");
    h2->SetLineColor(kRed);
    h2->Draw();
    // Adjust margins
    gPad->SetRightMargin(0.13);

    
    // Save the canvas to a PDF
    c1->SaveAs("PDFs/ATLASpix_hitmaps.pdf");
}
