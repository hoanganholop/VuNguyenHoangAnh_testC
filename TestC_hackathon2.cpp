#include<stdio.h>

int main(){
	int choice;
	int n;
	int arr[n][n];
	
	while(1){
		printf("\nMenu\n");
	    printf("1.Nhap kich co va gia tri cac phan tu cua mang\n");
	    printf("2.In cac phan tu cua mang theo ma tran\n");
	    printf("3.In ra cac phan tu co tren duong bien va tinh tich\n");
	    printf("4.In ra cac phan tu tren duong cheo chinh\n");
	    printf("5.In ra cac phan tu tren duong cheo phu\n");
	    printf("6.Sap xep duong cheo chinh theo thu tu tang dan\n");
	    printf("7.Tim kiem 1 phan tu va in ra vi tri phan tu do trong mang\n");
	    printf("8.Thoat\n");
	    printf("Lua chon cua ban: ");
	    scanf("%d", &choice);
	    if(choice==8){
	    	printf("Ket thuc chuong trinh\n");
	    	break;
		}
		switch(choice){
			case 1:
				printf("Nhap so hang va cot: ");
				scanf("%d",&n);
				for(int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						printf("Phan tu thu [%d][%d] la: ", i,j);
						scanf("%d", &arr[i][j]);
					}
				}
				break;
			case 2:
			    for(int i=0;i<n;i++){
			    	for(int j=0;j<n;j++){
			    		printf("%5d", arr[i][j]);
					}
					printf("\n");
				}
				break;
			case 3:
				long long result;
				result=1;
				printf("Cac phan tu nam tren duong bien la:");
				for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                            printf("%d ", arr[i][j]);
                            result *= arr[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu tren duong bien: %d\n", result);
                break;
			case 4:
				printf("Cac phan tu nam tren duong cheo chinh: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;
			case 5:
				printf("Cac phan tu nam tren duong cheo phu: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i][n-i-1]);
                }
                printf("\n");
                break;
				
			case 7:	
			    int findIndex;
			    int found;
			    found = 0;
			    printf("Nhap phan tu can tim: ");
			    scanf("%d", &findIndex);
			    printf("Vi tri cua phan tu can tim la: ");
			    for(int i=0;i<n;i++){
			    	for(int j=0;j<n;j++){
			    		if(arr[i][j]==findIndex){
			    			printf("[%d][%d]",i,j);
			    			found=1;
						}
					}
				}
				if(!found){
					printf("Khong tim thay phan tu trong mang\n");
				}
				break;
			default:
			    printf("Lua chon khong hop le");
				break;	
		}
	}
	return 0;
}
