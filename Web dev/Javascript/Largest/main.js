const btn = document.querySelector('.btn');
const msg = document.querySelector('.msg')

btn.addEventListener('click', onsubmit);

function onsubmit(e) {
    e.preventDefault();
    const num1 = document.querySelector('#num1').value;
    const num2 = document.querySelector('#num2').value;
    const ans = num1>num2 ? num1 : num2;
    console.log(ans)
    msg.innerHTML = ans
}