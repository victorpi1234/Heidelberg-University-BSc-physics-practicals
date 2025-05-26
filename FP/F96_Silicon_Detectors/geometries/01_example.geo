[Timepix3_0]
type = "Timepix3"                  # Detector type
number_of_pixels = 256,256         # Size of the pixel matrix
pixel_pitch = 55um,55um            # Size of each pixel
position = 0mm,0mm,0mm             # Position in space. The beam travels along the z-axis.
orientation = 9deg,189deg,0deg     # Rotational orientation in space
 orientation_mode = "xyz"          # Right-handed coordinate system. The beam travels along the positive z-axis.
spatial_resolution = 4um, 4um      # Used as uncertainty on the cluster position
time_resolution = 1.56ns           # Used as uncertainty on the cluster timestamp
role = "reference"                 # This detector will be the reference for correlations and the alignment
