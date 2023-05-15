import keyboard  
import time
import serial
import inputs

ser = serial.Serial('COM9', 9800, timeout=1)
steps=0.2
global lastevent
global lastlastevent
lastevent= ["hey",24]
lastlastevent= ["hey",24]
global tooglelumos
tooglelumos=False
while True:  
    events = inputs.get_gamepad()

    for event in events:
        
        if event.code!="ABS_X" and event.code!="SYN_REPORT" and event.code!="ABS_Y" and event.code!="ABS_Z"  and event.code!="ABS_RY" and event.code!="ABS_RX":
               
            print("log"+str(lastevent))
            #pew-zauber
            if lastevent==["ABS_RZ",255] and event.code=="ABS_RZ" and event.state!=255:
    
                time.sleep(0.08)
                ser.write(b'P')
                time.sleep(steps)
                print("süden")

            #revelio 
            if event.code=="ABS_HAT0X" and event.state ==-1:
                print("revelio")
                ser.write(b'R')
                time.sleep(steps)

            #lumos 
            if lastevent==["ABS_RZ",255]:
                if event.code=="BTN_NORTH" and event.state ==1:
                    print("lumos")
                    if tooglelumos==False:
                        print("lumosstart")
                        time.sleep(0.2)
                        ser.write(b'L')
                        tooglelumos=True
                    else:
                        
                        ser.write(b'S')
                        print("lumosstop")   
                        tooglelumos=False 
                    time.sleep(steps)
            
            if event.code=="BTN_NORTH" and event.state ==1 and lastevent!=["ABS_RZ",255]:
                print("east")
                ser.write(b'T')
                time.sleep(steps)
            lastevent=[event.code,event.state]
            lastlastevent=lastevent
        




