import csv
import random
import names

def randomdepartment():
    job_titles = [
    "Office Mgr.",    "Asst. (Admin)",    "Clerk",    "Data Entry Spec.",
    "Support Staff",    "Coord.",    "Recpt.",    "Assoc.",    "Jr. Assoc.",
    "Int. (Intern)",    "Trainee",    "Apprentice",    "Gen. Asst.",    "Off. Staff",
    "Records Clerk",    "File Clerk",    "Mail Clerk",    "Bookkeeper",
    "Receptionist",    "Admin. Tech.",    "Office Coord.",    "Jr. Coord.",
    "Proc. Asst.",    "HR Asst.",    "Recruiter",    "Talent Acq. Spec.",
    "HR Coord.",    "Payroll Spec.",    "L&D Spec.",    "HR Gen.",    "Comp. Anlst.",
    "HRIS Admin.",    "People Ops Gen.",    "Talent Mgr. Asst.",    "Jr. Recruiter",
    "Workforce Anlst.",    "HR Cons. Asst.",    "HRBP Asst.",   "Jr. Benefits Spec.",
    "T&D Coord.",    "Org. Dev. Asst.",    "Acct. Clerk",    "Jr. Acct.",
    "Bookkeeper",    "Payroll Acct.",    "Fin. Anlst.",    "Tax Acct.",
    "AR Clerk",    "AP Spec.",    "Jr. Auditor",    "Budget Anlst.",
    "Treasury Anlst.",    "Credit Anlst.",    "Compliance Anlst.",    "Risk Anlst.",
    "Acct. Asst.",    "Sr. Acct.",    "Fin. Assoc.",    "Inv. Anlst. Asst.",
    "Jr. Compliance Off.",    "Jr. Fin. Anlst.",    "Fin. Reporting Spec.",    "Tax Prep. Spec.",
    "Int. Auditor Asst.",    "Forensic Acct. Asst.",    "Billing Spec.",    ]
    return random.choice(job_titles)
def randomsalary():
    return random.randint(50000, 500000)
DATASET_DIR="dataset"
def best_scenario(n):
    with open(f"{DATASET_DIR}/set{n}_ascending.csv", 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['EmployeeID', 'Name','Department', 'Salary'])
        for i in range(1,n+1):
            writer.writerow([i, names.get_full_name(), randomdepartment(),randomsalary()])

def worst_scenario(n):
    with open(f"{DATASET_DIR}/set{n}_descending.csv", 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['EmployeeID', 'Name','Department', 'Salary'])
        for i in range(1,n+1):
            writer.writerow([n-i, names.get_full_name(), randomdepartment(),randomsalary()])

def average_scenario(n):
    id=[i for i in range(1,n+1)]
    random.shuffle(id)
    with open(f"{DATASET_DIR}/set{n}.csv", 'w', newline='') as csvfile:
        writer = csv.writer(csvfile, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
        writer.writerow(['EmployeeID', 'Name','Department', 'Salary'])
        for i in id:
            writer.writerow([i, names.get_full_name(), randomdepartment(),randomsalary()])

def main():
    best_scenario(5000)
    best_scenario(10000)
    best_scenario(20000)
    worst_scenario(5000)
    worst_scenario(10000)
    worst_scenario(20000)
    average_scenario(5000)
    average_scenario(10000)
    average_scenario(20000)
if __name__ == "__main__":
    main()