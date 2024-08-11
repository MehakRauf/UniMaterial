import random
import operator
import math
import functools

from deap import base, creator, tools, gp

# Define the symbolic regression function
def symbolic_regression(x):
    return 5 * x**3 - 6 * x**2 + 8 * x

# Define the evaluation function (Root Mean Square Error)
def eval_rmse(individual, points):
    symbolic_expr = toolbox.compile(expr=individual)
    rmse = math.sqrt(sum((symbolic_expr(x) - symbolic_regression(x))**2 for x in points) / len(points))
    return rmse,

# Define the Primitive Set
pset = gp.PrimitiveSet("MAIN", arity=1)
pset.addPrimitive(operator.add, arity=2)
pset.addPrimitive(operator.sub, arity=2)
pset.addPrimitive(operator.mul, arity=2)
pset.addPrimitive(operator.neg, arity=1)
pset.addPrimitive(math.sin, arity=1)
pset.addPrimitive(math.cos, arity=1)
pset.addPrimitive(math.tan, arity=1)
pset.addEphemeralConstant("const", functools.partial(random.randint, -10, 10))

# Define the Fitness Function
creator.create("FitnessMin", base.Fitness, weights=(-1.0,))
creator.create("Individual", gp.PrimitiveTree, fitness=creator.FitnessMin)

# Create the Toolbox
toolbox = base.Toolbox()
toolbox.register("expr", gp.genHalfAndHalf, pset=pset, min_=1, max_=3)
toolbox.register("individual", tools.initIterate, creator.Individual, toolbox.expr)
toolbox.register("population", tools.initRepeat, list, toolbox.individual)
toolbox.register("compile", gp.compile, pset=pset)
toolbox.register("evaluate", eval_rmse, points=[x for x in range(-10, 11)])
toolbox.register("select", tools.selTournament, tournsize=3)
toolbox.register("mate", gp.cxOnePoint)
toolbox.register("mutate", gp.mutNodeReplacement, pset=pset)

# Define Parameters
pop_size = 500
num_generations = 10

# Create Initial Population
population = toolbox.population(n=pop_size)

# Evolutionary Loop
for gen in range(num_generations):
    # Evaluate the population
    fitnesses = toolbox.map(toolbox.evaluate, population)
    for ind, fit in zip(population, fitnesses):
        ind.fitness.values = fit

    # Select the next generation individuals
    offspring = toolbox.select(population, len(population))

    # Clone the selected individuals
    offspring = list(map(toolbox.clone, offspring))

    # Apply crossover and mutation
    for child1, child2 in zip(offspring[::2], offspring[1::2]):
        if random.random() < 0.5:
            toolbox.mate(child1, child2)
            del child1.fitness.values
            del child2.fitness.values

    for mutant in offspring:
        if random.random() < 0.2:
            toolbox.mutate(mutant)
            del mutant.fitness.values

    # Replace the population with the offspring
    population[:] = offspring

    # Gather all the fitnesses in one list
    fits = [ind.fitness.values[0] if ind.fitness.valid else None for ind in population]
    mean = sum(fit for fit in fits if fit is not None) / len(population)
    print(f"Generation {gen+1}: Min Fitness = {min(fit for fit in fits if fit is not None)}, Max Fitness = {max(fit for fit in fits if fit is not None)}, Avg Fitness = {mean}")

# Select the best individual
best_ind = tools.selBest(population, 1)[0]
print("\nBest Individual:", best_ind)

