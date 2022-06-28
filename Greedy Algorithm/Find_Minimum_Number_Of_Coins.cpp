Link - https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

int findMinimumCoins(int amount) 
{
    // Write your code here
    int ans = 0;
    int values[] = {1,2,5,10,20,50,100,500,1000};
    
    for(int i= 8;i>=0;i--){

        while(amount >= values[i]){
            amount -= values[i];
            ans++;
        }
    }
    return ans;
    
}
