import cv2
import numpy as np
img = cv2.imread("/home/julia/PROJETO/IMAGENS/001.jpg",1)
#rows,cols,channels= img.shape
#ponto = (cols/2,rows/2)
#rotacao=cv2.getRotationMatrix2D(ponto,15,1.0)
#rotacionado = cv2.warpAffine(img,rotacao,(cols,rows))
#cv2.imshow("rotacionando 45 graus",rotacionado)
#cv2.imwrite("/home/julia/Imagens/ROTACAO.png",rotacionado)
img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
img = cv2.medianBlur(img,11)
#img = cv2.adaptiveThreshold(img,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY_INV,11,5)
#kernel = np.ones((5,5),np.uint8)
#placa = cv2.dilate(img,kernel)
#placa = cv2.erode(placa,kernel)
otsu,img=cv2.threshold(img,110,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
placa =cv2.Canny(img,otsu*0.5,otsu)
#img = cv2.adaptiveThreshold(img,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY_INV,11,5)
placa = cv2.Canny(img,50,200)
#placa = cv2.morphologyEx(img, cv2.MORPH_OPEN,kernel)
#placa = cv2.morphologyEx(placa, cv2.MORPH_CLOSE,kernel)
#cv2.imshow("teste",img)
#cv2.imwrite("/home/julia/Imagens/PLACA17.png", img)
#cv2.imshow("teste2",img)
cv2.imwrite("/home/julia/PROJETO/RESULTADOS/001.png",placa)
