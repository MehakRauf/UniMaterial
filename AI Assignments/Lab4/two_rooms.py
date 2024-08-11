#main
from com_environment import Environment
from com_environment import Room
from tworooms_agent import VaccumAgent

class TwoRoomVaccumCleanerEnvironment(Environment):
    def __init__(self, agent):
        #defining the two rooms
        self.r1 = Room('A', 'dirty')
        self.r2 = Room('B', 'dirty')
        self.agent = agent     
        self.currentRoom = self.r1
        self.delay = 1000
        self.step = 1 
        self.action = ""  

    def executeStep(self, n=1):
        for _ in range(0, n):    #In Python, the underscore (_) is often used as a throwaway variable name. It is used when the variable is not going to be used within the loop body, and its purpose is to indicate to the reader that the value is intentionally ignored. The underscore is a convention to signal that the loop variable is intentionally ignored and its value doesn't matter.
            self.displayPerception()
            self.agent.sense(self)     #self.agent.sense(self) calls the sense method on the agent object, passing self (which is the environment itself) as an argument.
            res = self.agent.act()
            self.action = res
            self.check_conditions(res)
            self.displayAction()
            self.step += 1

    def executeAll(self):
       raise NotImplementedError('action must be defined!')

    def displayPerception(self):
        print("Perception at step %d is [%s, %s]" % (self.step, self.currentRoom.status, self.currentRoom.location))

    def displayAction(self):
        print("------- Action taken at step %d is [%s]" % (self.step, self.action))

    def check_conditions(self,res):
        if res == 'clean':
                self.currentRoom.status = 'clean'
        elif res == 'right':
                self.currentRoom = self.r2
        else:
                self.currentRoom = self.r1        

# Test program
if __name__ == '__main__':
    vcagent = VaccumAgent()
    env = TwoRoomVaccumCleanerEnvironment(vcagent)
    env.executeStep(5)
    