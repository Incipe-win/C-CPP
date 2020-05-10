def create_num(cnt):
    a, b = 0, 1

    current = 0

    while current < cnt:
        yield a
        a, b = b, a + b
        current += 1

fab = create_num(10)

ret = next(fab)
print(ret)

ret = next(fab)
print(ret)
    
