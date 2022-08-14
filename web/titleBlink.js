var title;

function getTitle()
{
	var titles = document.head.getElementsByTagName('title');
  if (titles.length == 0) {
    title = document.createElement('title');
    document.head.appendChild(title);
  } else {
    title = titles[0];
  }
}

var toggle = false;

function blink()
{
  if (toggle) {
    title.innerHTML = 'Blink';
  } else {
    title.innerHTML = '　';
  }
  toggle = !toggle;
}

getTitle();
setInterval(blink, 1000);