from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.model_selection import train_test_split

# Sample data
emails = [
    "Win a free lottery now",
    "Get cheap loans instantly",
    "Hi friend, how are you?",
    "Let's meet tomorrow",
    "Congratulations, you won money"
]
labels = [1, 1, 0, 0, 1]  # 1 = spam, 0 = not spam

# Convert text → numerical features
vectorizer = CountVectorizer()
X = vectorizer.fit_transform(emails)

# Split data
X_train, X_test, y_train, y_test = train_test_split(X, labels, test_size=0.4, random_state=42)

# Train Naive Bayes model
model = MultinomialNB()
model.fit(X_train, y_train)

# Predict
predictions = model.predict(X_test)

print("Predictions:", predictions)
