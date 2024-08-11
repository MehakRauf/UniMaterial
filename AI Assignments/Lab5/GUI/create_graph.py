def create_graph(self):
        nodes = self.nodes_entry.get().split(',')  
        edges = self.edges_entry.get().split(',')  

        for node in nodes:  
            self.graph[node.strip()] = {}  

        for edge in edges:  
            from_node, to_node, cost = edge.strip().split('-')  
            self.graph[from_node][to_node] = int(cost)  
            self.graph[to_node][from_node] = int(cost)  