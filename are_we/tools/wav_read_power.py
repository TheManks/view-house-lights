import matplotlib.pyplot as plt
import scipy.io.wavfile
import numpy as np
import time
from matplotlib import animation


rate, audio_data = scipy.io.wavfile.read("/home/larry/Downloads/Lube_-_Kombat-alejKZhngvg.wav")


audio_data = audio_data[0:88200]
mn = np.min(audio_data)
mx = np.max(audio_data)

output = ((audio_data-mn)*255.0) / (mx-mn)
output = [ int(x) for x in output ]

time = np.arange(0, float(audio_data.shape[0]), 1)/rate


plt.figure()
plt.plot(time, output, linewidth=0.1, alpha=1)
plt.show()
