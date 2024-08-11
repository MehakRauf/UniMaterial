import tkinter as tk 
from tkinter import ttk 

def create_button_labels(self):
        self.lbl_nodes = tk.Label(self.gui, text="Enter the nodes separated by commas(a,b,c):")  
        self.lbl_nodes.pack()  
        self.nodes_entry = ttk.Entry(self.gui)  
        self.nodes_entry.pack()  

        self.lbl_edges = ttk.Label(self.gui, text="Enter edges as ((from_node-to_node-weight)A-B-30)")  
        self.lbl_edges.pack()  
        self.edges_entry = ttk.Entry(self.gui)  
        self.edges_entry.pack()  

        self.lbl_start_node = ttk.Label(self.gui, text="Enter the initial Node:")  
        self.lbl_start_node.pack()  
        self.start_node_entry = ttk.Entry(self.gui)  
        self.start_node_entry.pack() 

        self.lbl_goal_node = ttk.Label(self.gui, text="Goal Node:")  
        self.lbl_goal_node.pack() 
        self.goal_node_entry = ttk.Entry(self.gui)  
        self.goal_node_entry.pack()  

        self.lbl_max_steps = ttk.Label(self.gui, text="Maximum Steps:")
        self.lbl_max_steps.pack()

        self.max_steps_entry = ttk.Entry(self.gui)
        self.max_steps_entry.pack()

        self.search_algo_frame = ttk.Frame(self.gui)
        self.search_algo_frame.pack(side=tk.TOP, padx=10, pady=10)

        # Define the buttons
        btn_bfs = ttk.Button(self.search_algo_frame, text="Breadth-First Search (BFS)", command=self.breadth_first_search)
        btn_ucs = ttk.Button(self.search_algo_frame, text="Uniform Cost Search (UCS)", command=self.uniform_cost_search)
        btn_dfs = ttk.Button(self.search_algo_frame, text="Depth-First Search (DFS)", command=self.depth_first_search)
        btn_dfsmin = ttk.Button(self.search_algo_frame, text="Depth-First Search (Minimum cost path)", command=self.dfs_mincost)
        btn_bfsmin = ttk.Button(self.search_algo_frame, text="Breadth-First Search (Minimum cost path)", command=self.bfs_mincost)
        # btn_iddfs = ttk.Button(self.search_algo_frame, text="Iterative Deepening DFS (IDDFS)", command=self.iterative_deepening_dfs)
        btn_random = ttk.Button(self.search_algo_frame, text="Random Search with maximum steps", command=self.random_explore)
        btn_random_open_closed = ttk.Button(self.search_algo_frame, text="Random Search with open and closed list", command=self.random_open_closed_list)

        # Place the buttons using the grid
        btn_bfs.grid(row=0, column=0, padx=5, pady=5)
        btn_dfs.grid(row=0, column=1, padx=5, pady=5)
        btn_dfsmin.grid(row=2, column=1, padx=5, pady=5)
        btn_bfsmin.grid(row=2, column=0, padx=5, pady=5)
        btn_ucs.grid(row=1, column=0, padx=5, pady=5)
        # btn_iddfs.grid(row=1, column=1, padx=5, pady=5)
        btn_random.grid(row=1, column=1, padx=5, pady=5)
        btn_random_open_closed.grid(row=3, column=0, padx=5, pady=5)
