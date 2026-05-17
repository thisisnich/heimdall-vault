let currentIndex = 0;
let isFlipped = false;
let cardStatus = new Array(flashcards.length).fill('unknown');
let currentFilter = 'all';
let filteredIndices = [...Array(flashcards.length).keys()];

function loadProgress() {
    const saved = localStorage.getItem('ege322_flashcard_progress');
    if (saved) {
        cardStatus = JSON.parse(saved);
        updateStats();
    }
}

function saveProgress() {
    localStorage.setItem('ege322_flashcard_progress', JSON.stringify(cardStatus));
}

function displayCard() {
    const card = flashcards[filteredIndices[currentIndex]];
    document.getElementById('questionContent').innerHTML = card.question;
    document.getElementById('answerContent').innerHTML = card.answer;
    
    const cardNum = `${currentIndex + 1} / ${filteredIndices.length}`;
    document.getElementById('cardNumber').textContent = cardNum;
    document.getElementById('cardNumberBack').textContent = cardNum;
    document.getElementById('currentCard').textContent = currentIndex + 1;
    
    updateProgress();
    updateButtons();
}

function flipCard() {
    const flashcard = document.getElementById('flashcard');
    isFlipped = !isFlipped;
    flashcard.classList.toggle('flipped');
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

function markCard(status) {
    cardStatus[filteredIndices[currentIndex]] = status;
    saveProgress();
    updateStats();
    
    if (currentIndex < filteredIndices.length - 1) {
        nextCard();
    }
}

function updateStats() {
    const known = cardStatus.filter(s => s === 'known').length;
    const unknown = cardStatus.filter(s => s === 'unknown' || s === 'learning').length;
    
    document.getElementById('knownCount').textContent = known;
    document.getElementById('unknownCount').textContent = unknown;
    document.getElementById('totalCards').textContent = filteredIndices.length;
}

function updateProgress() {
    const progress = ((currentIndex + 1) / filteredIndices.length) * 100;
    document.getElementById('progressBar').style.width = progress + '%';
}

function updateButtons() {
    document.getElementById('prevBtn').disabled = currentIndex === 0;
    document.getElementById('nextBtn').disabled = currentIndex === filteredIndices.length - 1;
}

function filterCards(filter) {
    currentFilter = filter;
    currentIndex = 0;
    if (isFlipped) flipCard();
    
    document.querySelectorAll('.btn-filter').forEach(btn => {
        btn.classList.remove('active');
    });
    event.target.classList.add('active');
    
    if (filter === 'all') {
        filteredIndices = [...Array(flashcards.length).keys()];
    } else if (filter === 'known') {
        filteredIndices = cardStatus.map((s, i) => s === 'known' ? i : -1).filter(i => i !== -1);
    } else if (filter === 'unknown') {
        filteredIndices = cardStatus.map((s, i) => (s === 'unknown' || s === 'learning') ? i : -1).filter(i => i !== -1);
    } else if (filter === 'critical') {
        filteredIndices = flashcards.map((card, i) => card.critical ? i : -1).filter(i => i !== -1);
    }
    
    if (filteredIndices.length === 0) {
        alert('No cards match this filter!');
        filterCards('all');
        return;
    }
    
    updateStats();
    displayCard();
}

function shuffleCards() {
    filteredIndices = filteredIndices.sort(() => Math.random() - 0.5);
    currentIndex = 0;
    if (isFlipped) flipCard();
    displayCard();
}

document.addEventListener('keydown', (e) => {
    if (e.key === 'ArrowLeft') previousCard();
    if (e.key === 'ArrowRight') nextCard();
    if (e.key === ' ' || e.key === 'Enter') {
        e.preventDefault();
        flipCard();
    }
    if (e.key === '1') markCard('known');
    if (e.key === '2') markCard('learning');
    if (e.key === '3') markCard('unknown');
});

loadProgress();
displayCard();
