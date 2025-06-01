function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min + 1)) + min;
}

function getRandomOperator() {
    const operators = ['+', '-', '*', '%'];
    return operators[Math.floor(Math.random() * operators.length)];
}

document.addEventListener("DOMContentLoaded", function() {
    const quizContainer = document.getElementById("quiz");
    const nextButton = document.getElementById("next");
    const timeDisplay = document.getElementById("time");
    
    let questions = [];
    let currentQuestionIndex = 0;
    let correctAnswers = 0;
    let timeLeft = 120;
    
    // Generate 10 questions in advance
    for (let i = 0; i < 10; i++) {
        let num1 = getRandomInt(-10, 10);
        let num2 = getRandomInt(-10, 10);
        let num3 = getRandomInt(-10, 10);
        let op1 = getRandomOperator();
        let op2 = getRandomOperator();
        let expression = `(${num1}) ${op1} (${num2}) ${op2} (${num3})`;
        let correctResult = eval(expression);
        
        questions.push({ expression, correctResult });
    }

    function showQuestion(index) {
        quizContainer.innerHTML = `
            <div class="question">
                <p>${questions[index].expression} = ?</p>
                <input type="number" id="answer" class="answer"/>
            </div>
        `;
    }

    function checkAnswer() {
        let input = document.getElementById("answer");
        let userAnswer = parseInt(input.value);
        
        if (userAnswer === questions[currentQuestionIndex].correctResult) {
            correctAnswers++;
        }

        currentQuestionIndex++;

        if (currentQuestionIndex < 10) {
            showQuestion(currentQuestionIndex);
        } else {
            displayFinalResult();
        }
    }

    function displayFinalResult() {
        clearInterval(timer); 
    
        quizContainer.innerHTML = "";
        nextButton.style.display = "none";
        
        let resultDiv = document.getElementById("result");
        resultDiv.innerText = `You got ${correctAnswers} out of 10 correct!`;
        resultDiv.style.display = "block";
    
        if (correctAnswers >= 7) confetti(); 
    }
    

    // Timer functionality
    const timer = setInterval(() => {
        timeLeft--;
        timeDisplay.textContent = timeLeft;
        if (timeLeft <= 0) {
            clearInterval(timer);
            displayFinalResult();
        }
    }, 1000);

    nextButton.addEventListener("click", checkAnswer);

    showQuestion(0);
});
