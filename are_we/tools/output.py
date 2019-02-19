import serial
import time
import wav_to_array as wav
import io
import PyCmdMessenger

port = '/dev/ttyACM0'
ard = PyCmdMessenger.ArduinoBoard(port, baud_rate=115200)
commands = [["setLed","i"]]
c = PyCmdMessenger.CmdMessenger(ard, commands)
c.send("setLed",50)

content = wav.parse()
for pos, i in enumerate(content):
    time.sleep(.01)
    c.send("setLed", i)
    print(i)
   

