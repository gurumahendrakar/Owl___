

class LinkedList:
    def __init__(self,value__ = None):
        self.__next = None
        self.__value = value__
        self.__head = None
        self.length = 0
        self.currentNode = None

    def createNode(self,value__):
          Node = LinkedList(value__)
          return Node

    def EmptyNode(self):
        if self.__head is None:
            raise Exception(f"Your List Was Empty :: {self.length}")


    def Append(self,value__):
        self.length+=1
        if (self.__head is None):
            self.__head = self.createNode(value__)
            self.currentNode = self.__head
            return

        self.currentNode.__next = self.createNode(value__)
        self.currentNode = self.currentNode.__next
        return None


    def Length(self):
        return self.length


    def Insert(self,index__,value__):
        if (index__ >= 0 and self.length  > index__):
            loop = 0
            current__ = self.__head
            while (loop != index__ ):
                current__ = current__.__next
                loop+=1

            current__.__value = value__
            return None

        raise IndexError("Choose A Right Index")

    def printSTR(self):
        STR = "["
        currnet__ = self.__head
        while (currnet__):
            STR+= f" {currnet__.__value} "
            currnet__ = currnet__.__next
        STR+="]"
        return STR

    def __str__(self):
        return self.printSTR()


    def ReturnPrevNode(self):
        if ( self.__head.__next is None):
            value__ = self.__head.__value
            self.__head = None
            return value__

        current__  = self.__head
        prev__ = None

        while (current__.__next):
            prev__ = current__
            current__ = current__.__next

        prev__.__next = None
        return prev__


    def Remove(self,value__):

        current__ = self.__head
        prev__ = None
        while (current__):
            if (current__.__value==value__):
                if prev__ == None:
                    self.__head = current__.__next
                    return
                else:
                    prev__.__next = current__.__next

                return None

            prev__ = current__
            current__ = current__.__next

        else:
            raise Exception("Value Doe`s Not Match !!")


    def Pop(self):
        self.EmptyNode()
        self.length-=1
        Popped = self.currentNode.__value
        self.currentNode = self.ReturnPrevNode()
        return Popped


SignleLinked= LinkedList()
for i in range(25):
    SignleLinked.Append(i)

print(SignleLinked)