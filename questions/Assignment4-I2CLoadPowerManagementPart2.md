Please include your answers to the questions below with your submission, entering into the space below each question
See [Mastering Markdown](https://guides.github.com/features/mastering-markdown/) for github markdown formatting if desired.

*Be sure to take measurements with logging disabled to ensure your logging logic is not impacting current/time measurements.*

*Please include screenshots of the profiler window detailing each current measurement captured.  See the file Instructions to add screenshots in assignment.docx in the ECEN 5823 Student Public Folder.* 

1. What is the average current per period?
   Answer: 48.48 Micro Amps
   <br>Screenshot:  
   ![Avg_current_per_period](https://github.com/CU-ECEN-5823/ecen5823-assignment4-Ganeshkm10/blob/master/Screenshots/AverageCurrentPerPeriod_A4.png)  

2. What is the average current when the Si7021 is Powered Off?
   Answer:2.13 mirco amps
   <br>Screenshot:  
   ![Avg_current_LPM_Off](https://github.com/CU-ECEN-5823/ecen5823-assignment4-Ganeshkm10/blob/master/Screenshots/Avg_current_LPM_Off_A4.png)  

3. What is the average current when the Si7021 is Powered On?
   Answer: 1.02 milli Amps
   <br>Screenshot:  
   ![Avg_current_LPM_Off](https://github.com/CU-ECEN-5823/ecen5823-assignment4-Ganeshkm10/blob/master/Screenshots/Avg_Current_LPM_On_A4.png)  

4. How long is the Si7021 Powered On for 1 temperature reading?
   Answer: 112 ms
   <br>Screenshot:  
   ![duration_lpm_on](https://github.com/CU-ECEN-5823/ecen5823-assignment4-Ganeshkm10/blob/master/Screenshots/Duration_LMP_On_A4.png)  

5. Compute what the total operating time of your design for assignment 4 would be in hours, assuming a 1000mAh battery power supply?
   Answer: 7.3 years.
   
6. How has the power consumption performance of your design changed since the previous assignment?
 
   Answer: Power consumption is reduced drastically from 529.95 Micro watt for one period to 133.48 Micro watt per period. 
           Average current per period is drastically reduced to 48.48 Micro amps from 159.39 Micro Amps, Which is the signficant improve compared to the Polling design. 
           Hence overall improvement is observed and the Interrupt based design is 4 to 5 times energy efficient than the polled based design.
   
   
7. Describe how you tested your code for EM1 during I2C transfers ?

   Answer: Silicon labs has SLEEP_ENERGYMode_t API which can be used to check the current energy mode the device is present in. 
           Another way is to remove the power add requirement and  check whether I2C is functioning or not. I have used the first way to check whether the device was in EM1                during I2C transfer.
   
