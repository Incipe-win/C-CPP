import re


def main():
    while True:
        names = input("请输入您的邮箱地址: ")

        ret = re.match(r"[a-zA-Z0-9_]{4,20}@(162|163|qq|gmail)\.com$", names)
        if ret:
            print("%s ok!" % ret.group())
        else:
            print("%s is not ok!" % names)


if __name__ == "__main__":
    main()
