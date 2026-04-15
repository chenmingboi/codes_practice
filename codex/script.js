const root = document.documentElement;
const cards = Array.from(document.querySelectorAll(".tilt-card"));
const canvas = document.getElementById("aurora");
const ctx = canvas.getContext("2d");

const pointer = {
  tx: window.innerWidth * 0.5,
  ty: window.innerHeight * 0.5,
  x: window.innerWidth * 0.5,
  y: window.innerHeight * 0.5,
};

const palette = ["#6d8eff", "#8f60ff", "#f05bc2", "#66b3ff"];
const blobs = Array.from({ length: 4 }, (_, i) => ({
  radius: 150 + i * 30,
  speed: 0.16 + i * 0.045,
  phase: Math.random() * Math.PI * 2,
  drift: 0.34 + i * 0.08,
}));

let cw = 0;
let ch = 0;
let dpr = Math.min(window.devicePixelRatio || 1, 2);
let lastTime = performance.now();

function resize() {
  cw = window.innerWidth;
  ch = window.innerHeight;
  dpr = Math.min(window.devicePixelRatio || 1, 2);
  canvas.width = Math.floor(cw * dpr);
  canvas.height = Math.floor(ch * dpr);
  ctx.setTransform(dpr, 0, 0, dpr, 0, 0);
}

function drawAurora(t) {
  ctx.clearRect(0, 0, cw, ch);
  ctx.globalCompositeOperation = "screen";

  for (let i = 0; i < blobs.length; i += 1) {
    const blob = blobs[i];
    const a = t * blob.speed + blob.phase;
    const x = cw * (0.16 + 0.2 * i) + Math.sin(a) * cw * blob.drift * 0.15;
    const y = ch * (0.28 + 0.13 * i) + Math.cos(a * 1.28) * ch * 0.23;
    const r = blob.radius + Math.sin(a * 1.52) * 30;

    const g = ctx.createRadialGradient(x, y, r * 0.12, x, y, r);
    g.addColorStop(0, `${palette[i]}d8`);
    g.addColorStop(0.5, `${palette[(i + 1) % palette.length]}70`);
    g.addColorStop(1, "rgba(0,0,0,0)");

    ctx.fillStyle = g;
    ctx.beginPath();
    ctx.arc(x, y, r, 0, Math.PI * 2);
    ctx.fill();
  }

  ctx.globalCompositeOperation = "source-over";
}

function animate(now) {
  const delta = Math.min(now - lastTime, 28);
  lastTime = now;

  const easing = 1 - Math.pow(0.001, delta / 1000);
  pointer.x += (pointer.tx - pointer.x) * easing;
  pointer.y += (pointer.ty - pointer.y) * easing;

  const nx = pointer.x / cw;
  const ny = pointer.y / ch;
  const rx = (0.5 - ny) * 10;
  const ry = (nx - 0.5) * 14;

  root.style.setProperty("--mx", `${(nx * 100).toFixed(2)}%`);
  root.style.setProperty("--my", `${(ny * 100).toFixed(2)}%`);

  cards.forEach((card, index) => {
    const depth = 1 - index * 0.22;
    const floatY = Math.sin(now * 0.0012 + index * 1.1) * 1.4;
    const cardRx = rx * depth;
    const cardRy = ry * depth;

    card.style.transform = `rotateX(${cardRx.toFixed(2)}deg) rotateY(${cardRy.toFixed(2)}deg) translateY(${floatY.toFixed(2)}px)`;
    card.style.boxShadow = `
      inset 1px 1px 0 rgba(255, 255, 255, 0.48),
      inset -1px -1px 0 rgba(255, 255, 255, 0.1),
      ${(-cardRy * 1.35).toFixed(1)}px ${(16 - cardRx * 0.85).toFixed(1)}px 60px rgba(13, 2, 35, 0.52)
    `;
  });

  drawAurora(now * 0.001);
  requestAnimationFrame(animate);
}

window.addEventListener("pointermove", (event) => {
  pointer.tx = event.clientX;
  pointer.ty = event.clientY;
});

window.addEventListener("pointerleave", () => {
  pointer.tx = cw * 0.5;
  pointer.ty = ch * 0.5;
});

window.addEventListener("resize", resize);
resize();
requestAnimationFrame(animate);
