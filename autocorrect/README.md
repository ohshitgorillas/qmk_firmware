# ohshitgorillas' Autocorrect Library

Welcome to my personal autocorrect library for QMK keyboards!

## Philosophy

Most pre-packaged autocorrect solutions focus heavily on misspellings—they're filled with corrections for words that are genuinely misspelled due to lack of knowledge. As someone who spells quite well, however, I rarely need corrections for words like "definitely" or "separate." What I actually need is correction for the mechanical errors that occur during fast typing: transposed letters, doubled characters, missed keystrokes, and other symptoms of fatfingeritis.

This library takes a different approach by focusing primarily on **typo correction** rather than spelling education. The goal is to catch the mechanical mistakes that happen when your fingers don't quite hit the keys you intended, while avoiding the bloat of corrections you'll never actually trigger.

## Organization

To maximize reusability and allow selective adoption, the corrections are organized into five distinct categories:

- **[typos.txt](typos.txt)**: Core typo corrections covering the most common mechanical errors—transposed letters, missing letters, and other finger fumbles. This is the foundation file that most users will want, although many entries are specific to QWERTY.

- **[misspellings.txt](misspellings.txt)**: A curated list of words that I personally misspell from time to time.

- **[personal.txt](personal.txt)**: Science-specific terms, technical jargon, proper nouns, and phrases that I use frequently but that most others won't recognize.

- **[profanity.txt](profanity.txt)**: Common typos of profane words, corrected to their intended forms. Separated for those who prefer to exclude such corrections from their setup.

- **[slurs.txt](slurs.txt)**: Corrections that transform offensive slurs (whether intentional or accidental) into benign alternatives (e.g., if you try to type 'like' but hit 'k' instead of 'l'). Upload it to your racist friend's keyboard!

## Usage

These files are designed for use with QMK's autocorrect feature, but the format should be adaptable to other autocorrect systems. You can use individual files or combine multiple files based on your needs and preferences.

Download the desired files to `<qmk folder>/autocorrect/`. Before compiling, run:

```bash
cat ~/<qmk folder>/autocorrect/*.txt > ~/<qmk folder>/autocorrect.txt
```

Then:
```bash
qmk generate-autocorrect-data ~/<qmk folder>/autocorrect.txt -o <your keymap directory>
```

See the official QMK Autocorrect Documentationm at https://docs.qmk.fm/features/autocorrect for more information.
