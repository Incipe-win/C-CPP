import argparse

# 获取所有参数
parse = argparse.ArgumentParser()
parse.add_argument("number1", help="第一个参数", type=int)
parse.add_argument("number2", help="第二个参数", type=int)

# 解析所有参数
args = parse.parse_args()

print("第一个参数: ", args.number1)
print("第二个参数: ", args.number1)
print("所有参数: ", args)
