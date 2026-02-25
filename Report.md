# C Programming Mini Project Documentation
## SMART BUS RESERVATION SYSTEM

---

## 1. TITLE PAGE

**Project Title:** Smart Bus Reservation System


## 2. ABSTRACT

The Smart Bus Reservation System is a comprehensive C-based application designed to manage bus reservations and ticketing. The system provides a complete solution for both administrators and users to manage bus operations, book tickets, and handle cancellations. It implements advanced features including user authentication, seat management, multi-passenger booking, payment processing, and ticket management. The program uses file-based storage for data persistence and provides an interactive menu-driven interface with color-coded output for better user experience.

---

## 3. INTRODUCTION

### Problem Being Solved
Traditional manual bus booking systems are time-consuming, error-prone, and inefficient. There is no centralized mechanism for managing seat availability, passenger information, and fare calculations across different routes and dates.

### Why This Project is Useful
- Automates the entire bus reservation process
- Reduces booking time and human errors
- Provides real-time seat availability information
- Manages multiple passengers efficiently
- Maintains complete booking records
- Implements category-based fare calculation (Adult, Child, Infant)

### Where It Can Be Used
- Bus management companies
- Travel agencies
- Transportation services
- Educational institutions with transport systems
- Tourism and hospitality services

---

## 4. OBJECTIVES

- Understand structured programming using C language
- Implement user authentication and security (login/registration)
- Work with file handling and data structures
- Use arrays, loops, and conditional statements effectively
- Design interactive menu-driven user interfaces
- Implement color-coded console output
- Work with multiple data structures (Bus, Ticket, User)
- Develop logical algorithms for seat management and booking validation
- Improve understanding of real-world application development

---

## 5. TOOLS & TECHNOLOGY

**Programming Language:** C (ANSI C)

**Compiler:** GCC / Code::Blocks / Turbo C

**Platform:** Windows (uses windows.h for console color support)

**Libraries Used:**
- stdio.h - Standard Input/Output
- stdlib.h - Standard Library (memory, system calls)
- string.h - String manipulation
- windows.h - Windows API (console color)
- conio.h - Console Input/Output
- time.h - Time functions

---

## 6. SYSTEM REQUIREMENTS

### Hardware Requirements
- Processor: Intel Pentium or equivalent
- RAM: Minimum 4GB
- Storage: 50MB free disk space
- Display: VGA or higher resolution monitor

### Software Requirements
- Windows Operating System (XP/7/8/10/11)
- C Compiler (GCC, Code::Blocks, or Turbo C)
- Text Editor or IDE for code editing
- Data files storage capability

---

## 6.1 COMPILATION & EXECUTION ON VS CODE

### Important: Configure MinGW Path in compile.bat

Before running the compile.bat script, **verify and update the MinGW compiler path** if needed.

#### Find Your MinGW Installation Path:

1. **Search for MinGW Installation:**
   - Open File Explorer
   - Search for `gcc.exe` on your computer
   - Note the full path (e.g., `C:\MinGW\bin\gcc.exe`)

2. **Common MinGW Installation Paths:**
   ```
   C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\          (Dev-C++)
   C:\MinGW\bin\                                         (Standalone MinGW)
   C:\mingw64\bin\                                       (MinGW-w64)
   C:\Program Files\mingw-w64\x86_64-8.1.0-posix-seh\bin\  (another variant)
   ```

#### How to Update compile.bat Path:

1. **Open compile.bat in Notepad/VS Code:**
   - Right-click on `compile.bat` → Open with → Notepad/Code Editor

2. **Locate the Compiler Paths (Lines 32-34):**
   ```batch
   set "GCC=c:\Program Files (x86)\Dev-Cpp\MinGW64\bin\gcc.exe"
   set "GPP=c:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe"
   ```

3. **Replace with YOUR MinGW Path:**

   **Example 1 - Standalone MinGW:**
   ```batch
   set "GCC=C:\MinGW\bin\gcc.exe"
   set "GPP=C:\MinGW\bin\g++.exe"
   ```

   **Example 2 - MinGW-w64:**
   ```batch
   set "GCC=C:\mingw64\bin\gcc.exe"
   set "GPP=C:\mingw64\bin\g++.exe"
   ```

   **Example 3 - CodeBlocks Installation:**
   ```batch
   set "GCC=C:\Program Files\CodeBlocks\MinGW\bin\gcc.exe"
   set "GPP=C:\Program Files\CodeBlocks\MinGW\bin\g++.exe"
   ```

