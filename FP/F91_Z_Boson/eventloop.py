# Lines beginning with "#" are comments in python.
# Start your program by importing Root and some other handy modules
import ROOT 
import math
import sys
import os
import os.path
from ROOT import TF1, kPink


# The argparse module makes it easy to write user-friendly command-line interfaces. 
import argparse



# we add the flags -f and -n to the scripts, so we can pass arguments in the command line:
# e.g.   python eventloop.py -f someFile.root -n 10
parser = argparse.ArgumentParser(description='Analysis of Z events.')
parser.add_argument('-f', metavar='inputFile', type=str, nargs=1, help='Input ROOT file', required=True)
parser.add_argument('-n', metavar='numEvents', type=int, nargs=1, help='Number of events to process (default all)')

args = parser.parse_args()
fileName = str(args.f[0])
numEvents = -1
if args.n != None :
    numEvents = int(args.n[0])

# from now on, fileName contains the string with the path to our input file and 
# numEvents the integer of events we want to process



# Some ROOT global settings and styling
ROOT.TH1.SetDefaultSumw2()

# The execution starts here
print("Starting the analysis")

# Open the input file. The name can be hardcoded, or given from commandline as argument
myfile = None
if os.path.isfile(fileName) and os.access(fileName, os.R_OK):
    myfile = ROOT.TFile(fileName)
else:
    sys.exit("Error: Input file does not exist or is not readable")

print("Opened file %s"%myfile.GetName())

# Now you have access to everything you can also see by using the TBrowser
# Load the tree containing all the variables
myChain = ROOT.gDirectory.Get( 'mini' )

# Open an output file to save your histograms in (we build the filename such that it contains the name of the input file)
# RECREATE means, that an already existing file with this name would be overwritten
outfile = ROOT.TFile.Open("analysis_"+myfile.GetName().split('/')[-1], "RECREATE")
outfile.cd()

# Book histograms within the output file
hVertexDist        = ROOT.TH1D("hVertexDist",   "Distribution of the interaction vertex along the z-axis; z [mm]; Entries", 1000, -500, 500)
hlep_n        = ROOT.TH1D("hNLep",   "Number of leptons; n; Entries", 10000000, 0, 10)
hlep_pt = ROOT.TH1D("hptep",   "NTransverse impulse; n; Entries", 60000, 1000, 200000)
hinv_mass_manual   = ROOT.TH1D("hinv_mass_manual", "Invariant mass of leading two leptons; M [GeV]; Entries", 300,0,150)
hinv_mass_Lorentz  = ROOT.TH1D("hinv_mass_Lorentz","Lorentz invariant mass calculation; M [GeV]; Entries", 300,0,150)
hinv_mass_both= ROOT.THStack()


hlep_pt_numerator = ROOT.TH1D("hlep_pt_numerator",   "NTransverse impulse; pt; Entries", 25, 0, 200)
hlep_pt_denominator = ROOT.TH1D("hlep_pt_denominator",   "NTransverse impulse; pt; Entries", 25, 0, 200)

#Cut histogram
hCuts = ROOT.TH1D("hCuts", "Total number of events selected by the consecutive criteria; ; Events", 13, 0, 13)
hCuts.SetFillColor(3)
hCuts.SetMinimum(1) #in order for logarithm to work

# To look at each entry in the tree, loop over it.
# Either loop over a fixed amount of events, or over all entries (nEntries)
if numEvents<0:
    nEntries = myChain.GetEntriesFast()
else:
    nEntries = numEvents 

