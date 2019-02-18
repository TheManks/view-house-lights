import matplotlib.pyplot as plt
import numpy as np
import scipy.io.wavfile
import time
import math


def parse():
    rate, audio_data = scipy.io.wavfile.read("/home/pi/Development/view-house-lights/are_we/tools/lowered.wav")
    tt = audio_data.shape[0] / rate
    print("Total time of piece is: {}secs".format(tt))

    # grab a smaller portion of our audio
    amount = 60*rate
    audio_data = audio_data[(120*rate):(120*rate)+amount]

    # int16 -> int32. Else overflow
    audio_data = audio_data.astype(np.int32)

    mn = np.min(audio_data)
    mx = np.max(audio_data)
    
    # Stopping here gives a direct conversion of the -32xxx:32xxx
    # range onto the range 0:255
    output = ((audio_data-mn)*255.0) / (mx-mn)


    amplitude = [(x-127)/255.0 for x in output]
    dB = [(20*math.log10(abs(a))) for a in amplitude]
    
    dbmn = np.min(dB)
    dbmx = np.max(dB)
    
    # Naive relative decibal calculation
    output = ((dB-dbmn)*255.0) / (dbmx-dbmn)
    
    # Need that in an int
    output = [ int(x) for x in output ]
    
    return output




