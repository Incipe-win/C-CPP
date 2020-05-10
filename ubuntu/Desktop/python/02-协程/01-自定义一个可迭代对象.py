from collections import Iterable
from collections import Iterator

class Classmate(object):
    
    def __init__(self):
        self.names = list()
        self.current = 0

    def add(self, name):
        self.names.append(name)

    def __iter__(self):
        return self

    def __next__(self):
        if self.current < len(self.names):
            ret = self.names[self.current]
            self.current += 1
            return ret
        else:
            raise StopIteration


classmate = Classmate()

classmate.add("Hello")
classmate.add("World")
classmate.add("You")

# print("判断classmate是否是可迭代对象:", isinstance(classmate, Iterable))
# classmate_iterator = iter(classmate)
# print("判断classmate_iterator是否是可迭代对象:", isinstance(classmate_iterator, Iterator))


for name in classmate:
    print(name)
