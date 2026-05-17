---
id: "47d43c04-b160-4b5b-8785-d367e459c730"
title: "Quiz Decks This"
type: vault_note
vault: wiki
created: 2026-05-17
updated: 2026-05-17
checksum: "sha256:55fa44fc5f6b367c"
source: heimdall/auto
---

# Quiz Decks This

- # 📝 Quiz Decks

This folder contains all your MCQ quiz decks in a centralized location.

## 🎯 How It Works

1. **One HTML viewer** (`universal-quiz.html`) reads all quiz decks
2. **Separate deck files** (`.js` files) store the quiz content
3. **Easy to add** new quizzes - just create a new `.js` file!

## 📁 Current Decks

- **ege322-test1.js** - EGE322 IoT Project Management Test 1 (2 topics, 25 questions total)
- **ap-cs-basics.js** - AP Computer Science A Java Fundamentals (5 questions)
- **ap-calc-bc.js** - AP Calculus BC Derivatives & Integration (2 topics, 10 questions total)

## ➕ Adding a New Quiz Deck

Create a new `.js` file in this folder with this format:

```javascript
const myNewQuiz = {
    name: "Quiz Name",
    description: "Brief description of what this quiz covers",
    category: "Subject Name",
    quizzes: [
        {
            title: "Topic 1",
            questions: [
                {
                    question: "Your question?",
                    options: ["Option A", "Option B", "Option C", "Option D"],
                    correct: 0,  // Index: 0=A, 1=B, 2=C, 3=D
                    explanation: "Detailed explanation of why this is correct"
                },
                // Add more questions...
            ]
        },
        {
            title: "Topic 2",
            questions: [
                // More questions for topic 2...
            ]
        }
    ]
};
```

Then add it to `universal-quiz.html`:

1. <!-- id:47d43c04-b160-4b5b-8785-d367e459c730 ts:2026-05-17 07:49 -->
- # 📝 Quiz Decks

This folder contains all your MCQ quiz decks in a centralized location.

## 🎯 How It Works

1. **One HTML viewer** (`universal-quiz.html`) reads all quiz decks
2. **Separate deck files** (`.js` files) store the quiz content
3. **Easy to add** new quizzes - just create a new `.js` file!

## 📁 Current Decks

- **ege322-test1.js** - EGE322 IoT Project Management Test 1 (2 topics, 25 questions total)
- **ap-cs-basics.js** - AP Computer Science A Java Fundamentals (5 questions)
- **ap-calc-bc.js** - AP Calculus BC Derivatives & Integration (2 topics, 10 questions total)

## ➕ Adding a New Quiz Deck

Create a new `.js` file in this folder with this format:

```javascript
const myNewQuiz = {
    name: "Quiz Name",
    description: "Brief description of what this quiz covers",
    category: "Subject Name",
    quizzes: [
        {
            title: "Topic 1",
            questions: [
                {
                    question: "Your question?",
                    options: ["Option A", "Option B", "Option C", "Option D"],
                    correct: 0,  // Index: 0=A, 1=B, 2=C, 3=D
                    explanation: "Detailed explanation of why this is correct"
                },
                // Add more questions...
            ]
        },
        {
            title: "Topic 2",
            questions: [
                // More questions for topic 2...
            ]
        }
    ]
};
```

Then add it to `universal-quiz.html`:

1. <!-- id:47d43c04-b160-4b5b-8785-d367e459c730 ts:2026-05-17 07:49 -->
