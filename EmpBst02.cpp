#include <iostream>
#include <string>
using namespace std;

class BST {
public:
    int id;
    string name;
    int salary;
    BST* left;
    BST* right;

    BST(int empId, string empName, int empSalary) {
        id = empId;
        name = empName;
        salary = empSalary;
        left = NULL;
        right = NULL;
    }
};

BST* root = NULL;

// Function to insert a node into BST (Recursive)
BST* insert(BST* root, int empId, string empName, int empSalary) {
    if (root == NULL) {
        return new BST(empId, empName, empSalary);
    }

    if (empSalary < root->salary) {
        root->left = insert(root->left, empId, empName, empSalary);
    } else {
        root->right = insert(root->right, empId, empName, empSalary);
    }

    return root;
}

// Function to create BST with user input
void createAndInsert() {
    int empId, empSalary, ch;
    string empName;
    do {
        cout << "ENTER EMPLOYEE ID: ";
        cin >> empId;
        cout << "ENTER EMPLOYEE NAME: ";
        cin.ignore();
        getline(cin, empName);
        cout << "ENTER SALARY: ";
        cin >> empSalary;

        root = insert(root, empId, empName, empSalary);

        cout << "WANT TO ENTER MORE? (0/1): ";
        cin >> ch;
    } while (ch != 0);
}

// Function to display BST (In-order Traversal)
void display(BST* root) {
    if (root == NULL) return;

    display(root->left);
    cout << "ID: " << root->id << ", Name: " << root->name << ", Salary: " << root->salary << endl;
    display(root->right);
}

// Function to find the minimum salary
int findMin(BST* root) {
    if (root == NULL) return -1;
    while (root->left != NULL) {
        root = root->left;
    }
    return root->salary;
}

// Function to find the maximum salary
int findMax(BST* root) {
    if (root == NULL) return -1;
    while (root->right != NULL) {
        root = root->right;
    }
    return root->salary;
}

// Function to compute the total number of employees
int countEmployees(BST* root) {
    if (root == NULL) return 0;
    return 1 + countEmployees(root->left) + countEmployees(root->right);
}

// Function to compute the average salary
double computeAverage(BST* root, int& count) {
    if (root == NULL) return 0;

    double leftSum = computeAverage(root->left, count);
    double rightSum = computeAverage(root->right, count);

    count++;
    return leftSum + root->salary + rightSum;
}

// Function to find salaries in a given range
void salaryRange(BST* root, int minSalary, int maxSalary) {
    if (root == NULL) return;

    if (root->salary > minSalary) {
        salaryRange(root->left, minSalary, maxSalary);
    }

    if (root->salary >= minSalary && root->salary <= maxSalary) {
        cout << "ID: " << root->id << ", Name: " << root->name << ", Salary: " << root->salary << endl;
    }

    if (root->salary < maxSalary) {
        salaryRange(root->right, minSalary, maxSalary);
    }
}

// Function to find the minimum value node in a subtree
BST* findMinNode(BST* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Recursive function to delete an employee from the BST
BST* deleteRecursive(BST* root, int key) {
    if (root == NULL) return root;

    if (key < root->salary) {
        root->left = deleteRecursive(root->left, key);
    } else if (key > root->salary) {
        root->right = deleteRecursive(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        } else if (root->left == NULL) {
            BST* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            BST* temp = root->left;
            delete root;
            return temp;
        }
        BST* temp = findMinNode(root->right);
        root->salary = temp->salary;
        root->right = deleteRecursive(root->right, temp->salary);
    }
    return root;
}

int main() {
    int c;
    do {
        cout << "\n1. Insert Employee\n2. Display Employees\n3. Find Minimum Salary\n4. Find Maximum Salary";
        cout << "\n5. Compute Average Salary\n6. Count Employees\n7. Salary Range Query\n8. Delete Employee by Salary\n9. Exit\nEnter choice: ";
        cin >> c;

        switch (c) {
            case 1:
                createAndInsert();
                break;
            case 2:
                cout << "Employee Records: \n";
                display(root);
                break;
            case 3:
                cout << "Minimum Salary: " << findMin(root) << endl;
                break;
            case 4:
                cout << "Maximum Salary: " << findMax(root) << endl;
                break;
            case 5: {
                int count = 0;
                double totalSalary = computeAverage(root, count);
                cout << "Average Salary: " << (count == 0 ? 0 : totalSalary / count) << endl;
                break;
            }
            case 6:
                cout << "Total Number of Employees: " << countEmployees(root) << endl;
                break;
            case 7: {
                int minS, maxS;
                cout << "Enter minimum salary: ";
                cin >> minS;
                cout << "Enter maximum salary: ";
                cin >> maxS;
                cout << "Employees in range [" << minS << ", " << maxS << "]: \n";
                salaryRange(root, minS, maxS);
                break;
            }
            case 8: {
                int delSal;
                cout << "Enter salary to delete: ";
                cin >> delSal;
                root = deleteRecursive(root, delSal);
                cout << "Employee deleted successfully!\n";
                break;
            }
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (c != 9);

    return 0;
}
