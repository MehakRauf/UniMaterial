from queue import PriorityQueue
from searchStrategy import SearchStrategy

class UCS(SearchStrategy):
    '''
    classdocs
    '''
    def __init__(self):
        self.priorityQueue = PriorityQueue()
    
    def isEmpty(self):
        return self.priorityQueue.empty()
    
    def addNode(self, node):
        return self.priorityQueue.put((node.cost, node))
    
    def removeNode(self):
        return self.priorityQueue.get()[1]
