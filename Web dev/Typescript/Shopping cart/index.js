var initialValue = 0; // Initialize a variable
var currentValue = initialValue; // Track the current value
var ans = document.querySelector("#ans");
if (ans) {
    ans.innerHTML = String(initialValue); // Display the initial value
}
var up = function () {
    currentValue++;
    if (ans) {
        ans.innerHTML = String(currentValue); // Update the displayed value
    }
};
var down = function () {
    if (currentValue == 1) {
        if (ans) {
            ans.innerHTML = String("Cart empty"); // Update the displayed value
        }
    }
    else {
        currentValue--;
        if (ans) {
            ans.innerHTML = String(currentValue); // Update the displayed value
        }
    }
};
