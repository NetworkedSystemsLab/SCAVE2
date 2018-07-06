import pyzed.camera as zcam
import pyzed.defines as sl
import pyzed.types as tp
import pyzed.core as core
import math
import numpy as np
import cv2
import sys
import time


def main():
	init_params = zcam.PyInitParameters()
	init_params.camera_resolution = sl.PyRESOLUTION.PyRESOLUTION_HD720
	init_params.camera_fps = 60
	init_params.depth_mode = sl.PyDEPTH_MODE.PyDEPTH_MODE_PERFORMANCE  # Use PERFORMANCE depth mode
	init_params.coordinate_units = sl.PyUNIT.PyUNIT_MILLIMETER  # Use milliliter units (for depth measurements)
	init_params.depth_minimum_distance = 300;

	print("Running...")
	
	cam = zcam.PyZEDCamera()
	if not cam.is_opened():
		print("Opening ZED Camera...")
	worst = 0


	status = cam.open(init_params)
	if status != tp.PyERROR_CODE.PySUCCESS:
		print(repr(status))
		exit()
	
	# Create and set PyRuntimeParameters after opening the camera
	runtime_parameters = zcam.PyRuntimeParameters()
	runtime_parameters.sensing_mode = sl.PySENSING_MODE.PySENSING_MODE_FILL  # Use STANDARD sensing mode
        #core.PyMEM.PyMEM_CPU
	#memory.PyMEM_CPU()
	image = core.PyMat()
	image.update_gpu_from_cpu()
	depth = core.PyMat()
	point_cloud = core.PyMat()

	#print_camera_information(cam)
	#print_help()
	#d = 0
	wait = 0
	key = ''
	buff = 0
	while key != 113:  # for 'q' keys
		start = time.time()
		err = cam.grab(runtime_parameters)
		print(round(cam.get_current_fps(),2))
		if err == tp.PyERROR_CODE.PySUCCESS:
			cam.retrieve_image(image, sl.PyVIEW.PyVIEW_LEFT)
			cam.retrieve_measure(depth, sl.PyMEASURE.PyMEASURE_DEPTH)
			cam.retrieve_measure(point_cloud, sl.PyMEASURE.PyMEASURE_XYZRGBA)
########Modified By Divas Grover########################################3
			def dist(a,b):
				err, point_cloud_value = point_cloud.get_value(a, b)
				distance = math.sqrt(point_cloud_value[0] * point_cloud_value[0] + point_cloud_value[1] * point_cloud_value[1] + point_cloud_value[2] * point_cloud_value[2])
				return distance
			
			x3 = image.get_width()/3
			y2 = image.get_height()/2
			
			xtl = int(x3/2)
			ytl = int(y2/2)
			
			xtm = int(xtl+x3)
			ytm = ytl
			
			xtr = int(xtm+x3)
			ytr = ytl
			########
			xbl = int(x3/2)
			ybl = int(ytl+y2)
			
			xbm = int(xbl+x3)
			ybm = ybl
			
			xbr = int(xbm+x3)
			ybr = ybl

			
			di_tl = [dist(i,j) for i in range(xtl-5,xtl+4) for j in range(ytl-5,ytl+4)]
			di_tm = [dist(i,j) for i in range(xtm-5,xtm+4) for j in range(ytm-5,ytm+4)]
			di_tr = [dist(i,j) for i in range(xtr-5,xtr+4) for j in range(ytr-5,ytr+4)]
			
			di_bl = [dist(i,j) for i in range(xbl-5,xbl+4) for j in range(ybl-5,ybl+4)]
			di_bm = [dist(i,j) for i in range(xbm-5,xbm+4) for j in range(ybm-5,ybm+4)]
			di_br = [dist(i,j) for i in range(xbr-5,xbr+4) for j in range(ybr-5,ybr+4)]

			frame = image.get_data()
			
			avg_dtl = sum(di_tl)/100
			avg_dtm = sum(di_tm)/100
			avg_dtr = sum(di_tr)/100
			
			avg_dbl = sum(di_bl)/100
			avg_dbm = sum(di_bm)/100
			avg_dbr = sum(di_br)/100
			
			def color(dst,r):
				if dst < r*1200 and dst > (r*1200 - 200):
					clr = (0,150,225)
				elif dst <= (r*1200 - 200):
					clr = (0,0,255)
				else:
					clr = (0,255,0)
				return clr
			
			c_dtl = color(avg_dtl,0.5)
			c_dtm = color(avg_dtm,1)
			c_dtr = color(avg_dtr,0.5)
			
			c_dbl = color(avg_dbl,0.5)
			c_dbm = color(avg_dbm,1)
			c_dbr = color(avg_dbr,0.5)

			t = round(((time.time()-start)*1000),2)
			
			dtl = str(round(avg_dtl,2))
			dtm = str(round(avg_dtm,2))
			dtr = str(round(avg_dtr,2))
			
			dbl = str(round(avg_dbl,2))
			dbm = str(round(avg_dbm,2))
			dbr = str(round(avg_dbr,2))
			
			#if math.isnan(avg_dist):
				#d = "NaN"
			#else:
				
				#if round(((time.time()-start)*1000),2) - t >= 1:
					#d = str(round(avg_dist)) + " time ms:"+ str(round(((time.time()-start)*1000),2)) + "worst_time:" + str(worst) + " #x="+str(x) + " y="+str(y)
				#else:
					#d = str(round(avg_dist)) + " time ms:"+ str(t) + " worst_time:" + str(worst) + " x="+str(x) + " y="+str(y)
			wd = image.get_width()
			ht = image.get_height()

