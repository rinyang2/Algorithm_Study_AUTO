print(*[(lambda y: str(y//3600)+" "+str((y%3600)//60)+" "+str(y%60))((lambda x: (x[3]-x[0])*3600+(x[4]-x[1])*60+x[5]-x[2])(list(map(int,input().split())))) for _ in range(3)],sep='\n')