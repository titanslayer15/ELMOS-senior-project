import serial

ser = serial.Serial('/dev/ttyUSB0')

ser.baudrate = 9600
ser.timeout = None

while True:

    time = read(4)

    if data == b'00000000':
        ser.close()
        break

    else:
        time = data
        voltage = read(4)
        print(time.decode())
        print(voltage.decode())
