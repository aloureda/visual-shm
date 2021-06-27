import matplotlib.pyplot as plt
import csv
######
#creates lists for time, position, velocity, and acceleration
######
t = []
x = []
v = []
a = []

######
#opens csv file generated with c++ program
######
with open('shm.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter = ',')
    next(plots)
    rownumber=0

    ######
    #adds data to the lists
    ######
    for row in plots:
        rownumber+=1
        #sets the point limit to 1000 in output graphs
        if rownumber > 1000:
            break
        t.append(row[0])
        x.append(float(row[1]))
        v.append(float(row[2]))
        a.append(float(row[3]))
        
######
#defines a variable with the amount of rows specified in the output csv
######
ntotal=len(t)
#creates x-axis points for measurement depending on amount of rows
ticks=[1*(ntotal/5), 2*(ntotal/5), 3*(ntotal/5), 4*(ntotal/5), 5*(ntotal/5)]

######
#display settings for the three graphs (position, velocity, and acceleration vs. time)
######
plt.xticks(ticks)

plot1=plt.plot(t, x, color = 'g', linestyle = 'dashed',
         marker = '.',label = "SHM Graph")
plt.xlabel('Time (s)')
plt.ylabel('Position (m)')
plt.title('SHM Graph')
plt.grid()
plt.show()

plt.xticks(ticks)

plot2=plt.plot(t, v, color = 'r', linestyle = 'dashed',
         marker = '.',label = "SHM Graph")
plt.xlabel('Time (s)')
plt.ylabel('Velocity (m/s)')
plt.title('SHM Graph')
plt.grid()
plt.show()

plt.xticks(ticks)

plot3=plt.plot(t, a, color = 'y', linestyle = 'dashed',
         marker = '.',label = "SHM Graph")
plt.xlabel('Time (s)')
plt.ylabel('Acceleration (m/s2)')
plt.title('SHM Graph')
plt.grid()
plt.show()


