import os
import numpy as np
'''
self.target     顺序存储数据集
self.DataFile   存储根目录
self.s          存储所有数据
self.label      存储所有标签及其对应的值
'''
class create_list():
    def __init__(self,root,classnum=2):
        self.target=open("./Data.txt",'w')
        self.DataFile=root
        self.s=[]
        self.label={}
        self.datanum=0
    
    def create(self):
        files=os.listdir(self.DataFile)
        for labels in files:
            tempdata=os.listdir(self.DataFile+"/"+labels)
            self.label[labels]=len(self.label)
            for img in tempdata:
                self.datanum+=1
                self.target.write(self.DataFile+"/"+labels+"/"+img+" "+labels+"\n")
                self.s.append([self.DataFile+"/"+labels+"/"+img,labels])
    
    def detail(self):
        #查看数据数量以及标签对应
        print(self.datanum)
        print(self.label)
    
    def get_all(self):
        #查看所有数据
        print(self.s)

    def get_root(self):
        #获得根目录
        return self.DataFile

    def shuffle(self):
        #获得打乱的存储txt
        shuffle_file=open("./Shuffle_Data.txt",'w')
        temp=self.s
        np.random.shuffle(temp)
        for i in temp:
            shuffle_file.write(i[0]+" "+str(i[1])+"\n")
        return self.DataFile+"/Shuffle_Data.txt"

    def label_id(self,label):
        #获得该标签对应的值
        return self.label[label]
