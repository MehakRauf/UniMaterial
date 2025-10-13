import math

data = [
    ("buy cheap now", "spam"),
    ("limited offer buy", "spam"),
    ("hello friend", "ham"),
    ("meet tomorrow friend", "ham")
]

vocab = []
for text, _ in data:
    for word in text.split():
        if word not in vocab:
            vocab.append(word)


N = len(data)  
idf = {}
for word in vocab:
    doc_count = sum(1 for text, _ in data if word in text.split())
    idf[word] = math.log(N / (1 + doc_count))

weights = {word: 0 for word in vocab}

for text, label in data:
    words = text.split()
    for word in words:
        tf = words.count(word) / len(words)  
        tfidf = tf * idf[word]               
        if label == "spam":
            weights[word] += tfidf
        else:
            weights[word] -= tfidf

def predict(text):
    words = text.split()
    print(words)
    score = 0
    for word in words:
        tf = words.count(word) / len(words)
        tfidf = tf * idf.get(word, 0 )
        score += weights.get(word, 0) * tfidf
    return "spam" if score > 0 else "ham"

print("Message: 'buy offer now' ->", predict("buy offer now"))
print("Message: 'hello tomorrow' ->", predict("hello tomorrow"))
