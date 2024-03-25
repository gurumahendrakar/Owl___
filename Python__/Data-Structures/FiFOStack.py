





class FIFO:

    def __init__(self):
        self.stack = []
        self.__front = -1
        self.__rear = -1
        self.QueueSize = 2
        self.is_full = False
        self.OneTimeFull= False
        self.Database = []

    def Deque(self):
        self.isFull()


    def isFull(self):
        if (self.is_full):
            self.__front += 1
            self.Database.append(self.stack[self.__front])

            if (self.__front > -1 and self.__rear == self.QueueSize):
                self.__rear  =  -1

            if (self.__front==self.QueueSize):
                self.__front = -1
                self.is_full = False

        else:
            if (self.__rear > self.__front):
                self.__front += 1
                self.Database.append(self.stack[self.__front])



    def isNotFull(self,value__):
        if (not self.is_full ):
            self.__rear += 1
            if (self.OneTimeFull):
                self.stack[self.__rear] = value__
            else:
                self.stack.append(value__)

            if (self.__rear == self.QueueSize):
                self.is_full = True
                if (not self.OneTimeFull):
                    self.OneTimeFull = True
        else:
            if (self.__front > self.__rear):
                self.__rear+=1
                self.stack[self.__rear] = value__


    def Enque(self,value__):
        self.isNotFull(value__)


    def __str__(self):
        return str(self.__rear) + "---" + str(self.__front)

fifo = FIFO()


print(fifo.stack,fifo.is_full,fifo._FIFO__front,fifo._FIFO__rear)
