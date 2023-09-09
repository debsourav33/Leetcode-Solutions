class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        List<Integer> ret = new ArrayList<>();
        Map<Integer,Boolean> hasParent = new HashMap<>();

        for(List<Integer> edge: edges){
          int v1 = edge.get(0);
          int v2 = edge.get(1);

          hasParent.put(v2,true); //it's reachable by other node
        }

        for(int i=0;i<n;i++){
          //if not reachable by other node, then add to result!
          if(!hasParent.containsKey(i))  
            ret.add(i);
        }

        return ret;
    }
}
