import cv2
import numpy as np
import PIL
import math
from numpy import pi, exp, sqrt, linalg
import matplotlib.pyplot as plt

class DepthFind(object):
    def __init__(self):
        # Load up image
        filename = 'C:\\Users\\nicol\\Desktop\\NSL\\Tests\\Picture1.png'
        #img = np.asarray(PIL.Image.open(filename))

        img = np.asarray(cv2.imread(filename))
        img = cv2.cvtColor( img, cv2.COLOR_RGB2GRAY )
        
        # # Call function
        # finding the mean of the act
        t = 140
        alX = 0
        alY = 0
        num = 0
        edged = self.maxEntropy(img)
        for x in range(img.shape[0]):
            for y in range(img.shape[1]):
                if(img[x,y] > t):
                    alX += x
                    alY += y
                    num += 1
        if num == 0:
            num = 1
        x = alX//num
        y = alY//num
        w = 400
        h = 400
        cv2.imshow("ed",edged)
        img = cv2.rectangle(img,(x,y),(x+w,y+h),(255,255,255),2)
        #_, cnts, _= cv2.findContours(edged, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        #cnts = sorted(cnts, key = cv2.contourArea, reverse = True)[:10]
        
        #for cnt in cnts:
         #   x,y,w,h = cv2.boundingRect(cnt)
        #img = cv2.rectangle(img,(x,y),(x+w,y+h),(255,255,255),2)
            
        cv2.imshow("test",img)
        cv2.waitKey(0)
        cv2.destroyAllWindows()
        # #write images
        # cv2.imwrite("C:\\Users\\nicol\\Desktop\\binary1.jpg",bin1)
    
    def maxEntropy(self,image):
        # obtain histogram
        hist = np.histogram(image, bins=256, range=(0, 256))[0]
        
        # get threshold
        t = self.calculateT(hist)
        
        # binary        
        return cv2.Canny(image,t//3,t) 
    
    def calculateT(self,data):
        # calculate Cumulative density function
        cdf = data.astype(np.float).cumsum()
    
        # find histogram's nonzero area
        temp = np.nonzero(data)[0]
        firstBin = temp[0]
        lastBin = temp[-1]
    
        # initialize search for maximum
        maxE, threshold = 0, 0
    
        for i in range(firstBin, lastBin + 1):
            # Background (dark)
            hRange = data[:i + 1]
            hRange = hRange[hRange != 0] / cdf[i]  # normalize within selected range & remove all 0 elements
            totalE = -np.sum(hRange * np.log(hRange))  # background entropy
    
            # Foreground/Object (bright)
            hRange = data[i + 1:]
            
            # normalize within selected range & remove all 0 elements
            hRange = hRange[hRange != 0] / (cdf[lastBin] - cdf[i])
            totalE -= np.sum(hRange * np.log(hRange))  # accumulate object entropy
    
            # find max
            if totalE > maxE:
                maxE, threshold = totalE, i
    
        return threshold         

depthFind = DepthFind()
