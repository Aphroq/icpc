import csv
import os

filename = 'E:/py/submission3.csv'



with open(filename,encoding='utf-8') as f:
   cnt = 0
   reader = csv.reader(f)
   #print(len(f.readlines())/18)
   for row in reader:
      cnt += 1
      #if cnt>10 :
      #   break
      stu = row
      path = os.getcwd() + '\\' + stu[1] 
      if not os.path.exists(path) :
         os.mkdir(path)

      path1 = path +'\\'+ stu[5] + '_wrong.cpp'
      path2 = path +'\\'+ stu[5] + '_right.cpp'
      print(path1)
      
      if os.path.exists(path1) or os.path.exists(path2):
         continue 
      if stu[2]!='0' :
         status = '_wrong.cpp'
      else:
         status = '_right.cpp'
         
      path = path + '\\' + stu[5] + status
      print(path)
      with open( path, "w", encoding='utf-8') as ff:
         ff.write(stu[3])



