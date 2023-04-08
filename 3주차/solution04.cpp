max_val = 0
include = [0]*N
max_include = None //최대값 + 아이템도 선택가능
{
    global max_val
    cur_weight, cur_value = 0,0
    for i in range(level):
        if include[i] == 1:
            cur_weiht += w[i]
            cur_value += v[i]

    if cur_weight > W:
        return 
    if cur_value > max_val:
        max_val = cur_value
    if level == N:
        return
    
    include[level] = 1
    knapsack(level+1)
    include[level] = 0
    knapsack(level+1)
}

knapsack(0)
print(max_val)

