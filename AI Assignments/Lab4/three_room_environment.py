
from com_environment import Environment
from com_environment import Room
from threerooms_agent import VaccumAgent

class ThreeRoomVaccumCleanerEnvironment(Environment):
    def __init__(self, agent):
        #defining the rooms along with their status i.e: clean or dirty
        self.r1 = Room('A', 'dirty')
        self.r2 = Room('B', 'dirty')
        self.r3 = Room('C', 'dirty')
        self.agent = agent
        #setting room A as the initial point
        self.currentRoom = self.r1
        self.delay = 1000
        #counting the steps
        self.step = 1
        self.action = ""

    def executeStep(self, n=1):
        for _ in range(0, n):
            self.displayPerception()
            self.agent.sense(self)
            res = self.agent.act()
            self.action = res
            self.check_conditions(res)
            self.displayAction()
            self.step += 1

    def check_conditions(self,res):
        if res == 'clean':
                self.currentRoom.status = 'clean'
        elif res == 'right':
            self.action_right()
        elif res == 'left':
            self.action_left()

    def executeAll(self):
        raise NotImplementedError('action must be defined!')

    def displayPerception(self):
        print("Perception at step %d is [%s,%s]" % (self.step, self.currentRoom.status, self.currentRoom.location))

    def displayAction(self):
        print("------- Action taken at step %d is [%s]" % (self.step, self.action))

    def action_right(self):
        if self.currentRoom == self.r1:
            self.currentRoom = self.r2
        elif self.currentRoom == self.r2:
            self.currentRoom = self.r3

    def action_left(self):
        if self.currentRoom == self.r3:
            self.currentRoom = self.r2
        elif self.currentRoom == self.r2:
            self.currentRoom = self.r1

# Test program
if __name__ == '__main__':
    vcagent = VaccumAgent()
    env = ThreeRoomVaccumCleanerEnvironment(vcagent)
    env.executeStep(50)
