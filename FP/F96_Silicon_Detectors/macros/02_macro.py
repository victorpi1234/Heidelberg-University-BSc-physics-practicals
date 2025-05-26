# The script runs to completion and the Python process is terminated, 
# so the generated canvas disappears. If you want to keep the Python 
# process alive and thus inspect your canvas, execute the script with:
# python -i example.py

import ROOT

# Set some style parameters to make the plots prettier
ROOT.gStyle.SetTitleSize(0.055, "xyz")
ROOT.gStyle.SetLabelSize(0.045, "xyz")
ROOT.gStyle.SetTitleOffset(1.2,"xyz")
ROOT.gStyle.SetLabelOffset(0.010)
ROOT.gStyle.SetPadTopMargin(0.05)
ROOT.gStyle.SetPadRightMargin(0.05) 
ROOT.gStyle.SetPadBottomMargin(0.16)
ROOT.gStyle.SetPadLeftMargin(0.14)
ROOT.gStyle.SetOptTitle(0)
ROOT.gStyle.SetOptStat("emr")
ROOT.gStyle.SetPadTickX(1)
ROOT.gStyle.SetPadTickY(1)
ROOT.gStyle.SetStatFontSize(0.045)
ROOT.gStyle.SetStatX(0.9)
ROOT.gStyle.SetStatY(0.9)
ROOT.gStyle.SetStatW(0.25)
ROOT.gStyle.SetStatH(0.15)

# Apply the style
ROOT.gROOT.ForceStyle()

# Open the file
# '../output' means go into the parent directory and then into 'output'
inFile = ROOT.TFile("../output/01_example.root")

# Read the histogram we want to draw
# make sure that the name matches exactly to the one you see in the TBrowser
h1 = inFile.Get("EventLoaderTimepix3/Timepix3_0/hitMap")
h2 = inFile.Get("EventLoaderTimepix3/Timepix3_1/hitMap")
h3 = inFile.Get("EventLoaderTimepix3/Timepix3_2/hitMap")
h4 = inFile.Get("EventLoaderTimepix3/Timepix3_3/hitMap")
h5 = inFile.Get("EventLoaderTimepix3/Timepix3_4/hitMap")
h6 = inFile.Get("EventLoaderTimepix3/Timepix3_5/hitMap")
h7 = inFile.Get("EventLoaderTimepix3/Timepix3_6/hitMap")
h8 = inFile.Get("EventLoaderATASpix/ATLASpix_0/hitMap")

################
# 1D Histogram #
################

# Create a new canvas (background to paint on)
# 900, 600 defines the size
c1 = ROOT.TCanvas("c1", "c1", 900, 600)

# Set the axis labels
h1.GetXaxis().SetTitle("PixelToT [lsb]")
h1.GetYaxis().SetTitle("Entries")

# Change the line color
# See https://root.cern.ch/doc/master/classTColor.html
# for all available colors
h1.SetLineColor(ROOT.kRed)

# Change the fill color and alpha (transparency)
h1.SetFillColorAlpha(ROOT.kRed, 0.5)

# Draw the histogram
h1.Draw()

# Create a legend
legend = ROOT.TLegend(0.65, 0.7, 0.9, 0.75)

# Add entries to the legend
legend.AddEntry(h1, "Timepix3_0")

# Draw the legend
legend.Draw()

# Trigger the drawing of the canvas
c1.Update()

# Save the plot
c1.Print("PDFs/example_c1.pdf")

################
# 2D Histogram #
################

# Create a second canvas
c2 = ROOT.TCanvas("c2", "c2", 900, 600)

# Draw the second histogram
# The option 'colz' draw the histogram with a color scale
# See https://root.cern/doc/master/classTHistPainter.html
# for all histogram drawing options
h2.Draw("colz")

# Set the right margin such that colorbar label isn't cut off
c2.SetRightMargin(0.18)

# Disable the statistics box
ROOT.gStyle.SetOptStat(0)

# Trigger the drawing of the canvas
c2.Update()

# Save the plot
c2.Print("PDFs/example_c2.pdf")
