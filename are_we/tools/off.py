import PyCmdMessenger

port = '/dev/ttyACM0'
ard = PyCmdMessenger.ArduinoBoard(port, baud_rate=115200)
commands = [["setLed","i"]]
c = PyCmdMessenger.CmdMessenger(ard, commands)
c.send("setLed",50)



