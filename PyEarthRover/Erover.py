import cv2
import numpy as np
cap = cv2.VideoCapture(0)
#open image window
cv2.namedWindow('MouseEvent')

#function for ferform task on mouse event
def mouse_event_task(event,x,y,flags,param):
    if event == cv2.EVENT_LBUTTONDBLCLK:
        print("suresh")
#Mouse callback method calling
cv2.setMouseCallback('MouseEvent', mouse_event_task)

while(True):
    #Capture fraame by frame
    e1=cv2.getTickCount()
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    cv2.imshow('MouseEvent',gray)
    if cv2.waitKey(30) & 0xFF == ord('q'):
        break
    e2=cv2.getTickCount()
    t=(e2-e1)/cv2.getTickFrequency()
    if t>=3:
        print(t)
        cap.release()
        cv2.destroyAllWindows()
        break
