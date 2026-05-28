let deck = null;
let flashcards = [];
let currentIndex = 0;
let isFlipped = false;
let cardStatus = [];
let filteredIndices = [];

function deckId() {
    return new URLSearchParams(window.location.search).get("deck");
}

function progressKey() {
    return `heimdall_fc_${deckId()}`;
}

function renderMarkdown(text) {
    if (window.marked) {
        return marked.parse(text || "");
    }
    return (text || "").replace(/\n/g, "<br>");
}

function loadDeck() {
    const id = deckId();
    if (!id || !window.HEIMDALL_DECKS) {
        showError("Missing deck id or decks.js not loaded.");
        return;
    }

    deck = HEIMDALL_DECKS.decks.find(d => d.id === id);
    if (!deck) {
        showError(`Deck "${id}" not found. Rebuild the hub or pick a deck from the home page.`);
        return;
    }

    flashcards = deck.cards;
    document.getElementById("deckTitle").textContent = deck.title;
    document.getElementById("deckSubtitle").textContent = `${deck.course} · ${deck.path}`;

    const saved = localStorage.getItem(progressKey());
    cardStatus = saved ? JSON.parse(saved) : Array(flashcards.length).fill("unknown");
    if (cardStatus.length !== flashcards.length) {
        cardStatus = Array(flashcards.length).fill("unknown");
    }

    filteredIndices = [...Array(flashcards.length).keys()];
    displayCard();
    updateStats();
}

function showError(msg) {
    document.querySelector(".viewer-root").innerHTML = `
        <div class="empty-state">
            <p>${msg}</p>
            <p style="margin-top:16px"><a href="index.html">← Back to deck list</a></p>
        </div>`;
}

function displayCard() {
    if (!filteredIndices.length) return;
    const card = flashcards[filteredIndices[currentIndex]];
    document.getElementById("questionContent").innerHTML = renderMarkdown(card.question);
    document.getElementById("answerContent").innerHTML = renderMarkdown(card.answer);

    const cardNum = `${currentIndex + 1} / ${filteredIndices.length}`;
    document.getElementById("cardNumber").textContent = cardNum;
    document.getElementById("cardNumberBack").textContent = cardNum;
    document.getElementById("currentCard").textContent = currentIndex + 1;

    updateProgress();
    updateButtons();
}

function flipCard() {
    isFlipped = !isFlipped;
    document.getElementById("flashcard").classList.toggle("flipped", isFlipped);
}

function nextCard() {
    if (currentIndex < filteredIndices.length - 1) {
        currentIndex++;
        if (isFlipped) flipCard();
        displayCard();
    }
}

function previousCard() {
    if (currentIndex > 0) {
        currentIndex--;
        if (isFlipped) flipCard();
        displayCard();
    }
}

function saveProgress() {
    localStorage.setItem(progressKey(), JSON.stringify(cardStatus));
}

function markCard(status) {
    cardStatus[filteredIndices[currentIndex]] = status;
    saveProgress();
    updateStats();
    if (currentIndex < filteredIndices.length - 1) nextCard();
}

function updateStats() {
    const known = cardStatus.filter(s => s === "known").length;
    const learning = cardStatus.filter(s => s === "unknown" || s === "learning").length;
    document.getElementById("knownCount").textContent = known;
    document.getElementById("unknownCount").textContent = learning;
    document.getElementById("totalCards").textContent = filteredIndices.length;
}

function updateProgress() {
    const progress = filteredIndices.length ? ((currentIndex + 1) / filteredIndices.length) * 100 : 0;
    document.getElementById("progressBar").style.width = progress + "%";
}

function updateButtons() {
    document.getElementById("prevBtn").disabled = currentIndex === 0;
    document.getElementById("nextBtn").disabled = currentIndex >= filteredIndices.length - 1;
}

function setActiveFilter(btn) {
    document.querySelectorAll(".btn-filter").forEach(el => el.classList.remove("active"));
    btn.classList.add("active");
}

function filterCards(filter, btn) {
    currentIndex = 0;
    if (isFlipped) flipCard();
    setActiveFilter(btn);

    if (filter === "all") {
        filteredIndices = [...Array(flashcards.length).keys()];
    } else if (filter === "known") {
        filteredIndices = cardStatus.map((s, i) => (s === "known" ? i : -1)).filter(i => i !== -1);
    } else if (filter === "unknown") {
        filteredIndices = cardStatus
            .map((s, i) => (s === "unknown" || s === "learning" ? i : -1))
            .filter(i => i !== -1);
    } else if (filter === "critical") {
        filteredIndices = flashcards.map((c, i) => (c.critical ? i : -1)).filter(i => i !== -1);
    }

    if (!filteredIndices.length) {
        alert("No cards match this filter.");
        filterCards("all", document.querySelector('.btn-filter[data-filter="all"]'));
        return;
    }

    updateStats();
    displayCard();
}

function shuffleCards() {
    filteredIndices.sort(() => Math.random() - 0.5);
    currentIndex = 0;
    if (isFlipped) flipCard();
    displayCard();
}

document.addEventListener("keydown", e => {
    if (e.key === "ArrowLeft") previousCard();
    if (e.key === "ArrowRight") nextCard();
    if (e.key === " " || e.key === "Enter") {
        e.preventDefault();
        flipCard();
    }
    if (e.key === "1") markCard("known");
    if (e.key === "2") markCard("learning");
    if (e.key === "3") markCard("unknown");
});

loadDeck();
