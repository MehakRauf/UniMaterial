#com_environment
class Room:   #Represents a room in the environment.
    def __init__(self, location, status="dirty"):
        self.location = location
        self.status = status

from abc import abstractmethod

class Environment(object):  #Represents the environment in which the agent operates.
    @abstractmethod
    def __init__(self, n):
        self.n = n
    @abstractmethod
    def executeStep(self, n=1):          # Executes a step in the environment.
        raise NotImplementedError('action must be defined!')
    @abstractmethod
    def executeAll(self):      #Executes all steps in the environment (abstract).
        raise NotImplementedError('action must be defined!')
    @abstractmethod
    def delay(self, n=100):     #Delays the environment by a specified amount (abstract).
        self.delay = n
