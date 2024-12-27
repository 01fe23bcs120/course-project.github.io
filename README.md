## 1. Shelter-to-Zone Connectivity Analysis
**Problem Statement**   
In a disaster scenario, shelters must be connected to disaster zones through optimal routes to minimize evacuation times and maximize the speed of resource allocation. These connections form a weighted graph where nodes represent shelters and zones, and edges represent transportation routes with weights denoting distances or travel times. The goal is to find the shortest path between every pair of nodes.  

**Key Aspects**
- Shortest path between all pairs of nodes.
- Identification of critical routes to prioritize resource allocation.

   **Algorithm Applied**<br>
  Floyd-Warshall Algorithm: It efficiently computes shortest paths between all pairs of nodes in a graph, even with negative weights (provided there are no negative weight cycles). This ensures a global view of connectivity for all shelters and zones simultaneously.

  **Time Complexity**
  O(V^3), where V is the number of shelters and disaster zones (nodes).

## 2. Task Scheduling for Rescue Operations
