/* Heimdall Flashcard Hub — single-page list + study */

let deckData = null;
let deck = null;
let flashcards = [];
let currentIndex = 0;
let isFlipped = false;
let cardStatus = [];
let filteredIndices = [];

function hubBaseUrl() {
    const href = window.location.href.split("#")[0].split("?")[0];
    return href.substring(0, href.lastIndexOf("/") + 1);
}

function getDeckId() {
    const hash = window.location.hash.replace(/^#/, "");
    if (hash.startsWith("deck=")) {
        return decodeURIComponent(hash.slice(5));
    }
    return new URLSearchParams(window.location.search).get("deck");
}

function setDeckId(id) {
    if (id) {
        history.replaceState(null, "", `#deck=${encodeURIComponent(id)}`);
    } else {
        history.replaceState(null, "", window.location.pathname + window.location.search);
    }
}

function loadDecksScript() {
    return new Promise((resolve, reject) => {
        const existing = window.HEIMDALL_DECKS;
        if (existing) {
            resolve(existing);
            return;
        }
        const script = document.createElement("script");
        script.src = hubBaseUrl() + "decks.js";
        script.onload = () => {
            const data = window.HEIMDALL_DECKS;
            if (data) resolve(data);
            else reject(new Error("decks.js loaded but HEIMDALL_DECKS is missing"));
        };
        script.onerror = () => reject(new Error("Could not load decks.js"));
        document.head.appendChild(script);
    });
}

function renderError(title, message) {
    document.getElementById("app").innerHTML = `
        <div class="page">
            <div class="empty-state">
                <h2 style="margin-bottom:12px">${title}</h2>
                <p>${message}</p>
                <p style="margin-top:16px"><strong>How to open:</strong></p>
                <ol style="text-align:left;margin:12px auto;max-width:520px;line-height:1.6">
                    <li>Open File Explorer</li>
                    <li>Go to <code>07-DASHBOARDS\\flashcard-hub\\</code></li>
                    <li>Double-click <code>index.html</code> (opens in Chrome/Edge)</li>
                </ol>
                <p style="margin-top:12px">Obsidian's built-in preview often blocks local scripts — use your browser instead.</p>
                <p style="margin-top:16px"><a href="index.html">Try again</a></p>
            </div>
        </div>`;
}

function renderList(data) {
    const totalCards = data.decks.reduce((n, d) => n + d.cardCount, 0);
    const grouped = data.decks.reduce((acc, d) => {
        const key = d.course || "General";
        (acc[key] ||= []).push(d);
        return acc;
    }, {});

    const courses = Object.keys(grouped).sort();
    const deckCards = courses.map(course => `
        <section class="course-group">
            <h2>${course}</h2>
            <div class="deck-grid">
                ${grouped[course].map(d => `
                    <a class="deck-card" href="#deck=${encodeURIComponent(d.id)}" onclick="openDeck('${d.id}'); return false;">
                        <h3>${escapeHtml(d.title)}</h3>
                        <div class="meta">${escapeHtml(d.path)}</div>
                        <span class="count">${d.cardCount} cards</span>
                    </a>
                `).join("")}
            </div>
        </section>
    `).join("");

    document.getElementById("app").innerHTML = `
        <div class="page">
            <div class="header">
                <h1>Heimdall Flashcard Hub</h1>
                <p class="sub">Pick a deck to study. Progress saves in your browser per deck.</p>
            </div>
            <div class="meta-bar">${data.deckCount} deck(s) · ${totalCards} cards · updated ${data.generated}</div>
            ${deckCards || `<div class="empty-state"><p>No decks. Run: python 91-SCRIPTS/build-flashcard-hub.py</p></div>`}
        </div>`;
}

function escapeHtml(text) {
    return String(text)
        .replace(/&/g, "&amp;")
        .replace(/</g, "&lt;")
        .replace(/>/g, "&gt;")
        .replace(/"/g, "&quot;");
}

function repairMarkdown(text) {
    if (!text) return "";
    if (!text.includes("\n|") && text.includes("|")) {
        text = text.replace(/\|\s+\|/g, "|\n|");
    }
    return text;
}

function renderMarkdown(text) {
    text = repairMarkdown(text || "");
    if (window.marked) {
        marked.setOptions({ gfm: true, breaks: true });
        return marked.parse(text);
    }
    return escapeHtml(text).replace(/\n/g, "<br>");
}

function renderStudy() {
    document.getElementById("app").innerHTML = `
        <div class="page page-narrow">
            <a class="back-link" href="#" onclick="goHome(); return false;">← All decks</a>
            <div class="header">
                <h1 id="deckTitle">Loading…</h1>
                <p class="sub" id="deckSubtitle"></p>
            </div>
            <div class="progress-bar"><div class="progress-fill" id="progressBar"></div></div>
            <div class="stats">
                <div class="stat-card"><span class="number" id="currentCard">1</span><span class="label">Current</span></div>
                <div class="stat-card"><span class="number" id="totalCards">0</span><span class="label">In filter</span></div>
                <div class="stat-card"><span class="number" id="knownCount">0</span><span class="label">Known</span></div>
                <div class="stat-card"><span class="number" id="unknownCount">0</span><span class="label">Learning</span></div>
            </div>
            <div class="filter-buttons">
                <button class="btn-filter active" data-filter="all" onclick="filterCards('all', this)">All</button>
                <button class="btn-filter" data-filter="unknown" onclick="filterCards('unknown', this)">Learning</button>
                <button class="btn-filter" data-filter="known" onclick="filterCards('known', this)">Known</button>
                <button class="btn-filter" data-filter="critical" onclick="filterCards('critical', this)">Critical</button>
                <button class="btn-filter" onclick="shuffleCards()">Shuffle</button>
            </div>
            <div class="flashcard-container">
                <div class="flashcard" id="flashcard" onclick="flipCard()">
                    <div class="card-face card-front">
                        <div class="card-number" id="cardNumber">1 / 1</div>
                        <div class="card-label">Question</div>
                        <div class="card-content" id="questionContent"></div>
                        <div class="card-hint">Click or Space to flip</div>
                    </div>
                    <div class="card-face card-back">
                        <div class="card-number" id="cardNumberBack">1 / 1</div>
                        <div class="card-label">Answer</div>
                        <div class="card-content" id="answerContent"></div>
                        <div class="card-hint">1 = know · 2 = learning · 3 = don't know</div>
                    </div>
                </div>
            </div>
            <div class="controls">
                <button class="btn btn-prev" id="prevBtn" onclick="previousCard()">Previous</button>
                <button class="btn btn-flip" onclick="flipCard()">Flip</button>
                <button class="btn btn-next" id="nextBtn" onclick="nextCard()">Next</button>
            </div>
            <div class="knowledge-buttons">
                <button class="btn btn-know" onclick="markCard('known')">I know this</button>
                <button class="btn btn-learning" onclick="markCard('learning')">Still learning</button>
                <button class="btn btn-unknown" onclick="markCard('unknown')">Don't know</button>
            </div>
        </div>`;
}

function progressKey() {
    return `heimdall_fc_${getDeckId()}`;
}

function openDeck(id) {
    setDeckId(id);
    route();
}

function goHome() {
    setDeckId(null);
    route();
}

function initStudy(id) {
    deck = deckData.decks.find(d => d.id === id);
    if (!deck) {
        renderError("Deck not found", `No deck with id "${escapeHtml(id)}". Rebuild the hub or pick from the list.`);
        return;
    }

    renderStudy();
    flashcards = deck.cards;
    document.getElementById("deckTitle").textContent = deck.title;
    document.getElementById("deckSubtitle").textContent = `${deck.course} · ${deck.path}`;

    const saved = localStorage.getItem(progressKey());
    cardStatus = saved ? JSON.parse(saved) : Array(flashcards.length).fill("unknown");
    if (cardStatus.length !== flashcards.length) {
        cardStatus = Array(flashcards.length).fill("unknown");
    }

    currentIndex = 0;
    isFlipped = false;
    filteredIndices = [...Array(flashcards.length).keys()];
    displayCard();
    updateStats();
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
    document.getElementById("knownCount").textContent = cardStatus.filter(s => s === "known").length;
    document.getElementById("unknownCount").textContent = cardStatus.filter(s => s === "unknown" || s === "learning").length;
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

function filterCards(filter, btn) {
    currentIndex = 0;
    if (isFlipped) flipCard();
    document.querySelectorAll(".btn-filter").forEach(el => el.classList.remove("active"));
    btn.classList.add("active");

    if (filter === "all") {
        filteredIndices = [...Array(flashcards.length).keys()];
    } else if (filter === "known") {
        filteredIndices = cardStatus.map((s, i) => (s === "known" ? i : -1)).filter(i => i !== -1);
    } else if (filter === "unknown") {
        filteredIndices = cardStatus.map((s, i) => (s === "unknown" || s === "learning" ? i : -1)).filter(i => i !== -1);
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

function route() {
    const id = getDeckId();
    if (id) initStudy(id);
    else renderList(deckData);
}

async function boot() {
    try {
        deckData = await loadDecksScript();
        route();
    } catch (err) {
        renderError(
            "Could not load flashcard data",
            `${err.message}. Run <code>python 91-SCRIPTS/build-flashcard-hub.py</code> first.`
        );
    }
}

window.addEventListener("hashchange", () => {
    if (deckData) route();
});

document.addEventListener("keydown", e => {
    if (!getDeckId()) return;
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

boot();
