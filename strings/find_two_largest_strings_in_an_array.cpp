vector<string> f(vector<string> strings){
    int n = strings.size();
    string largest1 = "",  largest2 = "";

    fo(i,n){
        string temp;
        cin>>temp;

        if(largest1 == ""){
            largest1 = temp;
        }else if(largest2 == ""){
            largest2 = temp;
        }else if(temp.length() > largest1.length()){
            string temp2 = largest1;
            largest1 = temp;
            if(temp2.length() > largest2.length()){
                largest2 = temp2;
            }
        }else if(temp.length() > largest2.length()){
            largest2 = temp;
        }
    }

    return {largest1,largest2};
}