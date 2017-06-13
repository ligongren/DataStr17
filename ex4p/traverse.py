graph = []


def build(node, linked):
    graph.append([node, linked, False])


def traverse():
    for i in graph:
        if not i[2]:
            dfs(i)


def dfs(now_node):
    if now_node[2]:
        return  # 如果已经遍历过则直接返回
    now_node[2] = True  # 将状态置为已遍历

    if now_node[0]:
        # 如果不为0则输出
        if no_next(now_node):
            print(now_node[0])
        else:
            print(now_node[0], end=" ")

    for i in now_node[1]:
        if not trave_ed(i):
            dfs(find_info(i))


def no_next(now_node):
    for i in now_node[1]:
        if not trave_ed(i):
            return False
    return True


def trave_ed(number):
    for i in graph:
        if i[0] == number:
            return i[2]


def find_info(number):
    for i in graph:
        if i[0] == number:
            return i
