class Node{
  HashMap<Integer, Node> child = new HashMap();
  
  boolean hasChild(int key){
    return child.containsKey(key);
  }

  Node getChild(int key){
    return child.get(key);
  }

  void push(int key, Node node){
    child.put(key, node);
  }

}

class Trie{
  Node root = new Node();
  
  void insert(Node node, int [] arr, int pos, int end){
    if(pos==end)  return;

    int idx = arr[pos];
    if(!node.hasChild(idx))
      node.push(idx,new Node());

    insert(node.getChild(idx), arr, pos+1, end);
  }

  int query(Node node, int[] arr, int pos, int end){
    if(pos==end)  return 0;

    int idx = arr[pos];
    if(!node.hasChild(idx))  return 0;

    return 1 + query(node.getChild(idx), arr, pos+1, end);
  }

}


class Solution {
    public int findLength(int[] nums1, int[] nums2) {
        Trie t = new Trie();
        for(int i=0;i<nums1.length;i++) 
          t.insert(t.root, nums1, i, nums1.length);

        int maxi=0;
        
        for(int i=0;i<nums2.length;i++) 
          maxi = Math.max(maxi, t.query(t.root, nums2, i, nums2.length));

        return maxi;


    }
}
