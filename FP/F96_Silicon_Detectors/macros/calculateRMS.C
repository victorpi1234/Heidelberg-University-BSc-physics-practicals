void calculateRMS() {
    // Open the ROOT file containing the time residuals histogram
    TFile* file = TFile::Open("../output/10_read_data.root");  // Replace with your actual file
    if (!file) {
        std::cerr << "Error opening ROOT file!" << std::endl;
        return;
    }

    // Get the time residuals histogram (replace with actual histogram name)
    TH1F* hist = (TH1F*)file->Get("AnalysisDUT/ATLASpix_0/residualsTime");  // Replace with your actual histogram name
    if (!hist) {
        std::cerr << "Error: Histogram 'residualsTime' not found!" << std::endl;
        file->Close();
        return;
    }

    // Get the number of bins and total entries in the histogram
    int nBins = hist->GetNbinsX();
    double totalEntries = hist->Integral();

    // Variables to hold sum and squared sum for RMS calculation
    double sum = 0;         // Weighted sum for mean
    double squaredSum = 0;  // Weighted sum for squared terms

    // Loop over all bins to calculate the sum and squared sum
    for (int i = 1; i <= nBins; ++i) {
        double content = hist->GetBinContent(i);
        double center = hist->GetBinCenter(i);
        
        sum += content * center;  // Weighted sum for mean
        squaredSum += content * std::pow(center, 2);  // Weighted sum for squared terms
    }

    // Calculate the mean of the histogram
    double mean = sum / totalEntries;

    // Calculate RMS using the formula: sqrt(mean of squared terms - mean^2)
    double rms = std::sqrt(squaredSum / totalEntries - std::pow(mean, 2));

    // Print RMS result
    std::cout << "Calculated RMS of time residuals: " << rms << std::endl;

    // Optionally, draw the histogram and fit a Gaussian to visualize the distribution
    hist->SetTitle("Time Residuals for ATLASpix_Simple");
    hist->GetXaxis()->SetTitle("Time Residual (ns)");
    hist->GetYaxis()->SetTitle("Entries");
    hist->Draw();
    
    // Fit a Gaussian to the histogram and display the fit parameters
    TF1* gausFit = new TF1("gausFit", "gaus", hist->GetXaxis()->GetXmin(), hist->GetXaxis()->GetXmax());
    hist->Fit(gausFit, "Q");
    gausFit->Draw("same");

    // Close the ROOT file
    file->Close();
}
