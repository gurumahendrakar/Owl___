


class Node:

    def __init__(self,value__):
        self.__value = value__
        self.__prev = None
        self.__next = None



class Double:
    def __init__(self):
        self.__head = None
        self.currentNode = None
        self.__length = 0

    def EmptyNode(self):
        if not self.__length:
            raise Exception(f"Your List Was Empty :: {self.__length}")


    def Pop(self):
        self.EmptyNode()
        self.__length -= 1
        Popped = self.currentNode._Node__value
        self.currentNode = self.currentNode._Node__prev
        return Popped

    def Remove(self, value__):

        current__ = self.__head
        while (current__):
            if (current__._Node__value==value__):
                if not current__._Node__prev:
                    self.__head = self.__head._Node__next
                    self.__head._Node__prev = None
                else:
                    self.currentNode = current__._Node__prev
                    self.currentNode._Node__next = current__._Node__next

                return
            current__ = current__._Node__next

    def printSTR(self):
        STR = "["
        currnet__ = self.__head
        while (currnet__):
            STR+= f" {currnet__._Node__value} "
            currnet__ = currnet__._Node__next
        STR+="]"
        return STR

    def Insert(self, index__, value__):
        if (index__ >= 0 and self.__length > index__):
            loop = 0
            current__ = self.__head
            while (loop != index__ ):
                current__ = current__._Node__next
                loop += 1

            current__._Node__value = value__
            return None

        raise IndexError("Choose A Right Index")

    def Push(self, value__):
        self.__length += 1
        if (self.__head is None):
            self.__head = Node(value__)
            self.currentNode = self.__head
            return


        node = Node(value__)
        node._Node__prev = self.currentNode
        self.currentNode._Node__next = node
        self.currentNode = self.currentNode._Node__next

        return None

    def __len__(self):
        return self.__length

    def __str__(self):
        return self.printSTR()


double =  Double()
for i in range(25):
    double.Push(i)

print(double)