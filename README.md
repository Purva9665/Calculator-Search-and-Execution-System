# Calculator Search & Execution System

A single-page, in-browser **multi-calculator** with a searchable menu. Pick a category (or search for it),
then run the calculation — no install, no server, no build step.

**Live demo:** _(enable GitHub Pages on this repo, then add the URL here)_

## Features
- 🔍 **Searchable menu** — type "temperature", "currency", "length", "sin"… to filter calculators
- 🌡️ **Temperature** — Celsius ↔ Fahrenheit ↔ Kelvin
- 💱 **Currency** — INR / USD / EUR / GBP / JPY (indicative fixed rates, base USD)
- 📏 **Unit conversion** — Length, Mass and Time
- 🧮 **Scientific** — degree-aware trig, log/ln, powers, roots, π and e, with a safe expression evaluator
  (input is whitelisted before evaluation)

## Tech
- HTML5, CSS3, vanilla JavaScript — zero dependencies
- Single file: `index.html`

## Run
Open `index.html` in any modern browser, or visit the live GitHub Pages link above.

## Notes
- `animation.c` and `color.c` are earlier C experiments kept for reference; the working calculator is the
  browser app in `index.html` (C executables can't run on a static web host).
