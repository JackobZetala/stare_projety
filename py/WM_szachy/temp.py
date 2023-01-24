import numpy as np
import cv2

def count_pieces(file_name):
    chess = cv2.imread(file_name)
    chess_small = cv2.pyrDown(chess)
    cv2.imshow("Basic", chess_small)
    
    chess2 = cv2.cvtColor(chess_small,cv2.COLOR_RGB2GRAY)
    
    edges = cv2.Canny(chess2, 100, 200)
    cv2.imshow("Edges", edges)
    chess3 = cv2.GaussianBlur(chess2, (3,3),0)
    '''cv2.imshow("2", chess2)
    
    cv2.imshow("3", chess3)'''
    
    chess_thresh = cv2.adaptiveThreshold(chess3, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY,11,7)
    cv2.imshow("Thresholded", chess_thresh)
    
    kernel1 = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (6, 6))
    kernel2 = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (2, 2))
    kernel3 = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (7, 7))
    kernel4 = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (8, 8))
    
    chess_median = cv2.medianBlur(chess_thresh, 3)
    cv2.imshow("Median Blur", chess_median)
    
    chess_closed = cv2.morphologyEx(chess_median, cv2.MORPH_CLOSE, kernel2)
    cv2.imshow("Closed", chess_closed)

    chess_dilate = cv2.erode(chess_closed, kernel1)
    cv2.imshow("Dilated", chess_dilate)
    
    chess_median2 = cv2.medianBlur(chess_dilate, 11)
    cv2.imshow("Median Blur2", chess_median2)
    
    chess_closed2 = cv2.morphologyEx(chess_median2, cv2.MORPH_CLOSE, kernel3)
    cv2.imshow("Closed2", chess_closed2)
    
    chess_opened = cv2.morphologyEx(chess_closed2, cv2.MORPH_OPEN, np.ones((7, 7), np.uint8))
    cv2.imshow("Opened", chess_opened)
    
    chess_dilate2 = cv2.dilate(chess_opened, kernel4)
    cv2.imshow("Dilated2", chess_dilate2)
    
    conts, hier = cv2.findContours(chess_dilate2, cv2.RETR_LIST, cv2.CHAIN_APPROX_SIMPLE)
    chess_draw = chess_small.copy()
    chess_draw = cv2.drawContours(chess_draw, conts, -1, (255, 0, 255), 1)
    cv2.imshow("All contours", chess_draw)
    
    chess_draw2 = chess_small.copy()
    edge = cv2.Canny(chess_dilate2, 20, 100)
    cv2.imshow("Edge",edge)
    
    pieces = 0
    corners = []
    
    for cont in conts:
        area = cv2.contourArea(cont)
        if area < 980 and area > 30:
            corners.append(cont)
            pieces=pieces+1
           
    chess_draw_good = cv2.drawContours(chess_draw2, corners, -1, (255, 0, 0), 1)
    cv2.imshow("Good contours", chess_draw_good)
    
    print(pieces)
    cv2.waitKey()
    cv2.destroyAllWindows()

if __name__=='__main__':
    print(count_pieces('./images/1.jpg'))
