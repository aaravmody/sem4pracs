const imageElement = document.getElementById("image");
const images = ["scienist.png", "sodhi.jpg", "chapnak.jpg"]; 
let currentImageIndex = 0;

function changeImage() {
  currentImageIndex = (currentImageIndex + 1) % images.length; 
  imageElement.src = images[currentImageIndex];
}

setInterval(changeImage, 2000); 
