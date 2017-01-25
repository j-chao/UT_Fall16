
data <- matrix(scan("/Users/JCHAO/Documents/UT/YEAR6/ISP/HW/hw6/contourData.dat.txt"), nrow=1000, byrow=TRUE)
colfunc <- colorRampPalette(c("red", "yellow")) 
filled.contour(data, col=colfunc(20), plot.title = title(main='Contour Data', xlab='x',ylab='y'))
