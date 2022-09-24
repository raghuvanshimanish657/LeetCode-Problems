class Solution {
public:
    int strStr(string haystack, string needle) {
        
        bool found;
        if (needle.size() > haystack.size()) return -1;
        
		// No need to go through last part of the haystack if needle needle ''cant fit''
        for (int i = 0; i < haystack.length() - needle.length() + 1; i++)
        {
            found = true;
            for (int j = 0; j < needle.length(); j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    found = false;
                    break;
                }
            }
            
            if (found) return i;
        }
        
        return -1;
    }
};