4. **Save the File:**
   - Press `Ctrl + S` (or File → Save)
   - Keep the file name as `compile.bat`

#### Verify MinGW Path is Correct:

1. **Open Command Prompt** in the project folder
2. **Test the GCC path:**
   ```batch
   "C:\your\mingw\path\gcc.exe" --version
   ```
3. **If successful, you'll see:**
   ```
   gcc (GCC) 9.3.0
   Copyright (C) 2019 Free Software Foundation, Inc.
   ```

#### If GCC Path Not Found:

Try these commands in Command Prompt to auto-detect MinGW:
```batch
where gcc
where g++
```

This will show the correct path if GCC is in your system PATH environment variable.

---

### Setup with compile.bat (Recommended)

The project includes a `compile.bat` script for easy compilation and execution in VS Code or Command Prompt.

#### Prerequisites:
- MinGW GCC Compiler installed (C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\)
- VS Code with C/C++ extension installed
- Command Prompt or PowerShell access

#### Steps to Compile and Run:

1. **Place Files in Same Directory:**
   ```
   C:\Users\[YourUsername]\OneDrive\Desktop\Jemx\
   ├── Bus-Ticket.c
   ├── compile.bat
   └── other files
   ```

2. **Open Command Prompt/PowerShell** in the project folder:
   - Press `Ctrl + Shift + P` in VS Code
   - Type "Terminal: Create New Terminal"
   - Or navigate to the folder and open Command Prompt

3. **Run the Compile Script:**
   ```batch
   compile.bat Bus-Ticket.c
   ```
   or
   ```
   compile Bus-Ticket.c
   ```
   or
   ```
   .\compile Bus-Ticket.c
   ```

4. **What the Script Does:**
   - Compiles Bus-Ticket.c using GCC compiler
   - Generates Bus-Ticket.exe executable
   - Automatically runs the compiled program
   - Displays colored output with status messages
   - Cleans up old executable files

5. **Expected Output:**
   ```
   ===========================================
   Welcome to the C/C++ Compile and Run Script
                version 2.0

             Developed by Jemx
   ===========================================

   Compiling Bus-Ticket.c...
   Compilation successful!

   Running Bus-Ticket.exe ...

   ------------------------------------------
               OUTPUT
   ------------------------------------------
   [Program starts here]
   ```

#### Manual Compilation (Alternative):

If you prefer to compile manually without the .bat script:

```bash
# Using GCC directly
gcc Bus-Ticket.c -o Bus-Ticket.exe

# Run the executable
Bus-Ticket.exe
```

#### VS Code Configuration (Optional):

