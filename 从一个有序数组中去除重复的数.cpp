#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��һ�������������Ƴ��ظ����ֵ�����
void StrDel(int * ps, int x)
{
	int str = 0;
	int dst = 0;
	int cur = 1;
	//�ȶ��嶼�ڳ�ʼλ�õ�str��tmp,str���ڱ�����������,tmp���ڼ�¼û���ظ����ֵ�����
	//�������ʹ��str+1����ô���str+1����Խ��,����˵��Ҫ���ⶨ��һ������cur����str+1
	while (cur < x)
	{
		if (ps[str] != ps[cur])
			//������if (ps[str] != ps[str+1])����Խ��ָ��ĵط�
		{
			ps[dst] = ps[str];
			str++;
			dst++;
			cur++;
		}
		else{
			str++;
			cur++;
		}
		//��������е�һ���͵ڶ�����ȣ�
		//��ôtmp����,str����������������
		//�������ȣ���ô�Ͱѵ�һ�����ָ���tmp��Ҳ���ǵ�һ��λ�ã�����ͬʱ����++
		//�Դ�����
	}
	//�����������һ���ж���ʱ��strָ��������鵹���ڶ���,curָ��������һ����
	//����˵�������,����ͬʱ�Ӽ�,û�и��κ�ֵ��strָ�����һ���������ʱps[cur]���Խ�磬
	//���Ǵ�ʱ�Ѿ������ж��ˣ���ʱ�ٽ����һ��Ԫ�ظ���dst
	//����˵���߲���ȣ�����if�У��������ڶ�������dst,Ȼ���ٽ�������һ������dst
	ps[dst] = ps[str];
	dst++;
	str++;
	
	for (int i = 0; i < dst; i++)
	{
		printf("%d ", ps[i]);
	}
}


int main(){
	int arr[] = { 1, 1, 2, 2, 3, 3, 4, 5, 6, 7, 7 ,7,8,8};
	int Size = sizeof(arr) / sizeof(arr[0]);
	StrDel(arr, Size);
}