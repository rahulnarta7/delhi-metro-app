#include<bits/stdc++.h>
using namespace std;


unordered_map<int,string> mp1;
unordered_map<string, string> normal;
unordered_map<string, vector<pair<string, int>>> graph;

    void addEdge(string u, string v, int w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}
    string normalize(const string &str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    result.erase(remove(result.begin(), result.end(), ' '), result.end());
    return result;
}

//initial the edge
    void initial(){
    addEdge("sikandarpur-y", "hauz khas-yv", 14);
    addEdge("hauz khas-yv", "rajiv chowk-yb", 10);
    addEdge("hauz khas-yv", "janakpuri-b", 25);
    addEdge("hauz khas-yv", "botanical graden-yb", 5);
    addEdge("rajiv chowk-yb", "new delhi-yo", 1);
    addEdge("rajiv chowk-yb", "noida52-b", 19);
    addEdge("rajiv chowk-yb", "kirti nagar-b", 7);
    addEdge("new delhi-yo", "kashmiri gate-yrv", 2);
    addEdge("new delhi-yo", "shivaji stadium-o", 1);
    addEdge("janakpuri-b", "dwarka-b", 5);
    addEdge("botanical graden-yb", "noida52-b", 4);
    addEdge("kirti nagar-b", "ashok park-g", 2);
    addEdge("shivaji stadium-o", "dwarka21-bo", 18);
    addEdge("dwarka-b", "dwarka21-bo", 9);
    addEdge("ashok park-g", "inderlok-r", 1);
    addEdge("inderlok-r", "kashmiri gate-yrv", 5);
    for (const auto &it : graph) {
        string normali = normalize(it.first);
        normal[normali] = it.first;
    }
    }

//mtero station list
    void printlist(){
        int i=1;
        cout<<"-----------List of all stations------------"<<endl;
    for(auto it:mp1){
        cout<<i<<" "<<mp1[i]<<endl;
        i++;
    }
    cout<<"    ---------------"<<endl;
    cout<<"--------------------------------"<<endl;
    }


//metro map
   void metromap() {
    cout << "**************METRO MAP*************" << endl;
    for (auto it : graph) {
        cout << it.first << " =>" << endl;
        for (auto c : it.second) {
            cout << "\t " << c.first << " : " << c.second << " km" << endl;
        }
    }
    cout << "------------------------------------" << endl;
}

//tolower
    string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

//shortest distance
vector<string> getshortest() {
    cout << "Enter the START station: ";
    string start;
    cin.ignore();
    getline(cin,start);
    string nstart= normalize(start);

    cout << "Enter the DESTINATION station: ";
    string dest;
    //cin.ignore();
    getline(cin,dest);
    string ndest = normalize(dest);

    // Validate stations
    if (normal.find(nstart) == normal.end()) {
        cout << "Error: START station '" << start << "' does not exist.\n";
        return {};
    }
    if (normal.find(ndest) == normal.end()) {
        cout << "Error: DESTINATION station '" << dest << "' does not exist.\n";
        return {};
    }
    string ostart=normal[nstart];
    string odest=normal[ndest];
    unordered_map<string, int> dist;
    unordered_map<string, string> parent;
    for (const auto &node : graph) {
        dist[node.first] = INT_MAX;
    }
    dist[ostart] = 0;

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> pq;
    pq.push({0, ostart});

    while (!pq.empty()) {
        int w = pq.top().first;
        string nn = pq.top().second;
        pq.pop();

        for (const auto &[nb, we] : graph[nn]) {
            int wn = w + we;
            if (dist[nb] > wn) {
                dist[nb] = wn;
                pq.push({dist[nb], nb});
                parent[nb] = nn;
            }
        }
    }

    vector<string> path;
    for (string at = odest; at != ""; at = parent[at]) {
        path.push_back(at);
        if (at == ostart) break;
    }

    if (path.back() != ostart) {
        cout << "No path exists between " << ostart << " and " << odest << ".\n";
        return {};
    }
    int total=dist[odest];
     cout<<"=>"<<endl;
    cout<<"Total distance is"<<" "<<total<<"km"<<endl;
    reverse(path.begin(), path.end());

    return path;
}

//meaning
    void meaning(){
    cout<<"-------Meaning of y,r,v,o,b-------"<<endl;
    cout<<"y=yellow line"<<endl;
    cout<<"r=red line"<<endl;
    cout<<"v=violet line"<<endl;
    cout<<"o=orange line"<<endl;
    cout<<"b=blue line"<<endl;
    cout<<"yv=station in yellow and violet line"<<endl;
    }

//open close time
    void openclose(){
    cout<<"Choose the metro station by their serial number for opening and closing time"<<endl;
    cout<<"Enter the number 1-14"<<endl;
    int n;
    cin>>n;
    if(n>14 || n<1)cout<<"enter the option 1-14"<<endl;
    cout<<"The opening and closing time of"<<" "<<mp1[n]<<" "<<"is"<<" "<<"5:00AM-11:00PM"<<endl;
    }


//main function
int main(){
    initial();
    mp1[1]="sikandarpur-y";
    mp1[2]="hauz khas-yv";
    mp1[3]="rajiv chowk-yb";
    mp1[4]="new delhi-yo";
    mp1[5]="kashmiri gate-yrv";
    mp1[6]="janakpuri-b";
    mp1[7]="botanical garden-yb";
    mp1[8]="noida52-b";
    mp1[9]="kirti nagar-b";
    mp1[10]="shivaji stadium-o";
    mp1[11]="inderlok-r";
    mp1[12]="dwarka-b";
    mp1[13]="dwarka21-bo";
    mp1[14]="ashok park-g";


    cout<<"-----------WELCOME TO DELHI METRO APP------------"<<endl;
while(true){
    cout<<"        ~LIST OF ALL ACTIONS~"<<endl;
    cout<<"1. LIST OF ALL STATIONS" <<endl;
    cout<<"2. SHOW THE METRO MAP" <<endl;
    cout<<"3. GET SHORTEST PATH WITH STATIONS"<<endl;
    cout<<"4. OPENING AND CLOSING TIME OF STATIONS"<<endl;
    cout<<"5. MEANING OF y,r,v,o,b"<<endl;
    cout<<"6. EXIT"<<endl;
    cout<<"ENTER NUMBER BETWEEN 1-6"<<endl;
    int choice=0;
    cin>>choice;
    if(choice==6)break;
    switch(choice){
    case 1:
        printlist();
        break;
    case 2:
        metromap();
        break;
    case 3:{


      vector<string> path=getshortest();
      if(!path.empty()){
      cout<<"YOUR SHORTEST PATH IS HERE:"<<endl;
        for (int i = 0; i < path.size() - 1; ++i) {
        cout << path[i] << " -> ";
        }
        cout << path.back() << endl;

      }
            break;
    }
    case 4:
        openclose();
        break;
    case 5:
        meaning();
        break;
    default :
        cout<<"Enter valid option between 1-6 !"<<endl;

    }
    cout<<"*********************************************"<<endl;
}
return  0;
}
