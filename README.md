# Operating Systems Laboratory — Linux

An interactive Jupyter notebook for the Operating Systems lab course: Linux installation, configuration & administration, and the command line.

 **Work in progress** — new experiments are added throughout the semester.

## Contents

| # | Experiment | Status |
|---|------------|--------|
| 1 | Linux systems & installation | ✅ |
| 2 | Linux configuration & administration | ✅ |
| 3 | The command line (lab tasks + command cheat sheet) | ✅ |
| 4+ | Coming soon | ⏳ |

The notebook also includes a practical command sheet and a lab exercises & report checklist.

## Repository structure

```
Operating-Systems-Lab/
├── README.md
├── OS_Laboratory.ipynb   # the lab notebook
└── images/               # figures used by the notebook
```

## How to use

```bash
git clone https://github.com/BradTZ8/Operating-Systems-Lab.git
cd Operating-Systems-Lab
pip install notebook
jupyter notebook OS_Laboratory.ipynb
```

Then run the cells one by one with **Shift + Enter**.

### Requirements

- Python 3 and Jupyter (`notebook` or `jupyterlab`)
- **Linux, WSL, or a Linux virtual machine** — many cells use `%%bash`, so they will not work in a plain Windows or macOS terminal
- Keep the `images/` folder next to the notebook, otherwise the figures will not load

## Updating

New experiments are added as the course progresses. To get the latest version:

```bash
git pull
```

## Credits

- Course instructors: Bardia Talebian & Amirhosein Azhdarnezhad
- Maintained by [@BradTZ8](https://github.com/BradTZ8)
