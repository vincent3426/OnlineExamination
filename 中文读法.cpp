class Solution(object):
    def chinese_reading(self, x):
        dic = {1: 'yi', 2: 'er', 3: 'san', 4: 'si', 5: 'wu', 6: 'liu',
               7: 'qi', 8: 'ba', 9: 'jiu', 0: 'ling'}
        unit = ['qian', 'bai', 'shi']
        k = 1000
        ret = ''
        l = [0 for x in range(4)]
        for i in range(4):
            l[i] = int(x / k)
            if i == 3 or l[i] == 0 :
                ret += dic[l[i]]
            else:
                ret += (dic[l[i]] + unit[i])
            x -= l[i] * k
            k = (k / 10)
        cnt = 0
        i = 0
        while l[i] == 0:
            cnt += 1
            i += 1
        return ret[4*cnt:]

tmp = Solution()
while True:
    try:
        x = int(input())
        print(tmp.chinese_reading(x))
    except EOFError:
        break
