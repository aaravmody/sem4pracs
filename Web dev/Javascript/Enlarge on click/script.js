const image = document.getElementById('myImage');

image.addEventListener('click', function() {
  if (image.style.width === '400px') {
    image.style.width = '200px';
    image.style.height = '200px';
  } else {
    image.style.width = '400px';
    image.style.height = '400px';
  }
});
