const root = document.documentElement;
const card = document.getElementById("glass-card");
const canvas = document.getElementById("aurora");
const ctx = canvas.getContext("2d");

const pointer = {
  tx: window.innerWidth * 0.5,
  ty: window.innerHeight * 0.5,
  x: window.innerWidth * 0.5,
  y: window.innerHeight * 0.5,
};

const palette = ["#7ee8ff", "#5bb8ff", "#87f0d2", "#3c7ccf"];
const blobs = Array.from({ length: 4 }, (_, i) => ({
  radius: 140 + i * 28,
  speed: 0.16 + i * 0.04,
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
    const x = cw * (0.18 + 0.18 * i) + Math.sin(a) * cw * blob.drift * 0.16;
    const y = ch * (0.35 + 0.12 * i) + Math.cos(a * 1.3) * ch * 0.24;
    const r = blob.radius + Math.sin(a * 1.5) * 28;

    const g = ctx.createRadialGradient(x, y, r * 0.12, x, y, r);
    g.addColorStop(0, `${palette[i]}cc`);
    g.addColorStop(0.48, `${palette[(i + 1) % palette.length]}66`);
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
  card.style.transform = `rotateX(${rx.toFixed(2)}deg) rotateY(${ry.toFixed(2)}deg)`;
  card.style.boxShadow = `
    inset 1px 1px 0 rgba(255, 255, 255, 0.5),
    inset -1px -1px 0 rgba(255, 255, 255, 0.1),
    ${(-ry * 1.4).toFixed(1)}px ${(14 - rx * 0.8).toFixed(1)}px 58px rgba(0, 11, 22, 0.48)
  `;

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
