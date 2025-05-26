#include <iostream>
#include "TFile.h"
#include "TH2F.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TStyle.h"

void _02_macro() {
    // Define the name of the input file
    std::string fileName = "../output/02_read_data.root";

    // Open the file and check if it exists
    TFile *f1 = TFile::Open(fileName.c_str());
    if (!f1 || f1->IsZombie()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return;
    }

    // Histogram names
    std::string histNames[] = {
        "EventLoaderTimepix3/Timepix3_0/hitMap",
        "EventLoaderTimepix3/Timepix3_1/hitMap",
        "EventLoaderTimepix3/Timepix3_2/hitMap",
        "EventLoaderTimepix3/Timepix3_3/hitMap",
        "EventLoaderTimepix3/Timepix3_4/hitMap",
        "EventLoaderTimepix3/Timepix3_5/hitMap",
        "EventLoaderTimepix3/Timepix3_6/hitMap",
        "EventLoaderATLASpix/ATLASpix_0/hitMap"
    };

    const int numHists = 8;  // Number of histograms
    TH2F* hists[numHists];    // Array to store histograms

    // Retrieve histograms and check for errors
    for (int i = 0; i < numHists; i++) {
        hists[i] = static_cast<TH2F*>(f1->Get(histNames[i].c_str()));
        if (!hists[i]) {
            std::cerr << "Error: Could not find histogram " << histNames[i] << std::endl;
            return;
        }
    }

   // Create a canvas and divide into 4x2 grid
    TCanvas* c1 = new TCanvas("c1", "Hit Maps", 1000, 600);
    c1->Divide(4, 2);

    // Draw histograms and add individual legends
    for (int i = 0; i < numHists; i++) {
        c1->cd(i + 1);
        hists[i]->SetTitle(histNames[i].c_str());
        hists[i]->GetXaxis()->SetTitle("Pixels");
        hists[i]->GetYaxis()->SetTitle("Pixels");
        hists[i]->Draw("colz");
        gPad->SetRightMargin(0.13);
        gPad->SetLogz(); // Use log scale for better visualization

        // Create individual legend for each histogram
        TLegend *leg = new TLegend(0.7, 0.75, 0.9, 0.9);
        leg->AddEntry(hists[i], histNames[i].c_str(), "l");
        leg->Draw();
    }

    // Save as PDF
    c1->SaveAs("PDFs/hitmaps.pdf");

    // Cleanup
    delete c1;
    f1->Close();
    delete f1;
}