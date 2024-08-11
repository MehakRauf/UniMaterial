#recursive function to implement towerOfHanoi
def towerOfHanoi(n, source_rod,helper_roder,destination_rod):
    #baseCase
    if(n==1):
        print("Disk ", n , " moved from ", source_rod, " to ", destination_rod)
        #means last disk was moved so return 
        return
    #calling the function recusrivesly by changing the location
    towerOfHanoi(n-1,source_rod, destination_rod, helper_roder)
    #printing what we have moved
    print("Disk ", n , " moved from ", source_rod, " to ", destination_rod)
    #calling the function recusrivesly by changing the location
    towerOfHanoi(n-1, helper_roder, source_rod, destination_rod)

#Taking the number of disks input
n=int(input("Enter the number of disk: "))
#calling the function
towerOfHanoi(n,"A","B","C")

    