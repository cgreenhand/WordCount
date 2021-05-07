#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    FILE* fp;
    int cnt = 0;
    if ((fp = fopen(argv[2], "r")) == NULL)
    {
        puts("error!\n");
        return 0;
    }
    if (argv[1][1] == 'w')
    {
        char c;
        while ((c = fgetc(fp)) != EOF) cnt++;
        printf("字符数=%d", cnt);
    }
    else if (argv[1][1] == 'c') // 统计字符
    {
        char buff[1024];
        while (fscanf(fp, "%s", buff) != EOF)
        {
            cnt++;
            for (int i = 1; i < strlen(buff) - 1; i++)
                if (buff[i] == ',' && buff[i - 1] != ',' && buff[i + 1] != ',')
                    cnt++;
        }
        printf("单词数=%d\n", cnt);
    }
    fclose(fp);
    return 0;
}
