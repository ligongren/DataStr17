from traverse import *

build(1, [2, 7])
build(2, [1, 3, 4])
build(3, [2])
build(4, [2, 5, 6, 8])
build(5, [4, 6])
build(6, [4, 5, 8])
build(8, [4, 6])
build(7, [1, 9, 10])
build(9, [7, 10])
build(10, [7, 9])
# 数据在PPT上样例的基础上交换了７和８的位置，为了防止生成树就是数字的顺序



traverse()
