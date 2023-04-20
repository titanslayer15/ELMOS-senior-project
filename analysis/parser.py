import serial

ser = serial.Serial('/dev/ttyUSB0')

ser.baudrate = 9600
ser.timeout = None

time = []
volt = []

i = 0

while True:

    data = ser.read(4)

    print(data)
    
    if data == b'stop':
        ser.close()
        break

    else:
        time.append(data)
        volt.append(ser.read(4))

for j in range(len(time)):
    print(int.from_bytes(time[j], "little"))
    print(int.from_bytes(volt[j], "little"))
    print("\n")
