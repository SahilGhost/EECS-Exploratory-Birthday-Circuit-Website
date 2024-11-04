document.addEventListener("DOMContentLoaded", () => {
    const sections = document.querySelectorAll(".card");
    const navLinks = document.querySelectorAll(".nav-links a");
  
    const observer = new IntersectionObserver(
      (entries) => {
        entries.forEach((entry) => {
          if (entry.isIntersecting) {
            entry.target.classList.add("visible");  // Add fade-in effect
            const stepId = entry.target.getAttribute("id");
            navLinks.forEach((link) => {
              link.classList.toggle("active", link.getAttribute("href").slice(1) === stepId);
            });
          }
        });
      },
      { threshold: 0.5 }
    );
  
    sections.forEach((section) => observer.observe(section));
  });
  