for jentry in range(0, nEntries):
    # python uses indention to show which code belongs into the loop. Thus, every line that should be executed within this loop should 
    # start with at least two spaces

    # print some info about already processed events
    if jentry % 100000 == 0:
        print("Processed", jentry, "/", nEntries, "events")
    
    nb = myChain.GetEntry(jentry)
    if nb <= 0: continue

    # will need to be changed for Monte Carlo events
    weight = 1

    
    # Read a variable from the input
    vertexZ = myChain.vxp_z
    lep_n = myChain.lep_n    
    lep_pt = myChain.lep_pt
    lep_eta=myChain.lep_eta
    lep_phi=myChain.lep_phi
    lep_E=myChain.lep_E
    
    
    for pt in  (lep_pt):
     hlep_pt.Fill(pt, weight)
    hVertexDist.Fill(vertexZ, weight)
    hlep_n.Fill(lep_n, weight)
    
    
    #Cuts
    hCuts.GetXaxis().SetBinLabel(1, "All")
    hCuts.GetXaxis().SetBinLabel(2, "Weights")
    hCuts.GetXaxis().SetBinLabel(3, "Trigger")
    hCuts.GetXaxis().SetBinLabel(4, "GRL")
    hCuts.GetXaxis().SetBinLabel(5, "Vertex")
    hCuts.GetXaxis().SetBinLabel(6, ">= 2 Leptons")
    hCuts.GetXaxis().SetBinLabel(7, "PDGID")
    hCuts.GetXaxis().SetBinLabel(8, "Charge")
    hCuts.GetXaxis().SetBinLabel(9, "p_T Cut")
    hCuts.GetXaxis().SetBinLabel(10, "E_T Isolation")
    hCuts.GetXaxis().SetBinLabel(11, "p_T Isolation")
    hCuts.GetXaxis().SetBinLabel(12, "Tight ID")
    hCuts.GetXaxis().SetBinLabel(13, "Z Mass")
    
    


    # Some entries are stored in vectors, meaning they have several entries themselves
    # another loop is needed for these objects
    # e.g.:
