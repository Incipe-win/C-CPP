import greenlet


def create_num(cnt):
    a, b = 0, 1

    current = 0

    while current < cnt:
        tmp = yield a
        print(">>>>>>", tmp)
        a, b = b, a + b
        current += 1


fab = create_num(10)

ret = next(fab)
print(ret)

ret = fab.send("hahahah")
print(ret)

ret = fab.send("I'am handsome!")
print(ret)
