def findHash(param):
    n = len(param)
    
    indexed_params = sorted((param[i], i) for i in range(n))
    
    used_hash_values = set()
    next_unused = 0  
    
    for param_val, _ in indexed_params:
        while next_unused < param_val and next_unused in used_hash_values:
            next_unused += 1
            
        if next_unused < param_val:
            #found unused value this position can take
            used_hash_values.add(next_unused)
            next_unused += 1
        #if next_unused >= param_val, this position can't contribute a new hash value
    
    return len(used_hash_values)