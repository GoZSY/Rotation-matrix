/****************************************************************
方法一、以副对角线为轴进行交换，然后上下对称的行交换
*****************************************************************/
int temp;
for(int i=0;i<n/2;i++){
    for(int j=i;j<n-1-i;j++){
        temp = mat[i][j];
        mat[i][j]=mat[n-j-1][i];
        mat[n-j-1][i]=mat[n-i-1][n-j-1];
        mat[n-i-1][n-j-1]=mat[j][n-i-1];
        mat[j][n-i-1]=temp;
    }
 
}
return mat;
/****************************************************************
方法二、将矩阵看成层次结构，每一层进行各自的转移，注意下标的对应关系即可
*****************************************************************/
vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
    // write code here
    int i,j,temp=0;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n/2;j++)
        {
            temp=mat[i][j];
            mat[i][j]=mat[i][n-1-j];
            mat[i][n-1-j]=temp;
        }
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n-i;j++)
        {
            temp=mat[i][j];
            mat[i][j]=mat[n-1-j][n-1-i];
            mat[n-1-j][n-1-i]=temp;
        }
    }
    return mat;
}
