#ifndef TROJAN_MAP_H
#define TROJAN_MAP_H
#define DOT_SIZE 5
#define LINE_WIDTH 3

#include <iostream>
#include <map>
#include <vector>

// A Node is the location of one point in the map.
class Node {
  public:
    Node(){};
    Node(const Node &n){id = n.id; lat = n.lat; lon = n.lon; name = n.name; neighbors = n.neighbors;};
    std::string id;    // A unique id assign to each point
    double lat;        // Latitude
    double lon;        // Longitude
    std::string name;  // Name of the location. E.g. "Bank of America".
    std::vector<std::string>
        neighbors;     // List of the ids of all neighbor points.
};

class TrojanMap {
 public:
  //-----------------------------------------------------
  // TODO: You do not and should not change the following functions:

  // Create the menu.
  void PrintMenu();

  // Read in the data
  void CreateGraphFromCSVFile();

  // Visualization
  // Given a location id, plot the point on the map.
  void PlotPoint(std::string id);

  // Given a lat and lon, plot the point on the map.
  void PlotPoint(double lat, double lon);

  // Given a vector of location ids draws the path (connects the points)
  void PlotPath(std::vector<std::string> &location_ids);

  // Given a vector of location ids draws the points on the map (no path).
  void PlotPoints(std::vector<std::string> &location_ids);

  // Create the videos of the progress to get the path
  void CreateAnimation(std::vector<std::vector<std::string>>);

  // Transform the location to the position on the map
  std::pair<double, double> GetPlotLocation(double lat, double lon);
  //-----------------------------------------------------
  // TODO: Implement these functions and create unit tests for them:

  // Get the Latitude of a Node given its id.
  double GetLat(std::string id);

  // Get the Longitude of a Node given its id.
  double GetLon(std::string id);

  // Get the name of a Node given its id.
  std::string GetName(std::string id);

  // Get the neighbor ids of a Node.
  std::vector<std::string> GetNeighborIDs(std::string id);

  // Get the distance between 2 nodes.
  double CalculateDistance(const Node &a, const Node &b);

  // Calculates the total path length for the locations inside the vector.
  double CalculatePathLength(const std::vector<std::string> &path);

  // Returns a vector of names given a partial name.
  std::vector<std::string> Autocomplete(std::string name);
  // AutoComplete2 can show the places that contains the search string, not just the ones that start with the search string
  std::vector<std::string> Autocomplete2(std::string name);

  // Returns lat and long of the given the name.
  std::pair<double, double> GetPosition(std::string name);

  // Given the name of two locations, it should return the **ids** of the nodes
  // on the shortest path. Dijkstra
  std::vector<std::string> CalculateShortestPath(std::string location1_name,
                                                 std::string location2_name);

  // shortest path helper function
  std::string GetID(std::string name);
  bool isAllVisited(std::map<std::string, bool> visited);
  std::string findMinID(std::map<std::string, double> &dist, std::map<std::string, int> &visited);

  // Given the name of two locations, it should return the **ids** of the nodes
  // on the shortest path. Bellman-Ford
  std::vector<std::string> CalculateShortestPath_BF(std::string location1_name, std::string location2_name);

  // Given a vector of location ids, it should reorder them such that the path
  // that covers all these points has the minimum length.
  // The return value is a pair where the first member is the total_path,
  // and the second member is the reordered vector of points.
  // (Notice that we don't find the optimal answer. You can return an estimated
  // path.)
  std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan(
      std::vector<std::string> &location_ids);



  // Help calculate TT problem
  double TTHelper(std::vector<std::vector<int>> &resultsIndexVec, std::vector<int> &location_indexs, 
      std::vector<std::vector<double>> adjMatrix, int start, int curNode, double curCost, double &minCost, std::vector<int> path);

  // 2opt
  std::pair<double, std::vector<std::vector<std::string>>> TravellingTrojan_2opt(
                                    std::vector<std::string> &location_ids);

  // 2opt swap helper function
  std::vector<std::string> twoOptSwap(std::vector<std::string> curRoute, int i, int k);




  //-----------------------------------------------------

  
  private:
  // A map of ids to Nodes.
  std::map<std::string, Node> data;

};

#endif