#    print "lep_pt:", myChain.lep_pt
#    print "lep_n:",   myChain.lep_n


    # might be helpful, to access all 32 bits of a 32 bit integer flag individually:

    # for bit in range ( 32 ):
    #     flagBit = lep_flag & (1 << bit)
    #     print flagBit
   
    
        #Cuts
    #Weights (change weights 0 to 1)    
    weight = myChain.mcWeight
    if weight ==0:
        weight = 1
    hCuts.Fill(0.5, 1)
    hCuts.Fill(1.5, weight)
    
    
    #Efficiency
    if lep_n == 2:
        hlep_pt_denominator.Fill(lep_pt[1]/1000 ,weight)
        lep_flag = myChain.lep_flag
        if lep_flag[1] >> 9 & 0x1:
            hlep_pt_numerator.Fill(lep_pt[1]/1000 ,weight)
   
    
    #Electron or muon trigger
    if myChain.trigE or myChain.trigM:
        hCuts.Fill(2.5, weight)
    else:
        continue
        
    #Good Run List (exclude data, collected when a part had malfunctioned)
    if myChain.passGRL:
        hCuts.Fill(3.5, weight)
    else:
        continue
    
    #Vertex (Checks the primary vertex)
    if myChain.hasGoodVertex:
        hCuts.Fill(4.5, weight)
    else:
        continue
    
    #2 Leptons (checks if at least two leptons have decayed)
    if myChain.lep_n>=2:
        hCuts.Fill(5.5, weight)
    else:
        continue        
        
        
    #PGID (We expect leptons to be electrons-11 or muons-13)
    lep_type = myChain.lep_type
    electron_muon = [11, 13]
    if lep_type[0] == lep_type[1]: # An electron-muon pair cannot be produced
        if lep_type[0] == electron_muon[0] or lep_type[0] == electron_muon[1]:
            hCuts.Fill(6.5, weight)
        else:
            continue
    else:
        continue
     
    #Charge (lepton pair has to be with opposite charges)
    lep_charge = myChain.lep_charge
    if lep_charge[0] == -lep_charge[1]:
        hCuts.Fill(7.5, weight)
    else:
        continue
    
    #p_T cut (Momentum values of at least 25GeV are expected)
    if lep_pt[0] > 25000:
        if lep_pt[1] > 25000:
            hCuts.Fill(8.5, weight)
        else:
            continue
    else:
        continue
    
    
    #Isolation (compare ransverse energy (momentum) in cone to the it, but carried by the lepton)
    lep_ptcone30 = myChain.lep_ptcone30
    lep_etcone20 = myChain.lep_etcone20
    
    E_cutoff = 1
    if lep_etcone20[0] / lep_E[0] <= E_cutoff: 
        if lep_etcone20[1] / lep_E[1] <= E_cutoff:
            hCuts.Fill(9.5, weight)
        else:
            continue
    else:
        continue

    p_cutoff = 1
    if lep_ptcone30[0] / lep_pt[0] <= p_cutoff: 
        if lep_ptcone30[1] / lep_pt[1] <= p_cutoff:
            hCuts.Fill(10.5, weight)
        else:
            continue
    else:
        continue
    
    #Tight ID
    lep_flag = myChain.lep_flag
    tight_1 = lep_flag[0] >> 9 & 0x1  
    if lep_flag[1] >> 9 & 0x1:
        tight = tight_1 
    else:
        continue
    if tight:
        hCuts.Fill(11.5, weight)
    else:
        continue
        
      

    #Invariant mass
    #Manual
    if lep_n >1:
        M_m = math.sqrt(abs(2*lep_pt[0] * lep_pt[1] * ( math.cosh(lep_eta[0] - lep_eta[1]) - math.cos(lep_phi[0] - lep_phi[1]) )))/1000
    #Lorentz

        p0 = ROOT.TLorentzVector() 
        p1 = ROOT.TLorentzVector() 
        
        p1.SetPtEtaPhiE(lep_pt[1], lep_eta[1], lep_phi[1], lep_E[1]) 
        p0.SetPtEtaPhiE(lep_pt[0], lep_eta[0], lep_phi[0], lep_E[0]) 
        p = p0 + p1
        M_l = p.M()/1000     

        hinv_mass_manual.Fill(M_m, weight) 
        hinv_mass_Lorentz.Fill(M_l, weight)
        
        
    # restrict Z-Boson mass to (61, 121)GeV
    if M_l> 61 and M_l < 121:
        hCuts.Fill(12.5, weight)
    else:
        continue
     
        
##########################################################################
#end of the event loop
##########################################################################


### The Wrap-up code (writing the files, etc) goes here
# Let's look at the histogram; create a canvas to draw it on
canvas = ROOT.TCanvas("myCanvas", 'Analysis Plots', 200, 10, 700, 500 )
canvas.cd()
hVertexDist.Draw()
canvas.SaveAs("HVertexdist.png")
#########################################################################lep_flag = myChain.lep_flag
hCuts.Draw("hist")
canvas.SaveAs("cuts.png")

canvas.SetLogy(0)
hlep_pt_numerator.Divide(hlep_pt_denominator)
hlep_pt_numerator.SetLineColor(0)
hlep_pt_numerator.SetMarkerStyle(20) #circle
hlep_pt_numerator.SetMarkerColor(3)
hlep_pt_numerator.SetMarkerSize(1.5)
hlep_pt_numerator.SetMaximum(1.2)
hlep_pt_numerator.SetMinimum(0.6)
hlep_pt_numerator.Draw("PE") #polymarker and errorbar
canvas.SaveAs("Efficiency.png")

outfile.cd()
print("Writing output to %s"%outfile.GetName())
outfile.Write()

#useful command to pause the execution of the code. Allows to see the plot before python finishes
#ROOT.TPython.Prompt()
# MW: 1/9/2022: Caution here. In a multi-python build, libROOTTPython is only built for the highest 
# Python version. Bottomline: if you run TPython from Python, make sure your Python version is the 
# one that TPython was built for. Hence, instead we use standard python now instead.
usr_input = input ("Press any key to continue ")
