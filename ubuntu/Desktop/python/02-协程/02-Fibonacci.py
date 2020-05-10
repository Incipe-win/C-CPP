class Fibonacci(object):
    
    def __init__(self, cnt):
        self.current = 0
        self.cnt = cnt
        self.a = 0
        self.b = 1

    def __iter__(self):
        return self

    def __next__(self):
        if self.current < self.cnt: 
            ret = self.a
            self.a, self.b = self.b, self.a + self.b
            self.current += 1
            return ret
        else:
            raise StopIteration

fibonacci = Fibonacci(10)

for num in fibonacci:
    print(num)
