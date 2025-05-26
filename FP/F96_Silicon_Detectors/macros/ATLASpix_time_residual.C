// Important: The name of the file needs to
// be identical to the name of the function:
void ATLASpix_time_residual() {

    // Define the name of the input files:
    string fileName1 = "../output/10_read_data.root";
    // string fileName2 = "../output/07_read_data.root";

    // Open the files
    TFile *f1 = TFile::Open(fileName1.c_str());
    // TFile *f2 = TFile::Open(fileName2.c_str());

    // Set the name of the histogram we want to draw:
    string histName1 = "AnalysisDUT/ATLASpix_0/residualsTime";
    // string histName2 = "Tracking4D/trackChi2ndof";

    // Read the histograms from the files
    TH1F* h1 = static_cast<TH1F*>(f1->Get(histName1.c_str()));
    // TH1F* h2 = static_cast<TH1F*>(f2->Get(histName2.c_str()));


    // Create a new canvas with 2x2 divisions
    TCanvas* c1 = new TCanvas("c1", "Telescope Alignment", 1000, 1000);
    // c1->Divide(2, 2);

    // Access first section on canvas
    // c1->cd(1);
    h1->SetTitle("Gaussian fit to time residual");
    h1->GetXaxis()->SetTitle("time [ns]");
    h1->GetYaxis()->SetTitle("# events");
    h1->SetLineColor(kRed);
    h1->Draw();

    // Perform Gaussian fit on the first histogram
    TF1 *gausFit = new TF1("gausFit", "gaus");
    h1->Fit(gausFit, "Q");
    gausFit->Draw("same");

    // Display fit parameters on the plot
    TPaveText *pt = new TPaveText(0.6, 0.6, 0.9, 0.8, "NDC");
    pt->AddText(Form("Mean: %.3f", gausFit->GetParameter(1)));
    pt->AddText(Form("Sigma: %.3f", gausFit->GetParameter(2)));
    pt->Draw();

    // Adjust margins
    gPad->SetRightMargin(0.13);
    gStyle->SetOptStat(0);

    // Save the canvas to a PDF
    c1->SaveAs("PDFs/ATLASpix_time_residual.pdf");
}
