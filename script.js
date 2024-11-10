document.addEventListener("DOMContentLoaded", () => {
  const cards = document.querySelectorAll(".card");

  const observer = new IntersectionObserver((entries, observer) => {
    entries.forEach((entry, index) => {
      if (entry.isIntersecting) {
        // Add a delay based on the index of the card
        entry.target.style.transitionDelay = `${index * 0.2}s`;
        entry.target.classList.add("visible");
        
        // Optional: Stop observing once the element is visible
        observer.unobserve(entry.target);
      }
    });
  }, { threshold: 0.3 });

  cards.forEach((card) => observer.observe(card));
});