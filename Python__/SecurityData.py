
# class SymentricEncry:

#     def __init__(self):
#         self.__key1 = 5
#         self.__key2 = 10

#     def Encryption(self,data):
#         data = str(data)
#         index = 0
#         encryString = ""
#         while (index < len(data)):
#             encryString+=  str(int(ord(data[index])) ^ self.__key1 ^ (self.__key2))+"-"
#             index+=1
#         return (encryString[0 : len(encryString) - 1 ])

#     def Decryption(self,data):
#         decryString = ""
#         for i in data.split("-"):
#             decryString+=chr(int(i) ^ 10 ^ 5)
#         return (decryString)


# symKey = SymentricEncry()
# data = (symKey.Encryption("Take Care Of IT "))
# for i  in data.split("-"):
#     print(chr(int(i)),end=" ")
# print()

# print(symKey.Decryption(data))




