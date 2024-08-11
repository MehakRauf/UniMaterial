class Node(object):
    '''
    classdocs
    '''
    def __init__(self, state, parentNode=None, depth=0, cost=0, action=''):
        '''
        Constructor
        '''
        # Initialize the state of the node
        self.state = state
        # Initialize the parent node
        self.parentNode = parentNode
        # Initialize the depth of the node in the search tree
        self.depth = depth
        # Initialize the cost associated with reaching this node
        self.cost = cost
        # Initialize the action taken to reach this node from its parent
        self.action = action

    # Define comparison methods
    def __lt__(self, other):
        return self.cost < other.cost

    def __eq__(self, other):
        return self.cost == other.cost
    
    def __str__(self):
        # Return a string representation of the node
        return str(self.state) + " -- " + self.action + " -- " + str(self.cost)
