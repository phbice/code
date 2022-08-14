var textlist = []
$('div.main-text-wrap span.content-wrap').each(
	(i, elem) => {
    textlist.push(elem.innerHTML)
  }
)
textlist.join('\n')