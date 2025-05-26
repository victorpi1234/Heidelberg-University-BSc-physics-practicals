[Timepix3_0]
type = "Timepix3"
number_of_pixels = 256,256
pixel_pitch = 55um,55um
position = 0mm,0mm,0mm
orientation = 9deg,189deg,0deg
orientation_mode = "xyz"
spatial_resolution = 4um, 4um
time_resolution = 1.56ns

# Add all other detectors here:
# -> Timepix3_(1-6) and ATLASpix_0
[Timepix3_1]
type = "Timepix3"
number_of_pixels = 256,256
pixel_pitch = 55um,55um
position = 0mm,0mm,21.5mm
orientation = 9deg,189deg,0deg
orientation_mode = "xyz"
spatial_resolution = 4um, 4um
time_resolution = 1.56ns

[Timepix3_2]
type = "Timepix3"
number_of_pixels = 256,256
pixel_pitch = 55um,55um
position = 0mm,0mm,43.5mm
orientation = 9deg,189deg,0deg
orientation_mode = "xyz"
spatial_resolution = 4um, 4um
time_resolution = 1.56ns

[ATLASpix_0]
type = "ATLASpix"
number_of_pixels = 25,400
pixel_pitch = 130um,40um
position = 0mm,0mm,105mm
orientation = 0deg,0deg,0deg
orientation_mode = "xyz"
spatial_resolution = 15.8713um, 15.8713um
time_resolution = 16ns
role = "DUT"

[Timepix3_3]
type = "Timepix3"
number_of_pixels = 256,256
pixel_pitch = 55um,55um
position = 0mm,0mm,186.5mm
orientation = 9deg,9deg,0deg
orientation_mode = "xyz"
spatial_resolution = 4um, 4um
time_resolution = 1.56ns
role = "reference"

[Timepix3_4]
type = "Timepix3"
number_of_pixels = 256,256
pixel_pitch = 55um,55um
position = 0mm,0mm,208mm
orientation = 9deg,9deg,0deg
orientation_mode = "xyz"
spatial_resolution = 4um, 4um
time_resolution = 1.56ns

[Timepix3_5]
type = "Timepix3"
number_of_pixels = 256,256
pixel_pitch = 55um,55um
position = 0mm,0mm,231.5mm
orientation = 9deg,9deg,0deg
orientation_mode = "xyz"
spatial_resolution = 4um, 4um
time_resolution = 1.56ns

[Timepix3_6]
type = "Timepix3"
number_of_pixels = 256,256
pixel_pitch = 55um,55um
position = 0mm,0mm,336.5mm
orientation = 9deg,9deg,0deg
orientation_mode = "xyz"
spatial_resolution = 4um, 4um
time_resolution = 1.56ns


# Tip:
# For the spatial resolution of the ATLASpix_0,
# assume a binary resolution (see manual):
