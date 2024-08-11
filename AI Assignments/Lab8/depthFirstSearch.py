from queue import LifoQueue
from searchStrategy import SearchStrategy

class DepthFirstSearchStrategy(SearchStrategy):
    '''
    classdocs
    '''
    def __init__(self):
        self.stack = LifoQueue()
    
    def isEmpty(self):
        return self.stack.empty()
    
    def addNode(self, node):
        return self.stack.put(node)
    
    def removeNode(self):
        return self.stack.get()
