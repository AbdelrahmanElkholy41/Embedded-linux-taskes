class EmployeeManagement:
    def __init__(self):
        self.employees = []  # List to store employee data
        self.next_id = 1  # ID generator for new employees

    def add_employee(self):
        name = input("Please Enter Employee Name: ")
        job = input("Please Enter Employee Job: ")
        salary = float(input("Please Enter Employee Salary: "))
        employee = {
            "id": self.next_id,
            "name": name,
            "job": job,
            "salary": salary
        }
        self.employees.append(employee)
        print(f"Employee {name} added successfully with ID {self.next_id}.")
        self.next_id += 1

    def print_employee_data(self):
        if self.employees:
            for emp in self.employees:
                print(f"ID: {emp['id']}, Name: {emp['name']}, Job: {emp['job']}, Salary: {emp['salary']}")
        else:
            print("No employees found.")

    def remove_employee(self):
     emp_id = int(input("Enter Employee ID to remove: "))
     for emp in self.employees:
        if emp['id'] == emp_id:
            self.employees.remove(emp)
            print(f"Employee with ID {emp_id} removed successfully.")
            break
     else:
        print(f"No employee found with ID {emp_id}.")


    def display_menu(self):
        while True:
            print("\nEmployee Management System")
            print("1. Add New Employee")
            print("2. Print Employee Data")
            print("3. Remove Employee")
            print("4. Exit")

            choice = input("Enter your choice: ")

            if choice == '1':
                self.add_employee()
            elif choice == '2':
                self.print_employee_data()
            elif choice == '3':
                self.remove_employee()
            elif choice == '4':
                print("Exiting the system. Goodbye!")
                break
            else:
                print("Invalid choice. Please try again.")



ems = EmployeeManagement()
ems.display_menu()
