//part1
double median(int a[], int b[], int sizeA, int sizeB){
    int totalSize=sizeA+sizeB;
    double firstNumber;
    double secondNumber;
    int arr[totalSize];
    double median;

    for (int i=0;i<=sizeA;i++){
        scanf("%d",a[i]);
        arr[i]=a[i];
    }
    int l;
    l=sizeA;
    for(int j=0;j<=sizeB;j++){
        scanf("%d",b[j]);
        arr[l++]=b[j];
    }

    for(int i=0;i<totalSize;i++){
        int temp;
        for(int j=i+1;j<totalSize;j++){
            if(arr[j]<arr[i]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }

    if(totalSize%2 == 0){
        firstNumber = arr[(totalSize/2) - 1];
        secondNumber = arr[totalSize/2];
        median = (firstNumber+secondNumber)/2;
    }

//part2
void longestSequence(int a[], int sizeA){
    int len1=1;
    int finalLength=1;
    int firstNumber;
    int lastNumber;

    for(int i=0, j=1;i<=sizeA-1&&j<=sizeA;i++,j++){
        if(a[i]<a[j]){
            len1++;
            if(j==(sizeA-1)){     
                if(len1>finalLength){
                    lastNumber=j;
                    finalLength=len1;
                    firstNumber=j+1-finalLength;
                    len1=1;
                }
            }
        }
        else{
            if(len1>finalLength){
                    lastNumber=i;
                    finalLength=len1;
                    firstNumber=i+1-finalLength;
                    len1=1;
                }else{
                    len1=1;
                }
            } 
        }
    printf("Longest sequence is ");
    for(int i=firstNumber;i<=lastNumber;i++){
        printf("%d",a[i]);
        if(a[i]<a[lastNumber]){
            printf(", ");
        }
        else if(a[i]==a[lastNumber]){
            printf(".");
        }
    }
}
	
    if(totalSize%2 != 0){
        median = arr[(totalSize-1)/2];
    }
    return median;
}

//part3
void longestMutualSequence(int firstArr[], int secondArr[], int sizeA, int sizeB){
    int len1=1;
    int finalLength=1;
    int firstNumber;
    int lastNumber;
    
    for(int i=0;i<sizeA;i++){
        for(int j=0;j<sizeB;j++){
            if(firstArr[i]==secondArr[j]){
                int k=i;
                int n=j;
                for(int c=k,d=n;c<sizeA&&d<sizeB;c++,d++){
                    if(firstArr[c+1]==secondArr[d+1]&&(c+1)<sizeA&&(d+1)<sizeB){
                        len1++;
                    }else{
                        if(len1>finalLength){
                            finalLength=len1;
                            lastNumber=c;                          
                            firstNumber=c+1-finalLength;
                            len1=1;
                        }else{
                            len1=1;
                        }
                    }
                }
            }
        } 
    }   
    printf("Longest common sequence is ");
    for(int i=firstNumber;i<=lastNumber;i++){
        printf("%d",firstArr[i]);
        if(i==lastNumber){
            printf(".");
        }
        else{
            printf(", ");
        }
    }
}           
