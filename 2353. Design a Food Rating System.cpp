class FoodRatings {
public:

    struct Food{
      int rating;
      string name;

      Food(){rating=0, name="";}

      Food(string nm, int r){rating = r; name = nm;}

      bool operator<(const Food& f2) const{
        if(rating == f2.rating)  return name < f2.name;
        return rating > f2.rating;
      }
    };

    unordered_map<string,Food> food_map;
    unordered_map<string,string> food_to_cuis;
    unordered_map<string,set<Food>> cuis_map;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        food_map.clear();
        food_to_cuis.clear();
        cuis_map.clear();

        int n = foods.size();
        for(int i=0;i<n;i++){
          string c = cuisines[i];
          string f = foods[i];
          int r = ratings[i];

          Food food = Food(f,r);
          
          food_map[f] = food;
          food_to_cuis[f] = c;
          
          if(cuis_map.count(c)==0)  cuis_map[c] = set<Food>();
          cuis_map[c].insert(food);
        }

        // s.insert(Food(5,"rice"));
        // s.insert(Food(15,"pizza"));
        // s.insert(Food(2,"curry"));

        // s.erase(Food(15,"pizza"));

        // for(auto u: s){
        //   cout<<u.name<<" "<<u.rating<<endl;
        // }
    }
    
    void changeRating(string f, int newRating) {
        Food &food = food_map[f];
        string c = food_to_cuis[f];
        
        
        cuis_map[c].erase(food);
        food.rating = newRating;
        cuis_map[c].insert(food);
        //food_map[f] = food;  since we have taken reference &food, no need to reassign
    }
    
    string highestRated(string c) {
        Food f = *cuis_map[c].begin();
        return f.name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
 
