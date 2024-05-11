//aryan shah ka hai

function validateForm() {
    // Get form elements
    var firstName = document.getElementById('firstName').value;
    var lastName = document.getElementById('lastName').value;
    var sapId = document.getElementById('sapId').value;
    var dob = document.getElementById('dob').value;
    var division = document.getElementById('division').value;
    var department = document.getElementById('department').value;
    var phoneNumber = document.getElementById('phoneNumber').value;
    var email = document.getElementById('email').value;
    var password = document.getElementById('password').value;
    var confirmPassword = document.getElementById('confirmPassword').value;

    // Regular expressions for validation
    var sapIdPattern = /^600[0-9]{8}$/;
    var phoneNumberPattern = /^[0-9]{10}$/;
    var emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
    var passwordPattern = /^(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{8,}$/;

    // Error message variable
    var errorMessage = "";

    // Validate first name
    if (firstName.trim() == "") {
        errorMessage += "Please enter your first name.\n";
    }

    // Validate last name
    if (lastName.trim() == "") {
        errorMessage += "Please enter your last name.\n";
    }

    // Validate SAP ID
    if (!sapIdPattern.test(sapId)) {
        errorMessage += "SAP ID must start with 600 and be 11 digits.\n";
    }

    // Validate Date of Birth
    if (dob.trim() == "") {
        errorMessage += "Please select your date of birth.\n";
    }

    // Validate Division
    if (division.trim() == "") {
        errorMessage += "Please enter your division.\n";
    }

    // Validate Department
    if (department.trim() == "") {
        errorMessage += "Please select your department.\n";
    }

    // Validate Phone Number
    if (!phoneNumberPattern.test(phoneNumber)) {
        errorMessage += "Phone number must be 10 digits.\n";
    }

    // Validate Email
    if (!emailPattern.test(email)) {
        errorMessage += "Please enter a valid email address.\n";
    }

    // Validate Password
    if (password.trim() == "") {
        errorMessage += "Please enter a password.\n";
    } else if (!passwordPattern.test(password)) {
        errorMessage += "Password must be at least 8 characters long and contain at least one special character.\n";
    }

    // Validate Confirm Password
    if (confirmPassword.trim() == "") {
        errorMessage += "Please confirm your password.\n";
    } else if (confirmPassword !== password) {
        errorMessage += "Passwords do not match.\n";
    }

    // Display error message if any
    if (errorMessage !== "") {
        alert(errorMessage);
        return false; // Prevent form submission
    }

    // // If all validations pass, return true to allow form submission
    // return true;

     // If all validations pass, construct URL parameters and redirect to students.html
     var urlParams = "?firstName=" + encodeURIComponent(firstName) +
     "&lastName=" + encodeURIComponent(lastName) +
     "&sapId=" + encodeURIComponent(sapId) +
     "&dob=" + encodeURIComponent(dob) +
     "&division=" + encodeURIComponent(division) +
     "&department=" + encodeURIComponent(department) +
     "&phoneNumber=" + encodeURIComponent(phoneNumber) +
     "&email=" + encodeURIComponent(email);

window.location.href = "students.html" + urlParams;

return false; // Prevent default form submission

}