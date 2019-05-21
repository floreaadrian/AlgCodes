t = int(input())
days = ["saturday", "sunday", "monday",
        "tuesday", "wednesday", "thursday", "friday"]
while(t > 0):
    line = input().split(" ")
    s = str(line[0])
    e = str(line[1])
    l = int(line[2])
    r = int(line[3])
    if (s == e):
        if(r-l == 0):
            print(1)
        elif ((r-l) % 7 == 0):
            print("many")
        else:
            print("impossible")
    else:
        nr_of_days = 0
        s_index = days.index(s)
        e_index = days.index(e)
        if(s_index < e_index):
            nr_of_days = e_index - s_index + 1
        else:
            nr_of_days = s_index - e_index + 2

        if(l > nr_of_days and r < nr_of_days + 7):
            print("impossible")
        elif(r < nr_of_days):
            print("impossible")
        elif(r-l <= 7):
            print(nr_of_days)
        else:
            print("many")
    t = t - 1
