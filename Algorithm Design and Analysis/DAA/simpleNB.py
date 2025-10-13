def train_naive_bayes(data, labels):
    spam_words={}
    ham_words = {}
    spam_count =0
    ham_count = 0

    for text, label in zip(data, labels):
        words = text.lower().split()
        if label == "spam":
            spam_count += 1
            for w in words:
                spam_words[w] = spam_words.get(w, 0) + 1
        else:
            ham_count += 1
            for w in words:
                ham_words[w] = ham_words.get(w, 0) + 1
    print(ham_words)
    return spam_words, ham_words, spam_count, ham_count

def predict(text, spam_words, ham_words, spam_count, ham_count):
    words = text.lower().split()
    p_spam = spam_count / (spam_count + ham_count)
    p_ham = ham_count / (spam_count + ham_count)

    for w in words:
        p_spam *= (spam_words.get(w, 0) + 1) / (sum(spam_words.values()) + len(spam_words))
        p_ham *= (ham_words.get(w, 0) + 1) / (sum(ham_words.values()) + len(ham_words))

    return "spam" if p_spam > p_ham else "ham"

data = ["win money now", "buy cheap meds", "hello friend", "let's meet tomorrow"]
labels = ["spam", "spam", "ham", "ham"]

spam_words, ham_words, spam_count, ham_count = train_naive_bayes(data, labels)
print(predict("buy cheap", spam_words, ham_words, spam_count, ham_count))
print(predict("hello tomorrow", spam_words, ham_words, spam_count, ham_count))
