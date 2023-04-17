import serial

ser = serial.Serial('/dev/ttyUSB0')

ser.baudrate = 9600
ser.timeout = None

while True:
    data = ser.read(4)
    print(data)
