Link - https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparison(Job a, Job b){
        return (a.profit > b.profit);
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        //sort on the basis of profit
        sort(arr,arr+n, comparison);
        int maxi = arr[0].dead;
        //find the maximum deadline available for any job
        for(int i=1;i<n;i++){
            maxi = max(maxi, arr[i].dead);
        }
        //make the slot array with maximum deadline available for it
        int slot[maxi+1];
        //initialise it with -1
        for(int i=0;i<=maxi;i++){
            slot[i] = -1;
        }
        int countJobs= 0, jobProfit = 0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            //we will start putting the jobs from the end of their deadline
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j] == -1){
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        ans.push_back(countJobs);
        ans.push_back(jobProfit);
        
        return ans;
        
    } 
};