Create a `.vscode/tasks.json` file:
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Compile with compile.bat",
            "type": "shell",
            "command": "compile.bat",
            "args": ["Bus-Ticket.c"],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "presentation": {
                "reveal": "always"
            }
        }
    ]
}
```

Then press `Ctrl + Shift + B` in VS Code to run the task.

#### Troubleshooting:

| Issue | Solution |
|-------|----------|
| "compile.bat not found" | Ensure compile.bat is in the same folder as Bus-Ticket.c |
| "gcc not found" | Install MinGW GCC or update the path in compile.bat |
| "Input file not specified" | Use: `compile.bat Bus-Ticket.c` (not just filename) |
| Program exits immediately | Add `system("pause");` at the end or use `pause` in Command Prompt |

---

## 7. METHODOLOGY / ALGORITHM

### Main Algorithm Flow:
1. **Start Program** → Display welcome screen with animated loading
2. **User Authentication**
   - Display main menu (Admin/Register/User Login/Exit)
   - Route to appropriate section based on user choice
3. **Admin Panel** (if admin login successful)
   - Add new buses to system
   - View all available buses
   - Delete buses (with booking validation)
   - View all bookings
4. **User Registration**
   - Create new user account
   - Store credentials in users.dat file
5. **User Login**
   - Verify credentials against stored user data
   - Grant access to user panel on success
6. **User Panel** (if user login successful)
   - View available buses
   - Search buses by source/destination
   - Book tickets (single or multiple)
   - View personal tickets
   - Cancel tickets
7. **Ticket Booking Process**
   - Accept bus number and travel details
   - Display seat layout (color-coded: available/booked)
   - Collect passenger information
   - Calculate fare based on age category
   - Process payment
   - Save ticket records
8. **Data Management**
   - Store buses in buses.dat
   - Store users in users.dat
   - Store tickets in tickets.dat
9. **End Program** → Exit system

---

## 8. FLOWCHART

```
                              START
                                |
                    ┌───────────▼───────────┐
                    │  Welcome Screen       │
                    │  (Animated Loading)   │
                    └───────────┬───────────┘
                                |
                    ┌───────────▼────────────────┐
                    │   Main Menu Display        │
                    │ 1. Admin Login             │
                    │ 2. Register User           │
                    │ 3. User Login              │
                    │ 4. Exit                    │
                    └───┬───────────┬────────┬───┘
                        │           │        │
                 ┌──────▼──┐ ┌──────▼──┐  ┌─▼───────┐
                 │ ADMIN    │ │REGISTER │  │USER     │
                 │LOGIN     │ │ USER   │  │LOGIN    │
                 └────┬─────┘ └────┬────┘  └────┬────┘
                      │            │            │
          ┌───────────▼────────┐   │   ┌────────▼──────────┐
          │  Admin Panel       │   │   │  User Panel        │
          │ 1.Add Bus          │   │   │ 1.View Buses       │
          │ 2.View Buses       │   │   │ 2.Search Bus       │
          │ 3.Delete Bus       │   │   │ 3.Book Ticket      │
          │ 4.View Bookings    │   │   │ 4.View My Tickets  │
          │ 5.Logout           │   │   │ 5.Cancel Ticket    │
          └────────┬───────────┘   │   │ 6.Logout           │
                   │               │   └────────┬───────────┘
                   │        ┌──────▼─────┐     │
                   │        │ Store User  │     │
                   │        │ Credentials │     │
                   │        └──────┬──────┘     │
                   │               │            │
                   └───────┬───────┘────────────┘
                           |
                    ┌──────▼──────┐
                    │Back to Menu? │
                    │ Yes/No       │
                    └──┬────────┬──┘
                   Yes │        │
                       │        │ No
                       │        │
                    ┌──▼────┐   │
                    │MAIN    │   │
                    │MENU    │   │
                    └────────┘   │
                                 │
                            ┌────▼─────┐
                            │    END    │
                            └───────────┘
```

---

## 9. PROGRAM CODE

### Key Program Structure:

#### Data Structures (Lines 45-72):
```c
struct Bus{
    int busNo;
    char source[50];
    char destination[50];
    int totalSeats;
    float fare;
};

struct Ticket{
    int ticketID;
    int busNo;
    int seatNo;
    char name[50];
    int age;
    char category[10];
    char phone[20];
    char username[50];
    char travelDate[20];
    char travelTime[10];
    float fare;
};

struct User{
    char username[50];
    char password[50];
};
```

#### Key Functions:
- `color()` - Set console text color
- `header()` - Display formatted header
- `welcomeScreen()` - Animated welcome display
- `registerUser()` - User registration
- `userLogin()` - User authentication
- `adminLogin()` - Admin authentication
- `addBus()` - Add new bus records
- `viewBuses()` - Display all buses
- `searchBus()` - Search buses by route
- `bookTicket()` - Book passenger tickets
- `viewMyTickets()` - Display user's tickets
- `cancelTicket()` - Cancel booked tickets
- `adminPanel()` - Admin menu system
- `userPanel()` - User menu system

---

## 10. SAMPLE INPUT / OUTPUT

### Sample Session 1: Admin Adding a Bus

**Input:**
```
Main Menu Choice: 1 (Admin Login)
Username: admin
Password: 1234

Admin Panel Choice: 1 (Add Bus)
Bus No: 101
Source: Delhi
Destination: Mumbai
Total Seats: 50
Adult Fare: 500.00
```

**Output:**
```
=============================================================
                      ADMIN LOGIN
=============================================================
Admin Login Successful!

=============================================================
                        ADD BUS
=============================================================
Bus Added Successfully!
```

### Sample Session 2: User Booking a Ticket

**Input:**
```
Main Menu Choice: 2 (Register)
Username: john_doe
Password: pass123

Main Menu Choice: 3 (User Login)
Username: john_doe
Password: pass123

User Panel Choice: 3 (Book Ticket)
Bus No: 101
Travel Date: 15/03/2024
Travel Time: 10:30
Number of Passengers: 2

Passenger 1:
Seat No: 5
Name: John Doe
Age: 30
Phone: 9876543210

