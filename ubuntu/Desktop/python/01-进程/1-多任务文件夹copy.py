import multiprocessing
import math
import os

def copy_file(queue, file_name, old_folder_name, new_folder_name):
    """完成文件的复制"""
    old_f = open(old_folder_name + "/" + file_name, "rb")
    content = old_f.read()
    old_f.close()
   
    new_f = open(new_folder_name + "/" + file_name, "wb")
    new_f.write(content)
    new_f.close()

    queue.put(file_name)



def main():
    # 1. 获取用户要copy的文件夹的名字
    old_folder_name = input("请输入要copy的文件夹的名字: ")

    # 2. 创建一个新的文件夹
    try:
        new_folder_name = old_folder_name + "[副本]"
        os.mkdir(new_folder_name)
    except:
        pass

    # 3. 获取文件夹的所有的待copy的文件名字listdir()
    file_names = os.listdir(old_folder_name)
    print(file_names)

    # 4. 创建进程池
    po = multiprocessing.Pool(5)
    queue = multiprocessing.Manager().Queue()

    # 5. 向进程池红添加copy文件的任务
    for file_name in file_names:
        # 复制原文件夹中的文件，到新的文件夹中的文件去
        po.apply_async(copy_file, args = (queue, file_name, old_folder_name, new_folder_name))

    po.close()
    # po.join()
    length = len(file_names)
    cnt = 0
    
    while True:
        file_name = queue.get()
        # print("%s已经copy完成!" % file_name)
        cnt += 1 
        print("\r已经完成: %.2f %%" % (cnt * 100 / length), end="")
        if cnt >= length:
            break
       
    print()

if __name__ == "__main__":
    main()
