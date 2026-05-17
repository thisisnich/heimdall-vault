---
id: "19d7cef1-2307-4f42-ace6-396677e49fa1"
title: "Versal App"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:dc972d3a7fdc5adc"
source: heimdall/auto
---

# Versal App

- versal app!**

---

## ➕ How to Add Your Own Decks

### **For Flashcards:**

1. Create a new file in `flashcard-decks/` folder (e.g., `my-deck.js`)
2. Use this format:

```javascript
const myDeck = {
    name: "My Deck Name",
    description: "What this deck covers",
    category: "Subject",
    cards: [
        { 
            question: "Question?", 
            answer: "Answer (can use HTML)", 
            critical: false,  // true for important cards
            chapter: "1.1"    // optional chapter grouping
        }
    ]
};
```

3. Add to `universal-flashcards.html`:
   - Add script tag: `<script src="flashcard-decks/my-deck.js"></script>`
   - Add to array: `myDeck` in the `availableDecks` array

### **For Quizzes:**

1. Create a new file in `quiz-decks/` folder (e.g., `my-quiz.js`)
2. Use this format:

```javascript
const myQuiz = {
    name: "My Quiz Name",
    description: "What this quiz covers",
    category: "Subject",
    quizzes: [
        {
            title: "Topic Name",
            questions: [
                {
                    question: "Question?",
                    options: ["A", "B", "C", "D"],
                    correct: 0,  // 0=A, 1=B, 2=C, 3=D
                    explanation: "Why this is correct"
                }
            ]
        }
    ]
};
```

3. <!-- id:19d7cef1-2307-4f42-ace6-396677e49fa1 ts:2026-05-17 07:49 -->
- versal app!**

---

## ➕ How to Add Your Own Decks

### **For Flashcards:**

1. Create a new file in `flashcard-decks/` folder (e.g., `my-deck.js`)
2. Use this format:

```javascript
const myDeck = {
    name: "My Deck Name",
    description: "What this deck covers",
    category: "Subject",
    cards: [
        { 
            question: "Question?", 
            answer: "Answer (can use HTML)", 
            critical: false,  // true for important cards
            chapter: "1.1"    // optional chapter grouping
        }
    ]
};
```

3. Add to `universal-flashcards.html`:
   - Add script tag: `<script src="flashcard-decks/my-deck.js"></script>`
   - Add to array: `myDeck` in the `availableDecks` array

### **For Quizzes:**

1. Create a new file in `quiz-decks/` folder (e.g., `my-quiz.js`)
2. Use this format:

```javascript
const myQuiz = {
    name: "My Quiz Name",
    description: "What this quiz covers",
    category: "Subject",
    quizzes: [
        {
            title: "Topic Name",
            questions: [
                {
                    question: "Question?",
                    options: ["A", "B", "C", "D"],
                    correct: 0,  // 0=A, 1=B, 2=C, 3=D
                    explanation: "Why this is correct"
                }
            ]
        }
    ]
};
```

3. <!-- id:19d7cef1-2307-4f42-ace6-396677e49fa1 ts:2026-05-17 07:49 -->
