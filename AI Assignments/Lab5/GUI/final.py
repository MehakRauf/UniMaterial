import tkinter as tk  
from tkinter import messagebox  
from create_widgets import create_button_labels
from create_graph import create_graph
from bfs import bfs 
from dfs import dfs
from dfsminimumcost import dfs_mincost
from bfsminimumcost import bfs_mincost
from uniform_cost_search import ucs
from random_search import random_search
from rs_with_open_closed import random_search_openclosed
from iddfs import iddfs

class UniformedSearchAlgorithms:
    def __init__(self, gui):
        self.gui = gui
        self.gui.title("Uniformed Search Algorithms") 
        self.graph = {}  #storing the graph as a dictionary
        create_button_labels(self)  
    
    def breadth_first_search(self):
        create_graph(self)  
        start_node = self.start_node_entry.get()  
        goal_node = self.goal_node_entry.get()  
        path = bfs(self,start_node, goal_node) 
        self.show_result("Using the BFS algorithm", start_node, goal_node, path)  

    def depth_first_search(self):
        create_graph(self)  
        start_node = self.start_node_entry.get()  
        goal_node = self.goal_node_entry.get()  
        path = dfs(self,start_node, goal_node)  
        self.show_result("Using the DFS algorithm", start_node, goal_node, path) 

    def dfs_mincost(self):
        create_graph(self)  
        start_node = self.start_node_entry.get()  
        goal_node = self.goal_node_entry.get()  
        path = dfs_mincost(self,start_node, goal_node)  
        self.show_result("Using the DFS algorithm", start_node, goal_node, path)  
    
    def bfs_mincost(self):
        create_graph(self)  
        start_node = self.start_node_entry.get()  
        goal_node = self.goal_node_entry.get()  
        path = bfs_mincost(self,start_node, goal_node)  
        self.show_result("Using the DFS algorithm", start_node, goal_node, path)  
    
    def uniform_cost_search(self):
        create_graph(self)  
        start_node = self.start_node_entry.get()  
        goal_node = self.goal_node_entry.get()  
        path = ucs(self,start_node, goal_node)  
        self.show_result("Using the UCS algorithm", start_node, goal_node, path)  

    # def iterative_deepening_dfs(self):
    #     create_graph(self)  
    #     start_node = self.start_node_entry.get()  
    #     goal_node = self.goal_node_entry.get()  
    #     path = iddfs(self,start_node, goal_node)  
    #     self.show_result("Using the IDDFS algorithm", start_node, goal_node, path)  

    def random_explore(self):
        create_graph(self) 
        start_node = self.start_node_entry.get()  
        max_steps = int(self.max_steps_entry.get())  
        path = random_search(self,start_node, max_steps)  
        if path:  
            messagebox.showinfo("The path is:", f"{path}") 
        else:  
            messagebox.showwarning("No path found") 
    def random_open_closed_list(self):
        create_graph(self)  
        start_node = self.start_node_entry.get()  
        path = random_search_openclosed(self,start_node)  
        if path:  
            messagebox.showinfo("The path is:", f"{path}") 
        else:  
            messagebox.showwarning("No path found")  

    def show_result(self, title, start, goal, path):
        if path:  
            messagebox.showinfo(title, f"Path from {start} to {goal}: {path}")  
        else:  
            messagebox.showinfo(title, f"No path found from {start} to {goal}")  

def main():
    root = tk.Tk()  
    app = UniformedSearchAlgorithms(root)  
    root.mainloop() 

if __name__ == "__main__":
    main()  