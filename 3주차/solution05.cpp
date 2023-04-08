visited = [[[0]*4 for _ in range(N)] for _ in ranged(N)] 
//3차원 배열, 들어오는 방향

def maze(cur, in_dir):
    if not indside(cur) or brd[cur[0]][cur[1]] ! = 0 or,
    visited[cur[0]][cur[1]][in_dir] != 0;
        return false
    
    if cur == t;
        return true
    
    visited[cur[0]cur[1]][i_dir] = 1; 현재위치 들어온 방향 체크
    for d in range(4):
        if d == (in_dir+4-1)%4;
            continue;
        p = [cur[i] + offset[d][i] for i in range(2)]
        if maze(p,d):
            return true
        return false