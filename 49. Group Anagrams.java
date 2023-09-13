class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
      Map<String,List<String>> map = new HashMap();
      for(String str: strs){
        char[] chars = str.toCharArray();
        Arrays.sort(chars);
        String sortedString = new String(chars);
        
        if(!map.containsKey(sortedString))
          map.put(sortedString, new ArrayList());
        map.get(sortedString).add(str);
      }

      List<List<String>> ret = new ArrayList();
      for(List<String> list: map.values()){
        ret.add(list);
      }

      return ret;
    }
}
