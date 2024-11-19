# BankSystem

### Repository Description: **Bank Management System**

#### Overview  
This repository contains a comprehensive **Bank Management System** built using **C++**, designed to manage bank operations effectively with separate functionalities for clients and administrators. It implements **functional programming (FP)** concepts for modular and maintainable code.

---

#### Features  
1. **Client-Side Functionalities**:
   - Account creation (savings, current, etc.).
   - View account details and transaction history.
   - Deposit and withdraw funds.
   - Transfer money between accounts.
   - Request services (e.g., loans, checkbooks).

2. **Admin-Side Functionalities**:
   - Manage user accounts (add, update, delete).
   - Monitor transactions and generate reports.
   - Approve or reject client service requests.
   - Manage interest rates and loan details.
   - Ensure compliance with regulations.

3. **Functional Programming (FP) Concepts**:
   - Utilizes pure functions for transaction processing and validations.
   - Higher-order functions for account management and reporting.
   - Immutable data structures where applicable for safety.

4. **Data Storage**:
   - Simple file-based storage for persistent data.
   - Future-ready for integration with databases like SQLite or MySQL.

5. **Security**:
   - Password-protected login for both clients and admins.
   - Basic encryption for sensitive data like passwords.

6. **Scalability**:
   - Modular design with reusable components for future enhancements.

---

#### Technologies Used  
- **C++**: Core programming language.
- **File Handling**: For persistent storage.
- **Functional Programming Principles**: For cleaner, testable code.
- **CLI Interface**: User-friendly command-line interface.

---

#### Structure  
- **src/**: Contains source code files for clients and admin modules.  
- **include/**: Header files for reusable components.  
- **data/**: Stores client and transaction data.  
- **tests/**: Unit tests for key functionalities.  

---

#### Getting Started  
1. Clone the repository:  
   ```bash
   git clone  https://github.com/mohbkceo/BankSystem.git
   cd bank_manage
   ```
2. Compile the code:  
   ```bash
   g++ -o bank_manage bankCode.cpp -std=c++17
   ```
3. Run the application:  
   ```bash
   ./bank_manage
   ```

---

#### Future Enhancements  
- GUI-based client and admin interfaces.  
- Integration with cloud-based databases.  
- Advanced security features like multi-factor authentication.  
- Support for internationalization and currency conversion.  

---

#### Contributing  
Contributions are welcome! Fork the repository and submit a pull request with your improvements or bug fixes.  

**License**: MIT  

