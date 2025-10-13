from sklearn.feature_extraction.text import CountVectorizer
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split

# Sample data
emails = [
    "Win money now",
    "Buy cheap products",
    "Hey, are we meeting later?",
    "Your appointment is confirmed",
    "Congratulations, you have won!"
]
labels = [1, 1, 0, 0, 1]  # 1 = spam, 0 = not spam

# Convert text to features
vectorizer = CountVectorizer()
X = vectorizer.fit_transform(emails)

# Split
X_train, X_test, y_train, y_test = train_test_split(X, labels, test_size=0.4, random_state=42)

# Train SVM model
model = SVC(kernel='linear')  # linear = simple, easy to visualize
model.fit(X_train, y_train)

# Predict
predictions = model.predict(X_test)

print("Predictions:", predictions)
