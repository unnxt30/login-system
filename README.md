# Login-System for a Web Application.

### Build a login system for a web application and ensure that user passwords are stored securely.
Describe a system that: <br />
1. Stores user passwords in a way that makes it difficult for an attacker who gains
access to the database to determine users' actual passwords.<br/>
2. Allows users to log in by verifying their password without storing the password in
plain text.<br/>
3. Provides an additional layer of security to prevent brute-force attack<br/>

### Approach:

-> Not storing the password in plain text format, using a Simple Hashing Algorithm (SHA-256) for safety. <br/>
-> Using a Hash Table to store users and their passwords. <br/>
-> Generating a (secure)password if user doesn't want to enter it manually. <br/>