############Drawing_on_Image#########################################
            ##Retangle
			cv2.rectangle(frame, (xtl+5,ytl+5),(xtl-4,ytl-4), (0,0,255),2)
			cv2.rectangle(frame, (xtm+5,ytm+5),(xtm-4,ytm-4), (0,0,255),2)
			cv2.rectangle(frame, (xtr+5,ytr+5),(xtr-4,ytr-4), (0,0,255),2)
			
			cv2.rectangle(frame, (xbl+5,ybl+5),(xbl-4,ybl-4), (0,0,255),2)
			cv2.rectangle(frame, (xbm+5,ybm+5),(xbm-4,ybm-4), (0,0,255),2)
			cv2.rectangle(frame, (xbr+5,ybr+5),(xbr-4,ybr-4), (0,0,255),2)
			
            ##Horizontal_Line
			cv2.line(frame,(0,int(image.get_height()/2)),(1280,int(image.get_height()/2)),(255, 0,255),1)
            ##Vertical_Lines
			cv2.line(frame,(int(wd/3),ht),(int(wd/3),0),(255,0,255),1)
			cv2.line(frame,(int(2*(wd/3)),0),(int(2*(wd/3)),ht),(255,0,255),1)
            ##Text
			cv2.putText(frame, dtl, (xtl+5,ytl-5), cv2.FONT_HERSHEY_SIMPLEX, 1, c_dtl, 2)
			cv2.putText(frame, dtm, (xtm+5,ytm-5), cv2.FONT_HERSHEY_SIMPLEX, 1, c_dtm, 2)
			cv2.putText(frame, dtr, (xtr+5,ytr-5), cv2.FONT_HERSHEY_SIMPLEX, 1, c_dtr, 2)
			
			cv2.putText(frame, dbl, (xbl+5,ybl-5), cv2.FONT_HERSHEY_SIMPLEX, 1, c_dbl, 2)
			cv2.putText(frame, dbm, (xbm+5,ybm-5), cv2.FONT_HERSHEY_SIMPLEX, 1, c_dbm, 2)
			cv2.putText(frame, dbr, (xbr+5,ybr-5), cv2.FONT_HERSHEY_SIMPLEX, 1, c_dbr, 2)
			##Image_Display
##################################################################################
#####################################END##########################################
##################################################################################
			cv2.imshow("ZED", frame)
####################################################################

			key = cv2.waitKey(5)
			if buff == 5 and worst < t:
				worst = t
			if buff < 5:
				buff = buff+1
			else:
				buff = 5
			#settings(key, cam, runtime, mat)
		else:
			key = cv2.waitKey(5)
	cv2.destroyAllWindows()

	cam.close()
	print("\nFINISH")

if __name__ == "__main__":
    main()
