var page_content = document.getElementsByClassName('page-content')[1].children;
var para_list = [];
for (let i = 0; i < page_content.length; i++) {
  para_list.push('　　' + page_content[i].innerHTML)
}
para_str = para_list.join('')