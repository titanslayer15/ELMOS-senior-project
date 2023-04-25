import serial

ser = serial.Serial('/dev/ttyUSB0')

ser.baudrate = 9600
ser.timeout = None

time = []
volt = []

data = bytearray()

while True:

    bt = ser.read(1);
    
    if bt == b' ':
        time.append(data)
        print(int.from_bytes(data, "big"))
        data = bytearray()
        continue
        
    elif bt == b'_':
        time.append(data)
        print(int.from_bytes(data, "little"))
        ser.close()
        break

    data += bt;



    
    # else:
        # print(int.from_bytes(data, "little"))
        # print(int.from_bytes(ser.read(4), "little"))


# for j in range(len(time)):
    # time[j] = int.from_bytes(time[j], "little")
    # volt[j] = int.from_bytes(volt[j], "little") * (5.0 / 1023.0)
    # print(time[j], ",", volt[j])
    
