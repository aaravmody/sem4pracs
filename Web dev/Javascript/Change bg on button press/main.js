let a = document.querySelector(".btn")
let b = document.querySelector('body')
let changebg = 0

a.addEventListener("click",change);

function change()
{
    if(changebg===0)
        {
    b.classList.add('new-bg')
    console.log("done")
    changebg=1;
        }
    else{
        b.classList.remove('new-bg')
        changebg=0;
    }
}