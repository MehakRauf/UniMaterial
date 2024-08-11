class Rule:
    def _init_(self, condition, action):
        self.condition = condition
        self.action = action

    def evaluate(self, facts):
        if all(fact in facts for fact in self.condition):
            return self.action
        else:
            return None

class InferenceEngine:
    def _init_(self):
        self.rules = []

    def add_rule(self, condition, action):
        rule = Rule(condition, action)
        self.rules.append(rule)

    def infer(self, facts):
        for rule in self.rules:
            result = rule.evaluate(facts)
            if result:
                return result
        return None

# Example usage:
if __name__ == "_main_":
    engine = InferenceEngine()

    # Define rules
    engine.add_rule(["sunny", "warm"], "go for a walk")
    engine.add_rule(["rainy"], "stay indoors")
    engine.add_rule(["snowy"], "build a snowman")

    # Facts
    facts = ["sunny", "warm"]

    # Inference
    action = engine.infer(facts)
    if action:
        print("Action to take:", action)
    else:
        print("No action inferred.")