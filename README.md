# robot-animation
This is the first project in our CGclass,which is taught by handsome dean Chen and cool teacher Li!
    实验报告本实验以OPENGL为基础，构建了模拟机器人行走的模型，大体思路是设置全局静态变量static distance代表平移
距离不同的angle代表四肢的角度，foward变量判断左腿转动的方向，通过对面向绘图过程的封装来直观实现机器人的运动。
   实验实现过程直观，试图通过最小的代码量实现该功能，主体代码在Stickman.cpp中，分别画头、身子、躯干、腿，下
   面以画右腿为例介绍一下具体过程
   void draw_rightleg(){ 
   glPushMatrix(); 
   glColor3f(1.0f, 1.0f, 1.0f); 
   glTranslatef(distance, 0.0f, -0.1f); 
   glRotatef(rleg_angle1, 0, 0, 1); 
   glTranslatef(0.0f, -0.15f, 0.0f); 
   glScalef(0.1f, 0.3f, 0.1f); 
   glutSolidCube(1); 
   glColor3f(0.0f, 1.0f, 0.0f);
   glTranslatef(0.0f, -1.0f, 0.0f);
   glRotatef(rleg_angle2, 0, 0, 1);
  }
   首先压入矩阵，设置大腿颜色为白色，然后平移到旋转中心，然后旋转一个角度，在再成比例放缩，注意这个顺序是问题的
 关键，首先平移到旋转中心再旋转，用glutsolidcube画出正方体。绿色的小腿也是同样的道理，而且实现了相对旋转和相对
 运动
   如何更改全局变量，又如何让画面动起来呢，这就要用到idle在绘画闲时更新数据，下面是myidle的代码段，注意小腿和小
 臂的摆动的增幅是大腿和大臂的两倍。代码比较易懂
 void myidle() } //bool foward = 1;//左臂和右腿向前运动  
 if (foward==1){  
 distance = distance - 0.00006;  
 larm_angle1 +=0.05;  
 larm_angle2 += 0.1;  
 rarm_angle1 -= 0.05;  
 rarm_angle2 -= 0.1;  
 lleg_angle1 -= 0.05;  
 rleg_angle1 += 0.05;  
 lleg_angle2 -= 0.1;  
 rleg_angle2 += 0.1;   
 } 
 else{  
 distance = distance - 0.00006;  
 rarm_angle1 += 0.05;  
 rarm_angle2 += 0.1;  
 larm_angle1 +=-0.05;  
 larm_angle2 += -0.1;  
 lleg_angle1 += 0.05;  
 rleg_angle1 -= 0.05;  
 lleg_angle2 += 0.1;  
 rleg_angle2 -= 0.1; 
 }   
 mydisplay(); }
