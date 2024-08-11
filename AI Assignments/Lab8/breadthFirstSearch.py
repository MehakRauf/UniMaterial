from searchStrategy import SearchStrategy
from queue import Queue

class BreadthFirstSearchStrategy(SearchStrategy):
    '''
    classdocs
    '''
    def __init__(self):
        self.queue = Queue()

    #to check if all the nodes are visited
    def isEmpty(self):
        return self.queue.empty()

    #to add a node
    def addNode(self, node):
        self.queue.put(node)

    #to remove a node
    def removeNode(self):
        return self.queue.get()



