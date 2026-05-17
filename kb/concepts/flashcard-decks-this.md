---
id: "a60450ee-744f-419d-b80b-9fa7147be25b"
title: "Flashcard Decks This"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:34cc39e298278b64"
source: heimdall/auto
---

# Flashcard Decks This

- # 📚 Flashcard Decks

This folder contains all your flashcard decks in a centralized location.

## 🎯 How It Works

1. **One HTML viewer** (`universal-flashcards.html`) reads all decks
2. **Separate deck files** (`.js` files) store the flashcard content
3. **Easy to add** new decks - just create a new `.js` file!

## 📁 Current Decks

- **ege322-test1.js** - EGE322 IoT Project Management Test 1 (36 cards)
- **ap-cs-basics.js** - AP Computer Science A Java Basics (10 cards)
- **ap-calc-derivatives.js** - AP Calculus BC Derivatives (10 cards)
- **ap-calc-integrals.js** - AP Calculus BC Integration (10 cards)

## ➕ Adding a New Deck

Create a new `.js` file in this folder with this format:

```javascript
const myNewDeck = {
    name: "Deck Name",
    description: "Brief description of what this deck covers",
    category: "Subject Name",
    cards: [
        { 
            question: "Your question?", 
            answer: "Your answer (can include HTML)", 
            critical: false  // true for important cards
        },
        // Add more cards...
    ]
};
```

Then add it to `universal-flashcards.html`:

1. Add script tag: `<script src="flashcard-decks/your-file.js"></script>`
2. <!-- id:a60450ee-744f-419d-b80b-9fa7147be25b ts:2026-05-17 07:49 -->
- # 📚 Flashcard Decks

This folder contains all your flashcard decks in a centralized location.

## 🎯 How It Works

1. **One HTML viewer** (`universal-flashcards.html`) reads all decks
2. **Separate deck files** (`.js` files) store the flashcard content
3. **Easy to add** new decks - just create a new `.js` file!

## 📁 Current Decks

- **ege322-test1.js** - EGE322 IoT Project Management Test 1 (36 cards)
- **ap-cs-basics.js** - AP Computer Science A Java Basics (10 cards)
- **ap-calc-derivatives.js** - AP Calculus BC Derivatives (10 cards)
- **ap-calc-integrals.js** - AP Calculus BC Integration (10 cards)

## ➕ Adding a New Deck

Create a new `.js` file in this folder with this format:

```javascript
const myNewDeck = {
    name: "Deck Name",
    description: "Brief description of what this deck covers",
    category: "Subject Name",
    cards: [
        { 
            question: "Your question?", 
            answer: "Your answer (can include HTML)", 
            critical: false  // true for important cards
        },
        // Add more cards...
    ]
};
```

Then add it to `universal-flashcards.html`:

1. Add script tag: `<script src="flashcard-decks/your-file.js"></script>`
2. <!-- id:a60450ee-744f-419d-b80b-9fa7147be25b ts:2026-05-17 07:49 -->
