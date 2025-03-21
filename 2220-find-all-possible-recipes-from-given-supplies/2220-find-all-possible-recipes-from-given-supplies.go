func findAllRecipes(recipes []string, ingredients [][]string, supplies []string) []string {
    availableSupplies := make(map[string]bool)
    recipeToIngredients := make(map[string][]string)
    visited := make(map[string]int)
    result := []string{}

    for _, supply := range supplies {
        availableSupplies[supply] = true
    }

    for i, recipe := range recipes {
        recipeToIngredients[recipe] = ingredients[i]
    }

    var canMake func(string) bool
    canMake = func(recipe string) bool {
        if val, exists := visited[recipe]; exists {
            return val == 1
        }

        if availableSupplies[recipe] {
            return true
        }

        if _, exists := recipeToIngredients[recipe]; !exists {
            return false
        }

        visited[recipe] = 0

        for _, ingredient := range recipeToIngredients[recipe] {
            if !canMake(ingredient) {
                visited[recipe] = -1
                return false
            }
        }

        visited[recipe] = 1
        result = append(result, recipe)
        return true
    }

    for _, recipe := range recipes {
        canMake(recipe)
    }

    return result
}