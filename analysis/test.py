import serial

ser = serial.Serial('/dev/ttyUSB0')

ser.baudrate = 9600
ser.timeout = None

while True:
    time = ser.read(4)
    volt = ser.read(4)
    print(time)
    print(volt)
    print('\n\n')
    
