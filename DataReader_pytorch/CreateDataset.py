from PIL import Image
import torch

class cDataset(torch.utils.data.Dataset):
    def __init__(self, datatxt, root="", transform=None, target_transform=None, LabelDic=None):
        super(cDataset,self).__init__()
        files = open(root + "/" + datatxt, 'r')
        self.img=[]
        for i in files:
            i = i.rstrip()
            temp = i.split()
            if LabelDic!=None:
                self.img.append((temp[0],LabelDic[temp[1]]))
            else:
                self.img.append((temp[0],temp[0]))
            
        self.transform = transform
        self.target_transform = target_transform
    
    def __getitem__(self, index):
        files, label = self.img[index]
        img = Image.open(files).convert('RGB')
        if self.transform is not None:
            img = self.transform(img)
        return img,label
    
    def __len__(self):
        return len(self.img)

