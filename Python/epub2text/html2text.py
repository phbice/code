'''convert html to text'''
from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
    # def handle_starttag(self, tag, attrs):
        # if tag == 'h3':
            # self.fp.write('\n')

    def handle_data(self, data):
        if self.lasttag in ('h2', 'h3', 'b', 'p', 'span', 'br'):
            self.fp.write(data)
    # def handle_endtag(self, tag):
        # if tag == 'h3':
            # self.fp.write('\n\n\n')
        # elif tag == 'p':
            # self.fp.write('\n\n')

    def handle_startendtag(self, tag, attrs):
        if tag == 'br':
            self.fp.write('\n')

fileout = open(r'text.txt', 'w', encoding='utf-8')
parser = MyHTMLParser()
parser.fp = fileout
for fileNum in range(1,38):
    filein = open(r'html\text%04d.html' %fileNum, 'r', encoding='utf-8')
    parser.feed(filein.read())
    parser.close()
    filein.close()
    filein = open(r'html\text%04d_0001.html' %fileNum, 'r', encoding='utf-8')
    parser.feed(filein.read())
    parser.close()
    filein.close()
fileout.close()
