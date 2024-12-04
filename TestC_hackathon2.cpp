#include<stdio.h>

int main(){
	int choice;
	int rows, cols;
	int arr[100][100];
	
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
				printf("Nhap so hang: ");
				scanf("%d",&rows);
				printf("Nhap so cot: ");
				scanf("%d",&cols);
				for(int i=0;i<rows;i++){
					for(int j=0;j<cols;j++){
						printf("Phan tu thu [%d][%d] la: ", i,j);
						scanf("%d", &arr[i][j]);
					}
				}
				break;
			case 2:
			    for(int i=0;i<rows;i++){
			    	for(int j=0;j<cols;j++){
			    		printf("%5d", arr[i][j]);
					}
					printf("\n");
				}
				break;
			case 3:
				long long result;
				result=1;
				printf("Cac phan tu nam tren duong bien la:");
				for (int i = 0; i < rows; i++) {
                    for (int j = 0; j < cols; j++) {
                        if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                            printf("%d ", arr[i][j]);
                            result *= arr[i][j];
                        }
                    }
                }
                printf("\nTich cac phan tu tren duong bien: %d\n", result);
                break;
			case 4:
				if(rows!=cols){
					printf("So hang va so cot khong bang nhau nen khong co duong cheo chinh");
					break;
				}
				printf("Cac phan tu nam tren duong cheo chinh: ");
                for (int i = 0; i < rows; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;
			case 5:
				if(rows!=cols){
					printf("So hang va so cot khong bang nhau nen khong co duong cheo phu");
					break;
				}
				printf("Cac phan tu nam tren duong cheo phu: ");
                for (int i = 0; i < rows; i++) {
                    printf("%d ", arr[i][rows-i-1]);
                }
                printf("\n");
                break;
			case 6:
				if(rows!=cols){
					printf("So hang va so cot khong bang nhau nen khong co duong cheo chinh");
					break;
				}
				int temp;
                int arr2[100];
               
                for (int i = 0; i < rows; ++i) {
                    arr2[i] = arr[i][i];
                }
                for (int i = 0; i < rows- 1; ++i) {
                    for (int j = 0; j < rows - i - 1; ++j) {
                       if (arr2[j] > arr2[j + 1]) {
                       int temp = arr2[j];
                       arr2[j] = arr2[j + 1];
                       arr2[j + 1] = temp;
                       }
                    }
                }
                for (int i = 0; i < rows; ++i) {
                arr[i][i] = arr2[i];
                }
                printf("Cac phan tu nam tren duong cheo chinh sap xep theo thu tu tang dan: ");
                for(int i=0;i<rows;i++){
    	        printf("%5d",arr[i][i]);
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
			    for(int i=0;i<rows;i++){
			    	for(int j=0;j<rows;j++){
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
