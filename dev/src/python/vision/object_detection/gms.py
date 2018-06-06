import cv2
import numpy as np
import PIL
import math
from numpy import pi, exp, sqrt, linalg
import matplotlib.pyplot as plt
from scipy import signal
from PIL import Image
from scipy import ndimage
from random import randint

class Program:
    def __init__(self):
        LucasKanade(im1,im2)
        
        im = 'C:\\Users\\nicol\\Desktop\\GMS.jpg'
        #im = input('please paste path to GMS')
        print('Gaussian MeanShift')
        GMS(im)
        print('done')
        
class GMS:

    def __init__(self,path):
        img = cv2.imread(path,cv2.IMREAD_COLOR)
        
        self.Hr = 90
        self.Hs = 90
        self.Iter = 100
        self.opImg = np.zeros(img.shape,np.uint8)
        
        # Mean Shift
        clusters = 0
        vectors = self.createMatrix(img)
        
        while(len(vectors) > 0):
            # Generate a random index for seed (from feature matrix)
            randomIndex = randint(0,len(vectors)-1)
            seed = vectors[randomIndex]
            
            # Cache the seed as our initial mean
            initialMean = seed
            
            neighbors = self.getNeighbors(seed,vectors)
            
            # If we get only 1 neighbor, we can mark it 
            if(len(neighbors) == 1):
                vectors=self.markPixels([randomIndex],initialMean,vectors,clusters)
                clusters+=1
                continue
            # If we have multiple pixels, calculate the mean of all
            mean = self.calculateMean(neighbors,vectors)
            
            # Calculate mean shift based on the initial mean
            meanShift = abs(mean-initialMean)
            
            if(np.mean(meanShift)<self.Iter):
                vectors = self.markPixels(neighbors,mean,vectors,clusters)
                clusters+=1
        
        cv2.imshow('Original Image',img)
        cv2.imshow('Mean Shift',self.opImg)
        
        
    def getNeighbors(self,seed,matrix,mode=1):
        # searches feature matrix to get neighbors of a pixel
        neighbors = []
        for i in range(0,len(matrix)):
            pixel = matrix[i]
            r = math.sqrt(sum((pixel[:3]-seed[:3])**2))
            s = math.sqrt(sum((pixel[3:5]-seed[3:5])**2))
            if(s < self.Hs and r < self.Hr ):
                neighbors.append(i)
        return neighbors
    
    def markPixels(self,neighbors,mean,matrix,cluster):
        # Deletes the pixel from the matrix and marks it in the output
        for i in neighbors:
            pixel = matrix[i]
            x=pixel[3]
            y=pixel[4]
            self.opImg[x][y] = np.array(mean[:3],np.uint8)
        return np.delete(matrix,neighbors,axis=0)
    
    def calculateMean(self,neighbors,matrix):
        neighbors = matrix[neighbors]
        gaussian = signal.gaussian(len(neighbors[:,:1]), std=7)
        denominator = sum(gaussian)
        
        r=neighbors[:,:1]
        g=neighbors[:,1:2]
        b=neighbors[:,2:3]
        x=neighbors[:,3:4]
        y=neighbors[:,4:5]
        
        sumr = 0
        sumg = 0
        sumb = 0
        sumx = 0
        sumy = 0
        
        for i in range(gaussian.shape[0]):
            sumr += r[i]*gaussian[i]
            sumg += g[i]*gaussian[i]
            sumb += b[i]*gaussian[i]
            sumx += x[i]*gaussian[i]
            sumy += y[i]*gaussian[i]
            
        mean = np.array([sumr[0],sumg[0],sumb[0],sumx[0],sumy[0]])/denominator

        return mean
    
    def createMatrix(self,img):
        # Creates a vector matrix of the image in the form of [r,g,b,x,y] for each pixel
        h,w,d = img.shape
        vectors = []
        for row in range(0,h):
            for col in range(0,w):
                r,g,b = img[row][col]
                vectors.append([r,g,b,row,col])
        vectors = np.array(vectors)
        return vectors        
    
program = Program()
