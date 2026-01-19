from ultralytics import YOLO
import cv2
import math 
import urllib.request
import numpy as np
 
url='http://192.168.133.226/cam-hi.jpg'
im=None

# model
model = YOLO("yolo-Weights/yolov8n.pt")

# object classes
classNames = ["person", "bicycle", "car", "motorbike", "aeroplane", "bus", "train", "truck", "boat",
              "traffic light", "fire hydrant", "stop sign", "parking meter", "bench", "bird", "cat",
              "dog", "horse", "sheep", "cow", "elephant", "bear", "zebra", "giraffe", "backpack", "umbrella",
              "handbag", "tie", "suitcase", "frisbee", "skis", "snowboard", "sports ball", "kite", "baseball bat",
              "baseball glove", "skateboard", "surfboard", "tennis racket", "bottle", "wine glass", "cup",
              "fork", "knife", "spoon", "bowl", "banana", "apple", "sandwich", "orange", "broccoli",
              "carrot", "hot dog", "pizza", "donut", "cake", "chair", "sofa", "pottedplant", "bed",
              "diningtable", "toilet", "tvmonitor", "laptop", "mouse", "remote", "keyboard", "cell phone",
              "microwave", "oven", "toaster", "sink", "refrigerator", "book", "clock", "vase", "scissors",
              "teddy bear", "hair drier", "toothbrush"
              ]

print("Getting image")

img_resp=urllib.request.urlopen(url)
imgnp=np.array(bytearray(img_resp.read()),dtype=np.uint8)
im = cv2.imdecode(imgnp,-1)
results = model(im, stream=True)

# coordinates
for r in results:
    boxes = r.boxes

    for box in boxes:
        # bounding box
        x1, y1, x2, y2 = box.xyxy[0]
        x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2) # convert to int values

        # put box in cam
        cv2.rectangle(im, (x1, y1), (x2, y2), (255, 0, 255), 3)

        # confidence
        confidence = math.ceil((box.conf[0]*100))/100
        print("Confidence --->",confidence)

        # class name
        cls = int(box.cls[0])
        print("Class name -->", classNames[cls])

        # object details
        org = [x1, y1]
        font = cv2.FONT_HERSHEY_SIMPLEX
        fontScale = 1
        color = (255, 0, 0)
        thickness = 2

        cv2.putText(im, classNames[cls], org, font, fontScale, color, thickness)

cv2.imwrite('test.jpg', im)

# cap.release()
# cv2.destroyAllWindows()

