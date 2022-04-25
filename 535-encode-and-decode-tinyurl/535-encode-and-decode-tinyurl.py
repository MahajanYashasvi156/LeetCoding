mymap = {}
class Codec:

    def encode(self, longUrl: str) -> str:
        """Encodes a URL to a shortened URL.
        """
        ran = ''.join(random.choices(string.ascii_uppercase + string.ascii_lowercase+ string.digits, k = 10))
        mymap[ran] = longUrl
        return ran
        
    def decode(self, shortUrl: str) -> str:
        """Decodes a shortened URL to its original URL.
        """
        return mymap[shortUrl]
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))