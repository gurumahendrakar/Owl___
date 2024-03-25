import cv2 as cv
import numpy as np ;

class CV:

    def __init__(self):
        self.filename = "C:/Users/gurum/Downloads/wp5490387.jpg";
        self.img = cv.imread(self.filename);
        for x in range(500):
            for i in range(500):
                for o in range(3):
                    self.img[x][i][o] = 20+o
        print(self.img)
        cv.imshow("Spritual",self.img);
        cv.waitKey(0)

c  = CV()