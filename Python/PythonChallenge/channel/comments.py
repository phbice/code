import re
#import pdb
#pdb.set_trace()

file = open('comments.txt', 'r')
comment_dic = {}
path_pattern = re.compile(r'^Path = (.+)$')
comment_pattern = re.compile(r'^Comment = (.+)$')
for line in file:
    match_path = path_pattern.match(line)
    match_comment = comment_pattern.match(line)
    if match_path:
	    filename = match_path.group(1)
    elif match_comment:
	    comment = match_comment.group(1)
    if line == '\n':
        comment_dic[filename] = comment
file.close()

file = open('follow.txt', 'r')
result = ''
for line in file:
    result = result + comment_dic[line.strip() + '.txt']
print(result)