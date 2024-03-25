



class LIFO:
    def __init__(self):
        self.__stack = []
        self.__maxStackSize = 5

    def __len__(self):
        return self.__maxStackSize

    def getSize(self):
        return self.__maxStackSize

    def Pop(self):
        if (self.__maxStackSize == 5):
            raise Exception("Stack UnderFlow! ")

        pop = self.__stack.pop()
        self.__maxStackSize += 1
        return pop
    def CheckOverflowAndAppend(self,value__):
        check__ = (lambda  : self.__stack.append(value__)  if  self.__maxStackSize!=0  else Exception("Stack Overflow"))()
        if (check__):
             raise  check__


    def Push(self,value__):
        self.CheckOverflowAndAppend(value__)
        self.__maxStackSize-=1


stack = LIFO()

