#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
bool check(vector<int>& vec, vector<int>& out, int n){
    if(out.size() < n-1)
        return false;
    int i = 0;
    stack<int> stack;
    for(; i<n&&vec[i] != out[0]; ++i){
        stack.push(vec[i]);
        if(i == n-1)
            return false;
    }
    int pos = i;
    for(int j=1; j<n; ++j){
        if(!stack.empty() && out[j] == stack.top()){  //都不匹配，j++了之后，那么stack里面肯定有多余元素
            stack.pop();
        }
        else{
            int k=pos+1;
            for(; k<n && vec[k] != out[j]; ++k){
                if(k==n-1)
                    return false;
                stack.push(vec[k]);
            }
            pos = k;
        }
    }
	if (stack.empty())  //error...last:这个不为空，说明有多次不匹配，，，
		return true;
	else
		return false;
}

void deal(vector<int> &vec, vector<vector<int>> &ans, vector<int> out, int pos, int n){
    if(pos == n-1){
		if (check(out, vec, n)){
			ans.push_back(vec);
			/*//错误1.
			if(check(vec,out, n))
			ans.push_back(out);*/
			//return ;
			for (auto it : vec)
			{
				cout << it << " ";
			}
		}
		cout << ".......\n";
    }
    for(int i=pos; i<n; ++i){
        swap(vec[i], vec[pos]);
        deal(vec, ans, out, pos+1 ,n);
        swap(vec[i], vec[pos]);
    }
   /* for(int i=0; i<n; ++i){
        for( int j=i; j<n; ++j){
            swap(vec[i], vec[j]);
            deal(vec, ans, out, pos+1 ,n);
            swap(vec[i], vec[j]);
        }
    }
    */
}
int main(){
    int n;
    while(cin >> n){
        if(n<=0)
            continue;
        vector<int>  vec(n, 0);
        for(int i=0; i<n; ++i)
            cin >> vec[i];
        vector<vector<int>> ans;
        vector<int> out;
        //错误2.
        //deal(vec, ans, out, 0, n); //out是空的，，最后放入结果始终是空的，导致提示说没有循环处理，这个可能是一个没有
        deal(vec, ans, vec, 0, n);
        sort(ans.begin(), ans.end());
        for(int i=0; i<ans.size(); ++i){
            int j=0;
            for(; j< n-1; ++j)
                cout << ans[i][j] <<' ';
            cout << ans[i][j] <<endl; //j+1
        }
        ans.clear();
    }
    return 0;
}






/*#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
bool IsPopOrder(vector<char> pushV,vector<char> popV) {
        if(popV.size()==0) return false;   
        stack<int> st;
        int pos=0,i,flag=0;;   
        for(i=0;i<pushV.size()&&pushV[i]!=popV[0];i++){  
            st.push(pushV[i]);
            if(i==pushV.size()-1)
                return false;
        }
        pos=i;   
        for(int j=1;j<popV.size();j++){
            if((!st.empty())&&popV[j]==st.top()){
                  st.pop();
            } 
            else{
                 for(i=pos+1;i<pushV.size()&&pushV[i]!=popV[j];i++){
                    flag=1;
                    st.push(pushV[i]);
                     if(i==pushV.size()-1)
                        return false;
                }
                pos=i;
            }
        }
        if(st.empty())   
            return true;
        else
            return false;
}
void getAns(vector<vector<char> > &ans,vector<char> array,vector<char>pushV,int pos){
    if(pos==array.size()-1){
        if(IsPopOrder(pushV,array))
            ans.push_back(array);
    }else{
        for(int i=pos;i!=array.size();i++){
            int num=array[i];
            array[i]=array[pos];
            array[pos]=num;//先交换array[pos]与array[i]的值。
            getAns(ans,array,pushV,pos+1);
            num=array[i];//递归结束时，再将值交换回来。
            array[i]=array[pos];
            array[pos]=num;
        }
    }
}
int main(){
    int N; 
      vector<vector<char> >ans; 
    while(cin>>N){ 
       vector<char> array(N);    
       for(int i=0;i<N;i++)
           cin>>array[i];
       int pos=0;
       getAns(ans,array,array,pos);
       sort(ans.begin(),ans.end());
       for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size()-1;j++)
                 cout<<ans[i][j]<<' ';
              cout<<ans[i][ans[i].size()-1]<<endl;  
       }
       ans.clear();
    }
    return 0;
}
*/
