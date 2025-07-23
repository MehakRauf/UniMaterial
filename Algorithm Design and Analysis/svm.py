import matplotlib.pyplot as plt

# Email data: [TF-IDF("free"), TF-IDF("meeting")]
emails = {
    "E1": ([0.0248, 0], 1),  # Spam
    "E2": ([0, 0.031], 0),   # Not Spam
    "E3": ([0.031, 0], 1),   # Spam
    "E4": ([0, 0.031], 0)    # Not Spam
}

# Prepare data
x_vals = [emails[e][0][0] for e in emails]
y_vals = [emails[e][0][1] for e in emails]
colors = ['red' if emails[e][1] == 1 else 'green' for e in emails]
labels = list(emails.keys())

# Plot
plt.figure(figsize=(7, 6))
plt.scatter(x_vals, y_vals, c=colors, s=100, edgecolors='black')

# Annotations
for i, txt in enumerate(labels):
    plt.annotate(txt, (x_vals[i] + 0.001, y_vals[i] + 0.001))

# Axes
plt.xlabel("TF-IDF of 'free'")
plt.ylabel("TF-IDF of 'meeting'")
plt.title("2D Plot of Emails for SVM Spam Detection")
plt.axhline(0, color='gray', linewidth=0.5)
plt.axvline(0, color='gray', linewidth=0.5)
plt.grid(True)
plt.show()
