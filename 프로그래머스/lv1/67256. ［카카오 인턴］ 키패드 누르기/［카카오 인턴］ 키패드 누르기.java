class Solution {
    public String solution(int[] numbers, String hand) {
        int hd;
        if(hand.equals("right"))
            hd = 1;
        else
            hd = 0;
        int r = 11;
        int l = 10;
        char[] chArr = new char[numbers.length];
        for(int i = 0; i<numbers.length; i++)
        {
            if(numbers[i]==1||numbers[i]==4||numbers[i]==7)
            {
                chArr[i] = 'L';
                l = numbers[i];
            }   
            else if(numbers[i]==3||numbers[i]==6||numbers[i]==9)
            {
                chArr[i] = 'R';
                r = numbers[i];
            } 
            else
            {
                int len_L = distance(l, numbers[i]);
                int len_R = distance(r, numbers[i]);
                if(len_L>len_R)
                {
                    chArr[i] = 'R';
                    r = numbers[i];            
                }
                else if(len_L<len_R)
                {
                    chArr[i] = 'L';
                    l = numbers[i];
                }
                else
                {
                    if(hd==1)
                    {
                        r = numbers[i];
                        chArr[i] = 'R';
                    }
                    else
                    {
                        l = numbers[i];
                        chArr[i] = 'L';
                    }
                }
            }
        }
        String answer = String.valueOf(chArr);
        return answer;
    }
    
    public static int distance(int hand, int target)
    {
        if(hand == 1)
        {
            if(target == 2)
                return 1;
            else if(target == 5)
                return 2;
            else if(target == 8)
                return 3;
            else if(target == 0)
                return 4;
        }
        else if(hand == 2)
        {
            if(target == 2)
                return 0;
            else if(target == 5)
                return 1;
            else if(target == 8)
                return 2;
            else if(target == 0)
                return 3;
        }
        else if(hand == 3)
        {
            if(target == 2)
                return 1;
            else if(target == 5)
                return 2;
            else if(target == 8)
                return 3;
            else if(target == 0)
                return 4;
        }
        else if(hand == 4)
        {
            if(target == 2)
                return 2;
            else if(target == 5)
                return 1;
            else if(target == 8)
                return 2;
            else if(target == 0)
                return 3;
        }
        else if(hand == 5)
        {
            if(target == 2)
                return 1;
            else if(target == 5)
                return 0;
            else if(target == 8)
                return 1;
            else if(target == 0)
                return 2;
        }
        else if(hand == 6)
        {
            if(target == 2)
                return 2;
            else if(target == 5)
                return 1;
            else if(target == 8)
                return 2;
            else if(target == 0)
                return 3;
        }
        else if(hand == 7)
        {
            if(target == 2)
                return 3;
            else if(target == 5)
                return 2;
            else if(target == 8)
                return 1;
            else if(target == 0)
                return 2;
        }
        else if(hand == 8)
        {
            if(target == 2)
                return 2;
            else if(target == 5)
                return 1;
            else if(target == 8)
                return 0;
            else if(target == 0)
                return 1;
        }
        else if(hand == 9)
        {
            if(target == 2)
                return 3;
            else if(target == 5)
                return 2;
            else if(target == 8)
                return 1;
            else if(target == 0)
                return 2;
        }
        
        else if(hand == 10)
        {
            if(target == 2)
                return 4;
            else if(target == 5)
                return 3;
            else if(target == 8)
                return 2;
            else if(target == 0)
                return 1;
        }
        else if(hand == 0)
        {
            if(target == 2)
                return 3;
            else if(target == 5)
                return 2;
            else if(target == 8)
                return 1;
            else if(target == 0)
                return 0;
        }
        else if(hand == 11)
        {
            if(target == 2)
                return 4;
            else if(target == 5)
                return 3;
            else if(target == 8)
                return 2;
            else if(target == 0)
                return 1;
        }
       return 0; 
    }
    
}