Passenger 2:
Seat No: 6
Name: Jane Doe
Age: 5
Phone: 9876543210

Payment Choice: 1 (Card)
```

**Output:**
```
=============================================================
                     USER REGISTRATION
=============================================================
Registration Successful!

=============================================================
                       USER LOGIN
=============================================================
Login Successful!

=============================================================
                      SEAT LAYOUT
=============================================================
Bus: 101 | Date: 15/03/2024

[1]  [2]  [3]  [4]
[5]  [x]  [7]  [8]

=============================================================
                       PAYMENT
=============================================================
Total Amount: 750.00
1. Card
2. UPI
3. Cash

Payment Successful!

=============================================================
                    BOOKING PROGRESS
=============================================================
TicketID:45678 | Name:John Doe | Seat:5 | Fare:500.00
TicketID:32145 | Name:Jane Doe | Seat:6 | Fare:250.00

Booking Confirmed!
```

---

## 11. RESULT

The Smart Bus Reservation System has been successfully developed and tested. The program:

✓ Successfully initializes and displays the welcome screen
✓ Implements user authentication for both admin and regular users
✓ Allows creation of new user accounts with password security
✓ Enables admin to add, view, and delete bus records
✓ Implements real-time seat availability checking
✓ Displays interactive seat layout with color coding
✓ Processes multi-passenger bookings with dynamic fare calculation
✓ Supports three payment methods (Card, UPI, Cash)
✓ Maintains all booking records in persistent storage
✓ Allows users to view and cancel their bookings
✓ Implements proper validation for seat selection and user input
✓ Provides color-coded console output for better UI/UX
✓ All file operations (read/write) function correctly
✓ Successfully manages concurrent bookings and prevents double-booking

The program executed successfully with all features working as intended.

---

## 12. APPLICATIONS

- **Bus Transportation Companies**: Complete ticket booking and management system
- **Travel Agencies**: Integrated bus reservation and ticketing solution
- **School/College Transport**: Management of student and staff transportation
- **Tourism Industry**: Bus tour bookings and passenger management
- **Inter-State Transport**: Multi-route booking system for large operators
- **Training Centers**: Teaching structured programming and file handling
- **Learning Resource**: Understanding real-world application development

---

## 13. CONCLUSION

The Smart Bus Reservation System successfully demonstrates the application of fundamental C programming concepts in a real-world scenario. The project integrates multiple programming techniques including:

- Structured data types and organization
- File handling for data persistence
- User authentication and security (basic)
- Interactive menu-driven interfaces
- Console formatting and color output
- Multi-functional application architecture

The system provides a practical foundation for bus booking operations and can be extended with additional features. It showcases how C can be effectively used to build practical applications despite being a lower-level language compared to modern alternatives.

---

## 14. FUTURE ENHANCEMENTS

**Immediate Enhancements:**
- Database integration (SQL) instead of file-based storage
- Email confirmation for bookings
- SMS notifications to passengers
- Advanced seat reservation with cabin selection
- Cancellation refund automation

**User Interface Improvements:**
- GUI using GTK or Qt libraries
- Web-based interface using CGI
- Mobile app integration
- Real-time seat status updates
- Online payment gateway integration

**Advanced Features:**
- Group booking discounts
- Loyalty programs and rewards
- Dynamic pricing based on occupancy
- Route optimization algorithms
- Passenger feedback and ratings
- Employee management system
- Travel history and preferences tracking
- Multi-language support
- Accessibility features for disabled passengers

**Performance & Scalability:**
- Migration to Client-Server architecture
- Distributed database system
- Load balancing
- Caching mechanisms
- Cloud-based deployment

---

## 15. REFERENCES

**Books:**
- "The C Programming Language" by Brian W. Kernighan and Dennis M. Ritchie
- "C Programming Absolute Beginner's Guide" by Perry and Miller
- "Expert C Programming" by Peter van der Linden

**Online Resources:**
- tutorialspoint.com/cprogramming
- geeksforgeeks.org/c-programming
- stackoverflow.com (C programming tag)
- cprogramming.com

**Related Documentation:**
- Windows API Documentation
- Standard C Library Reference
- File I/O Programming Guide
- Data Structures and Algorithms

---

**End of Document**

*This documentation follows the C Programming Mini Project template and provides a comprehensive overview of the Smart Bus Reservation System project, suitable for academic submission.*
