#include<stdio.h>
#include<stdbool.h>

// Ham kiem tra so nguyen to
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
	int n;
	int arr[100];
	int choice;
	int max=0;
	while(1){
		printf("\nMenu\n");
		printf("1.Nhap so phan tu can nhap va gia tri phan tu\n");
		printf("2.In ra gia tri cac phan tu dang quan ly\n");
		printf("3.In ra gia tri lon nhat cua mang\n");
		printf("4.In ra cac phan tu la so nguyen to\n");
		printf("5.Them 1 phan tu vao trong mang\n");
		printf("6.Xoa mot phan tu trong mang\n");
		printf("7.Sap xep mang theo thu tu tang dan\n");
		printf("8.Tim kiem vi tri phan tu(nguoi dung nhap) va in ra vi tri index cua phan tu do\n");
		printf("9.Thoat\n");
		scanf("%d",&choice);
		
		if(choice==9){
			printf("Ket thuc chuong trinh");
			break;
		}
		switch(choice){
			case 1: //Nhap so phan tu can nhap va gia tri phan tu
				printf("Nhap so phan tu:");
				scanf("%d",&n);
				for(int i=0;i<n;i++){
					printf("Phan tu thu %d: ",i+1);
					scanf("%d", &arr[i]);
				}
				break;
			case 2: //In ra gia tri cac phan tu dang quan ly
			    printf("Cac phan tu dang quan ly la: ");
				for(int i=0;i<n;i++){
			    	printf("%d\t", arr[i]);
				}
				break;
			case 3: //In ra gia tri lon nhat cua mang
			    for(int i=0;i<n;i++){
			    	if(max<arr[i]){
			    		max = arr[i];
					}
				}
				printf("Phan tu lon nhat trong mang la: %d", max);
				break;
		    case 4: //In ra cac phan tu la so nguyen to
		        printf("Cac phan tu la so nguyen to la: ");
                for (int i=0;i<n;i++) {
                    if (isPrime(arr[i])) {
                        printf("%d ", arr[i]);
                    }
				}
				break;
			case 5: //Them 1 phan tu vao trong mang
			    if(n>=100){
			    	printf("Mang da day khong the them");
			    	break;
				}
				int newValue, position;
			    printf("Nhap phan tu muon them: ");
			    scanf("%d",&newValue);
			    printf("Nhap vi tri muon them: ");
			    scanf("%d", &position);
			    if(position<0||position>n){
			    	printf("Vi tri khong hop le");
			    	break;
				}
				for(int i=n;i>position;i--){
					arr[i]=arr[i-1];
				}
				arr[position]= newValue;
				n++;
				break;
			case 6: //Xoa mot phan tu trong mang
			    printf("Nhap vi tri can xoa (0 den %d): ", n-1);
                scanf("%d", &position);
                if (position < 0 || position > n) {
                    printf("Vi tri khong hop le.\n");
                    break;
                }
                for (int i=position;i<n-1;i++) {
                    arr[i]=arr[i + 1];
                }
                n--;
                break;
			case 7: //Sap xep mang theo thu tu tang dan
			    printf("Mang sau khi duoc sap xep la: ");
				for(int i=0;i<n-1;i++){
					for(int j=0;j<n-i-1;j++){
						if(arr[j]>arr[j+1]){
							int temp=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]= temp;
						}
					}
				}
				for(int i=0; i<n-1; i++){
					printf("%d\t", arr[i]);
				}
				break;
			case 8: //Tim kiem vi tri phan tu(nguoi dung nhap) va in ra vi tri index cua phan tu do
			    int findIndex;
			    int found;
				printf("Nhap phan tu can tim: ");
				scanf("%d",&findIndex);
				found=0;
				for(int i=0;i<n;i++){
					if(arr[i]==findIndex){
						printf("Phan tu can tim o vi tri: %d", i);
						found=1;
					}
				}
				if(found!=1){
					printf("Phan tu can tim khong ton tai trong mang");
				}   
				break; 
		    default:
			    printf("Lua chon khong hop le hay chon lai.\n");
				break;    
		}
		
	}
	return 0;
}
