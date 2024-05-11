var box= document.querySelector('#box')

box.addEventListener('mouseenter',onmouseenter);

function onmouseenter(e){
    e.target.style.backgroundColor = "red"
}

box.addEventListener('mouseleave',function (e){ 
    e.target.style.backgroundColor = 'blue'
})