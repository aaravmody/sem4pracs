const btn = document.querySelector('.btn');

btn.addEventListener('click', onsubmit);

function onsubmit(e) {
    e.preventDefault();
    const num1 = document.querySelector('#num1').value;
    const num2 = document.querySelector('#num2').value;
    const num3 = document.querySelector('#num3').value;
    const ans = num1*num2*num3
    console.log(ans)
    if(ans<0)
        {
            alert("-")
        }
    else{
        alert("+")
    }
}