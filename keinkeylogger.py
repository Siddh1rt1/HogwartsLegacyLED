import keyboard  
import time
while True:  
    try: 
        if keyboard.is_pressed('p'):  
            print('You Pressed p Key!')
            time.sleep(0.1)
        if keyboard.is_pressed('o'):  
            print('You Pressed o Key!')
            time.sleep(0.1)

    except:
        break  
