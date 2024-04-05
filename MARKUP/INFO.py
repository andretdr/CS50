# internet TCP/IP internet sending (internet protocol) IPv4 2^32-> IPv6 2^128, TCP garantees delivery, packet number 1 of 3, port number

PORT number
80 HTTP
443 HTTPS

1.2.3.4:80 # port at the end

# routers
# DNS domain name system -> what is IP address from this domain?
# DHCP Dynamic host configuration protocol -> what should be my DNS server and router? automatically

# HTTP protocol about how websites speak to each other. standaridises packets between web servers and browsers
# HTTPS secure. encrypted and scrambled


GET
POST

# browser to server
GET / HTTP/2
Host: www.harvard.edu    # http header

# server response
HTTP/2 200    # acknowledgment of version being used, status, 200 means OK, 301 means moved permanently, 404 file not found
Content-Type: text/html    # what kind of content?

# terminal
curl -I https://www.harvard.edu/ # connect to URL, return the server response


