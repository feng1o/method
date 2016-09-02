//http://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&tqId=11218&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
    	if(str == nullptr)
            return true;
        if(matrix == nullptr || rows < 1 && cols < 1)
            return false;
  
        char *trav = new char[cols*rows]() ; //{0} error
        memset(trav, 0, sizeof(char)*cols*rows);
        /*for(int i=0;i<rows ; ++i){
            for(int j=0; j<cols; ++j){
                trav[i*cols + j] = 0;
            }
        }*/
		//int len = 0;
        int i=0;
        //int j=0;
        for(; i<rows; ++i){
            int j=0;
            for(;j<cols;++j){
              //  len = 0;
                if(matrix[i*cols + j] == str[0])//如果使用进去就保证对，，
                if(rpath(matrix, i, j, rows, cols, str, trav, 0))
                     return true;
            }
        }
        delete trav;
        return false;
       /* for(;i<rows && !flag; ++i){//这个思路是错的....
            for(; j<cols; ++j){
                if(*str == matrix[i*cols + j]){
                    flag = true;
                    break;}
            }
        }
        if(flag == false)
            return false;
        char *trav = new char[cols*rows]() ; //{0} error
        for(int i=0;i<rows ; ++i){
            for(int j=0; j<cols; ++j){
                trav[i*cols + j] = 0;
            }
        }
        //trav[i][j] = -1;
        int len = 0;
        return rpath(matrix, i, j, rows, cols, str, trav, len);*/
    }

    //        if(matrix[i*cols + j] == str[0])//如果使用进去就保证对，，加这个。。。。才对
   bool rpath(char* matrix, int i, int j, int rows, int cols, char* str, char *trav, int len){

    if(i < 0 || j <0 || i>=rows || j>= cols )//进来保证是ok的；|| trav[i*cols + j] == -1 || matrix[i*cols + j] != str[len]
        return false;
    else{
      if(str[len+1] == '\0')
         return true;
      trav[i*cols +j] =  -1;
		if(trav[(i+1)*cols + j] != -1 && matrix[(i+1)*cols + j] == str[len+1])
          if(rpath(matrix, i+1, j, rows, cols, str, trav, len+1))
            return true;
       if(trav[(i-1)*cols + j] != -1 && matrix[(i-1)*cols + j] == str[len+1])
           if(rpath(matrix, i-1, j, rows, cols, str, trav, len+1))
            return true;
		if(trav[i*cols + j+1] != -1 && matrix[i*cols + j+1] == str[len+1])
           if(rpath(matrix, i, j+1, rows, cols, str, trav, len+1))
            return true;
        if(trav[i*cols + j-1] != -1 && matrix[i*cols + j-1] == str[len+1])
         if(rpath(matrix, i, j-1, rows, cols, str, trav, len+1))
            return true;
        trav[i*cols +j] =  0; 
        return false;
    }
}
//bool rpath(char* matrix, int i, int j, int rows, int cols, char* str, char trav[][cols], int len){
  bool rpath2(char* matrix, int i, int j, int rows, int cols, char* str, char *trav, int len){

    if(i < 0 || j <0 || i>=rows || j>= cols || trav[i*cols + j] == -1 || matrix[i*cols + j] != str[len])
        return false;
    //if(len == strlen(str)-1 )
      if(str[len+1] == '\0')
         return true;
    trav[i*cols +j] =  -1;
    //bool  rf = false;
        if(rpath2(matrix, i+1, j, rows, cols, str, trav, len+1) || 
            rpath2(matrix, i, j+1, rows, cols, str, trav, len+1) || 
            rpath2(matrix, i-1, j, rows, cols, str, trav, len+1) || 
            rpath2(matrix, i, j-1, rows, cols, str, trav, len+1))
            return true;
   // }
      else
    	trav[i*cols +j] =  0;    //只有某个点没走过去的时候，才会恢复上一步的，不是所有的都要恢复，，，走过了，又能通过，不应该恢复   
    return false;
}
    
    
    
    
    
    
    
    bool rpath111111(char* matrix, int i, int j, int rows, int cols, char* str, char *trav, int len){

    if(i < 0 || j <0 || i>=rows || j>= cols || trav[i*cols + j] == -1 || matrix[i*cols + j] != *(str+len))
        return false;

     if(len == strlen(str)-1 )
         return true;
    /*if(len < strlen(str) && matrix[i*cols + j] == *(str+len) && trav[i*cols + j] == 0){
        ++len;
        trav[i*cols + j] = -1;
        if( *(str+len)=='\0')  //出错，，why？？？
            return true;
    }*/
    trav[i*cols +j] =  -1;
    bool  rf = false;
   // for(int k=0; k<4; ++k){
       /* switch(k){
            case 0:
        }*/
        rf = rpath(matrix, i+1, j, rows, cols, str, trav, len+1) || \
            rpath(matrix, i, j+1, rows, cols, str, trav, len+1) || \
            rpath(matrix, i-1, j, rows, cols, str, trav, len+1) || \
            rpath(matrix, i, j-1, rows, cols, str, trav, len+1);
   // }
    trav[i*cols +j] =  0;      
    return rf;
}


}; 
    
    
    
    
    
    bool rpath111111(char* matrix, int i, int j, int rows, int cols, char* str, char *trav, int len){

    if(i < 0 || j <0 || i>=rows || j>= cols || trav[i*cols + j] == -1 || matrix[i*cols + j] != *(str+len))
        return false;

     if(len == strlen(str)-1 )
         return true;
    /*if(len < strlen(str) && matrix[i*cols + j] == *(str+len) && trav[i*cols + j] == 0){
        ++len;
        trav[i*cols + j] = -1;
        if( *(str+len)=='\0')  //出错，，why？？？
            return true;
    }*/
    trav[i*cols +j] =  -1;
    bool  rf = false;
   // for(int k=0; k<4; ++k){
       /* switch(k){
            case 0:
        }*/
        rf = rpath(matrix, i+1, j, rows, cols, str, trav, len+1) || \
            rpath(matrix, i, j+1, rows, cols, str, trav, len+1) || \
            rpath(matrix, i-1, j, rows, cols, str, trav, len+1) || \
            rpath(matrix, i, j-1, rows, cols, str, trav, len+1);
   // }
    trav[i*cols +j] =  0;      
    return rf;
}


};
#endif