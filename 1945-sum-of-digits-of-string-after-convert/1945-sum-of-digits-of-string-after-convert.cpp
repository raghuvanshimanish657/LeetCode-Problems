class Solution {
public:
	int getLucky(string s, int k) {
		string str;
		for(char ch: s)
		{
			int n = ch - 'a' + 1;
			string temp = to_string(n);
			str += temp;
		}
		string st;

		while(k--)
		{
			int sum = 0;
			for(char ch: str)
			{
				int n = ch - '1' + 1;
				sum += n;
			}
			str = to_string(sum);
		}
		int ans = stoi(str);
		return ans;
	}
};