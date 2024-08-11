def iddfs(self, start, goal):
        depth_limit = 0  
        while True:  
            result = dls(self,start, goal, depth_limit)  
            if result is not None:  
                return result
            depth_limit += 1  

def dls(self, node, goal, depth_limit):
    if node == goal:  
        return [node]  
    elif depth_limit == 0:  
        return None  
    elif depth_limit > 0:  
        for neighbor, _ in self.graph.get(node, {}).items():  
            result = dls(self,neighbor, goal, depth_limit - 1) 
            if result is not None:  
                return [node] + result              
            return None  