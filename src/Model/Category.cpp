#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include "../../library/json.hpp"

using json = nlohmann::json;
std::string source = "../../database/categories.json";
class Category
{
public:
    int id;
    std::string name;
    std::string slug;

    Category() = default;

    Category(int id, const std::string &name, const std::string &slug)
        : id(id), name(name), slug(slug) {}

    static std::vector<Category> getAll();
    static Category findById(int categoryId);
    static void edit(const Category &updatedCategory);
    static void create(const Category &newCategory);
    static void deleteCategory(const Category &categoryToDelete);
};

std::vector<Category> Category::getAll()
{
    std::vector<Category> categories;

    // Load existing categories from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    for (const auto &categoryData : jsonData["categories"])
    {
        Category category;
        category.id = categoryData["id"];
        category.name = categoryData["name"];
        category.slug = categoryData["slug"];

        categories.push_back(category);
    }

    return categories;
}

Category Category::findById(int categoryId)
{
    // Load existing categories from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    for (const auto &categoryData : jsonData["categories"])
    {
        if (categoryData["id"] == categoryId)
        {
            Category category;
            category.id = categoryData["id"];
            category.name = categoryData["name"];
            category.slug = categoryData["slug"];

            return category;
        }
    }

    // Return an empty category if not found
    return Category();
}

void Category::edit(const Category &updatedCategory)
{
    // Load existing categories from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Find and update the category with matching id
    for (auto &categoryData : jsonData["categories"])
    {
        if (categoryData["id"] == updatedCategory.id)
        {
            categoryData["name"] = updatedCategory.name;
            categoryData["slug"] = updatedCategory.slug;
            break;
        }
    }

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

void Category::create(const Category &newCategory)
{
    // Load existing categories from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Add the new category to the JSON data
    json newCategoryJson;
    newCategoryJson["id"] = newCategory.id;
    newCategoryJson["name"] = newCategory.name;
    newCategoryJson["slug"] = newCategory.slug;

    jsonData["categories"].push_back(newCategoryJson);

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

void Category::deleteCategory(const Category &categoryToDelete)
{
    // Load existing categories from JSON
    json jsonData;
    std::ifstream inputFile(source);
    inputFile >> jsonData;
    inputFile.close();

    // Find and remove the category with matching id
    auto &categoriesArray = jsonData["categories"];
    categoriesArray.erase(std::remove_if(categoriesArray.begin(), categoriesArray.end(),
                                         [&categoryToDelete](const auto &categoryData)
                                         {
                                             return categoryData["id"] == categoryToDelete.id &&
                                                    categoryData["name"] == categoryToDelete.name &&
                                                    categoryData["slug"] == categoryToDelete.slug;
                                         }),
                          categoriesArray.end());

    // Write the updated data back to JSON file
    std::ofstream outputFile(source);
    outputFile << std::setw(4) << jsonData;
    outputFile.close();
}

int main()
{
    // Testing getAll function
    std::cout << "getAll() Function Test:\n";
    std::vector<Category> allCategories = Category::getAll();
    for (const auto &category : allCategories)
    {
        std::cout << "Category ID: " << category.id << ", Name: " << category.name << "\n";
    }
    std::cout << "\n";

    // Testing findById function
    std::cout << "findById() Function Test:\n";
    int categoryIdToFind = 2;
    Category foundCategory = Category::findById(categoryIdToFind);
    if (foundCategory.id != 0)
    {
        std::cout << "Found Category - ID: " << foundCategory.id << ", Name: " << foundCategory.name << "\n";
    }
    else
    {
        std::cout << "Category with ID " << categoryIdToFind << " not found.\n";
    }
    std::cout << "\n";

    // Testing edit function
    std::cout << "edit() Function Test:\n";
    Category categoryToEdit = foundCategory; // Use the category found in the previous test
    categoryToEdit.name = "Updated Category Name";
    categoryToEdit.slug = "updated-slug";
    Category::edit(categoryToEdit);
    std::cout << "Category after editing:\n";
    Category editedCategory = Category::findById(categoryIdToFind);
    std::cout << "Edited Category - ID: " << editedCategory.id << ", Name: " << editedCategory.name << "\n";
    std::cout << "\n";

    // Testing create function
    std::cout << "create() Function Test:\n";
    Category newCategory(4, "New Category", "new-slug");
    Category::create(newCategory);
    std::cout << "Newly Created Category:\n";
    Category createdCategory = Category::findById(4);
    std::cout << "Created Category - ID: " << createdCategory.id << ", Name: " << createdCategory.name << "\n";
    std::cout << "\n";

    // Testing deleteCategory function
    std::cout << "deleteCategory() Function Test:\n";
    Category categoryToDelete = createdCategory; // Use the category created in the previous test
    Category::deleteCategory(categoryToDelete);
    std::cout << "Category after deleting:\n";
    Category deletedCategory = Category::findById(4);
    if (deletedCategory.id != 0)
    {
        std::cout << "Category still found after deletion. Something went wrong!\n";
    }
    else
    {
        std::cout << "Category successfully deleted.\n";
    }

    return 0;
}
