function factor(num)
{
  var lastFactor = 0;
  var factors = [];
  var i = 2;
  while (i * i <= num) {
    if (num % i == 0) {
      if (i != lastFactor) {
        lastFactor = i;
        factors.push([lastFactor, 1]);
      }
      else
        factors[factors.length - 1][1] += 1;
      num = Math.floor(num / i);
    }
    else
      i++;
  }
  if (num != lastFactor)
    factors.push([num, 1]);
  else
    factors[factors.length - 1][1] += 1;
  return factors;
}

function mathml(num, factors)
{
  var result = [];
  for (i = 0; i < factors.length; i++) {
    if (factors[i][1] > 1) {
      result.push('<msup><mn>' + factors[i][0] + '</mn><mn>' + 
                  factors[i][1] + '</mn></msup>');
    }
    else
      result.push('<mn>' + factors[i][0] + '</mn>');
  }
  return ('<math><mn>' + num + '</mn><mo>=</mo>' +
          result.join('<mo>&times;</mo>') + '</math>');
}
