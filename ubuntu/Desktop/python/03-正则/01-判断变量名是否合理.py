import re

def main():
    names = ["age", "_age", "1age", "age_1", "a_age", "age!", "a#123"]
    
    for name in names:
        ret = re.match(r"[a-zA-Z_]\w*$", name)
        if ret:
            print("%s it is ok!" % ret.group())
        else:
            print("%s it is not ok!" % name)
    



if __name__ == "__main__":
    main()
