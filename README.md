# AnalogTrafficLight 
An analog traffic light system with a few modifications using Arduino. 

For the traffic light system , a potentiometer was added to control the timing of the signals. The timing for the green and red signals are proportional to the analog input value. The yellow signal will always have a constant duration of 1 second. 
 
An override feature using push button for control which can control which signal will turn ON. 
 
A light sensor (LDR) will be used for controlling the operating mode of the traffic light signals. 
* During day time, the traffic signal operates in the "normal" operation mode
* During night time, the traffic signal only flashes the "red" light every one second. 
 
A streetlight is also present in the system. During the day, a smart streetlight is completely off. As the sun goes down, the smart streetlight gradually turns itself on at intensity levels that are appropriate to give sufficient lighting to the environment. When it is completely dark, the 'smart' street lights gives off its brightest light. 
 
## Circuit Diagram: 
![image](https://github.com/Jaermis/AnalogTrafficLight/assets/138207746/9ceb376d-d71a-4851-b551-e2f406f40cf5)
