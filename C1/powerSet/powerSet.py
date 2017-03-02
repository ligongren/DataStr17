def power_set(count):
    if count == 0:
        return [[]]
    last_set = power_set(count-1)
    added_set = power_set(count-1)
    for i in added_set:
        i += [count]
    return last_set + added_set

# define set

n = 3
# n = input('请输入所求集合中元素的数目:')
# n = [4,2]
# n += [3]
# print (n)

# n+=range(1,4)

# print(n)

print(power_set(n))

# lis.extend('d')            #show all set in set
# print len(lis)             #show shuzu number
# 第一次课课后作业
