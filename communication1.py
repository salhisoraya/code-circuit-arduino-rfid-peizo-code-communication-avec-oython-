import serial
try:
    arduino = serial.Serial("COM3", timeout=1)
except:
    print("verifier le port utilisé")

while True:
        data = arduino.readline().decode()
        print(data)