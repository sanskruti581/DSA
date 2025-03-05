#include <iostream>
#include <string>
#include <stack>
using namespace std;

class EMP {
public:
    int id;
    string name;
    int salary;
    EMP* left;
    EMP* right;

    EMP(int empId, string empName, int empSalary) {
        id = empId;
        name = empName;
        salary = empSalary;
        left = NULL;
        right = NULL;
    }
};

EMP* root = NULL;

// Function to insert a new employee into the BST based on salary
EMP* insert(EMP* root, int empId, string empName, int empSalary) {
    if (root == NULL) {
        return new EMP(empId, empName, empSalary);
    }

    if (empSalary < root->salary) {
        root->left = insert(root->left, empId, empName, empSalary);
    } else {
        root->right = insert(root->right, empId, empName, empSalary);
    }

    return root;
}

// Function to create and insert employees into the BST
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

// Function to display the BST in sorted order (Inorder Traversal)
void display(EMP* root) {
    if (root == NULL) return;

    display(root->left);
    cout << "ID: " << root->id << ", Name: " << root->name << ", Salary: " << root->salary << endl;
    display(root->right);
}

// Function to find the minimum salary in the BST
int findMin(EMP* root) {
    if (root == NULL) return -1;
    while (root->left != NULL) {
        root = root->left;
    }
    return root->salary;
}

// Function to find the maximum salary in the BST
int findMax(EMP* root) {
    if (root == NULL) return -1;
    while (root->right != NULL) {
        root = root->right;
    }
    return root->salary;
}

// Function to count the total number of employees in the BST
int countEmployees(EMP* root) {
    if (root == NULL) return 0;
    return 1 + countEmployees(root->left) + countEmployees(root->right);
}

// **Iterative function to compute average salary using stack (Inorder Traversal)**
void avgsal(EMP* root) {
    if (root == NULL) return;

    stack<EMP*> s;
    double total = 0;
    int cnt = 0;

    while (root != NULL || !s.empty()) {
        if (root) {
            s.push(root);
            root = root->left;
        } else {
            root = s.top();
            s.pop();
            total += root->salary;
            cnt++;
            root = root->right;
        }
    }
    cout << "Average Salary: " << (cnt == 0 ? 0 : total / cnt) << endl;
}

// Function to display employees within a given salary range
void salaryRange(EMP* root, int minSalary, int maxSalary) {
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

// **Function to delete an employee based on salary**
EMP* delete1(EMP* root, int x) {
    if (root == NULL) return NULL; // Base case: Tree is empty or node not found

    // Search for the node to be deleted
    if (x < root->salary) {
        root->left = delete1(root->left, x);
    } else if (x > root->salary) {
        root->right = delete1(root->right, x);
    } else { 
        // **Case 1: Node with only one child or no child**
        if (root->left == NULL) { // Only right child exists or no child
            EMP* temp = root->right;
            delete root;
            return temp; // Right child is directly connected to parent
        } else if (root->right == NULL) { // Only left child exists
            EMP* temp = root->left;
            delete root;
            return temp; // Left child is directly connected to parent
        }

        // **Case 2: Node with two children**
        // Find in-order successor (smallest in the right subtree)
        EMP* successor = root->right;
        while (successor->left != NULL) {
            successor = successor->left;
        }

        // Replace the node's salary with the successor's salary
        root->salary = successor->salary;

        // Delete the successor node from the right subtree
        root->right = delete1(root->right, successor->salary);
    }
    return root;
}

// Function to update an employee's name by ID
void update(EMP* root, EMP* newNode) {
    if (root == NULL) return;

    if (root->id == newNode->id) {
        root->name = newNode->name;
        return;
    }

    update(root->left, newNode);
    update(root->right, newNode);
}

// **Main function with menu-driven approach**
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
            case 5:
                avgsal(root); // Calls the iterative average salary function
                break;
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
                root = delete1(root, delSal);
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
