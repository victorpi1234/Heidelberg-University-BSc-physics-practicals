// Important: The name of the file needs to
// be identical to the name of the function:
void chi_comparison() {

    // Define the name of the input files:
    string fileName1 = "../output/06_read_data.root";
    string fileName2 = "../output/07_read_data.root";

    // Open the files
    TFile *f1 = TFile::Open(fileName1.c_str());
    TFile *f2 = TFile::Open(fileName2.c_str());

    if (!f1 || !f2) {
        std::cerr << "Error: Could not open input files!" << std::endl;
        return;
    }

    // Set the histogram names (make sure they match exactly with TBrowser)
    string histName1 = "Tracking4D/trackChi2ndof";
    string histName2 = "Tracking4D/trackChi2ndof";

    // Read the histograms from the files
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    TH1F* h2 = static_cast<TH1F*>(f2->Get(histName2.c_str()));

    if (!h1 || !h2) {
        std::cerr << "Error: One or both histograms not found!" << std::endl;
        return;
    }

    // Create a new canvas
    TCanvas* c1 = new TCanvas("c1", "Chi^2/ndof Comparison", 1000, 600);

    // Set different colors for the histograms
    h1->SetLineColor(kRed);
    h2->SetLineColor(kBlue);

    // Adjust line widths for better visibility
    h1->SetLineWidth(2);
    h2->SetLineWidth(2);

    // Set histogram titles
    h1->SetTitle("#chi^{2}/ndof Comparison");
    h1->GetXaxis()->SetTitle("#chi^{2}/ndof");
    h1->GetYaxis()->SetTitle("Number of Events");

    // Draw the histograms
    h1->DrawNormalized();
    h2->DrawNormalized("SAME"); // Draw the second histogram on the same canvas

    // Add a legend
    TLegend *leg = new TLegend(0.7, 0.75, 0.9, 0.9);
    leg->AddEntry(h1, "After Alignment", "l");
    leg->AddEntry(h2, "Before Alignment", "l");
    leg->Draw();

    // Remove statistics box
    gStyle->SetOptStat(0);

    // Save the plot as PDF
    c1->SaveAs("PDFs/chi_comparison.pdf");
}
