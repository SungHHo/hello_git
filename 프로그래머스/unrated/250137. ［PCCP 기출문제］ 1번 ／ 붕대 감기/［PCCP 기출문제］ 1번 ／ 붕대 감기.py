def solution(bandage, health, attacks):
    t, x, y = bandage
    time, heal, cnt = 0, health, 0
    attack_dict = {a: d for a, d in attacks}
    while True:
        if time in attack_dict:
            if heal - attack_dict[time] <= 0:
                return -1
            heal -= attack_dict[time]
            cnt = 0
        else:
            cnt += 1
            heal += x
            if cnt == t:
                heal += y
                cnt = 0
            if heal > health:
                heal = health
        time += 1
        if time > attacks[-1][0]:
            break
    return heal
