window.addEventListener('scroll', function() {
    const triggerPoint = document.documentElement.clientHeight * 1.25; // 75% of viewport height //gpt kiya, seekhlo yeh ab
    if (window.scrollY > triggerPoint) {
        alert("You've scrolled past 125% of the page!");
    }
  });
  