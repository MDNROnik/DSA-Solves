class Solution {
public:
    map<string,string>mp;
    int num=0;
    string encode(string longUrl) {
        string res = "http://tinyurl.com/"+to_string(num);
        num++;
        mp[res]=longUrl;
        return res;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }

};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));