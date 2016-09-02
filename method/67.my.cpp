//http://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=11219&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#ifndef  aa
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int count = 0;
        if(rows < 1|| cols <1 || threshold < 0)
            return 0;
        bool *flag = new bool[cols * rows];
        memset(flag, false, cols*rows);
        
        return move(threshold, rows, cols, 0, 0, 0, flag);
        //delete flag;
        //return count;
            
    }
    
    int move(int threshold, int rows, int cols, int row, int col, int count, bool *flag){
        int index = row*cols + col;
        //int count = 0;
        if(col < 0 || col >= cols || row <0 || row >= rows ||flag[index] != 0 || !check(row, col, threshold)){
            return count;
        }
        else {
            flag[index] = -1; 
            //理解这个，与正确答案区别.....这里多加了很多次..............
           /* count = move(threshold, rows, cols, row+1, col, 0+1, flag) +
            move(threshold, rows, cols, row-1, col, 0+1,  flag)+
            move(threshold, rows, cols, row, col+1, 0+1,  flag)+
            move(threshold, rows, cols, row, col-1, 0+1, flag);*/
        
       count = 1+ move(threshold, rows, cols, row+1, col, 0, flag) +
            move(threshold, rows, cols, row-1, col, 0,  flag)+
            move(threshold, rows, cols, row, col+1, 0,  flag)+
            move(threshold, rows, cols, row, col-1, 0, flag);
            return count;
        } 
    }
    
    
    bool check(int row, int col, int threshold){
        int num = 0;
        while(row){
            num += row %10;
            row /= 10;
        }
        while(col){
            num += col%10;
            col /= 10;
        }
        if(num > threshold)
            return false;
        else 
            return true;
    }
};


/*class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int count = 0;
        if(rows < 1|| cols <1 || threshold < 0)
            return 0;
        bool *flag = new bool[cols * rows];
        memset(flag, false, cols*rows);
        
        return move(threshold, rows, cols, 0, 0,  flag);
        //delete flag;
        //return count;
            
    }
    
    int move(int threshold, int rows, int cols, int row, int col, bool *flag){
        int index = row*cols + col;
        int count = 0;
        if(col >= 0 && col < cols && row >= 0 && row < rows && flag[index] == 0 && check(row, col, threshold)){
       
         	flag[index] = -1;
        
       count = 1+ move(threshold, rows, cols, row+1, col, flag) +
            move(threshold, rows, cols, row-1, col, flag)+
            move(threshold, rows, cols, row, col+1, flag)+
            move(threshold, rows, cols, row, col-1,  flag);
        }
        return count;
    }
    
    
    bool check(int row, int col, int threshold){
        int num = 0;
        while(row){
            num += row %10;
            row /= 10;
        }
        while(col){
            num += col%10;
            col /= 10;
        }
        if(num > threshold)
            return false;
        else 
            return true;
    }
};*/
#endif