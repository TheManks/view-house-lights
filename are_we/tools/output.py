import serial
import time
import random
import wav_to_array as wav
import io
import PyCmdMessenger

port = '/dev/ttyACM0'
ard = PyCmdMessenger.ArduinoBoard(port, baud_rate=115200)
commands = [["setLed","i"]]
c = PyCmdMessenger.CmdMessenger(ard, commands)
c.send("setLed",50)


#sio = serial.Serial(port,115200)
#sio = io.TextIOWrapper(io.BufferedRWPair(ser, ser))
#time.sleep(5)

content = wav.parse()
for pos, i in enumerate(content):
    time.sleep(.01)
    c.send("setLed", i)
    print(i)
   

