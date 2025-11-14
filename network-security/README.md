# Network Security

This document provides a concise overview of **Network Security** concepts, covering both fundamental and advanced security protocols, authentication mechanisms, and key management systems.

---

## 1. Public Key Cryptography
A cryptographic system that uses pairs of keys: **public keys** (shared openly) and **private keys** (kept secret).  
It enables secure data transmission, digital signatures, and authentication.

---

## 2. Entity Authentication
Methods used to verify the identity of a communicating party.

- **Claimant:** The entity that needs to prove its identity.  
- **Verifier:** The entity that checks and confirms the claimant’s identity.

---

## 3. Data Origin vs. Entity Authentication
- **Data Origin Authentication:** Ensures the authenticity of the *source* of the data.  
- **Entity Authentication:** Ensures the *identity* of the sender.  
- **Difference:** Data integrity vs. user identity verification.

---

## 4. Verification Categories
- **Knowledge-based authentication** (password, PIN)  
- **Possession-based authentication** (smart card, token)  
- **Biometric-based authentication** (fingerprint, facial recognition)

---

## 5. Password Systems

###  Fixed Password
- Static passwords used repeatedly.  
- **Weaknesses:** Vulnerable to brute-force and dictionary attacks.  
- **Enhancements:** Use of *salting*, *hashing*, and *multi-factor authentication (MFA)*.

---

## 6. Cryptographic Hash Functions
- Ensure **data integrity**.  
- Are **one-way** functions — impossible to reverse.  
- The same input always produces the same hash output.

###  SHA-512
- Produces a 512-bit output.  
- Provides high security.  
- Widely used in modern encryption protocols.

---

## 7. Zero-Knowledge Proofs (ZKP)
A concept of proving knowledge **without revealing the information itself**.  
> “I can prove that I know something without showing what it is.”

Used in privacy-preserving and authentication systems.

### Protocols:
- **Fiat–Shamir Protocol**  
  <img width="559" height="404" alt="Fiat-Shamir Protocol" src="https://github.com/user-attachments/assets/d5afd071-8eaa-42c3-9cb1-fba60da2e942" />

- **Feige–Fiat–Shamir Protocol**  
  <img width="595" height="417" alt="Feige-Fiat-Shamir Protocol" src="https://github.com/user-attachments/assets/e64209c5-0ad2-4f6f-a241-66b2e18b2ee6" />

- **Guillou–Quisquater Protocol**  
  <img width="541" height="412" alt="Guillou-Quisquater Protocol" src="https://github.com/user-attachments/assets/f1b592bb-65b6-474e-a83e-4da46756bfc9" />

---

## 8. Biometrics
- Authentication through physical characteristics such as fingerprints, iris scans, or facial recognition.  
- Provides higher security but raises **privacy** and **data protection** concerns.

---

## 9. Key Management
Covers the **generation**, **distribution**, **renewal**, and **revocation** of cryptographic keys.

- **KDC (Key Distribution Center):** Centralized system for key distribution.  
- **Kerberos:** An authentication protocol based on KDC architecture.

### KDC-Based Protocols
- **Needham–Schroeder Protocol**  
<img width="569" height="548" alt="image" src="https://github.com/user-attachments/assets/e026501d-89c1-4c0f-942b-d5ca6a145f55" />


- **Otway–Rees Protocol**  
<img width="564" height="606" alt="image" src="https://github.com/user-attachments/assets/76f38083-6f2f-48f9-a4eb-29b16dc3f523" />


- **Kerberos Protocol**
<img width="578" height="754" alt="image" src="https://github.com/user-attachments/assets/9c0d92eb-3585-41aa-bd8a-f1171bbabde6" />


---

## 10. Diffie–Hellman (DH) Key Exchange
- Allows two parties to generate a shared secret key.  
- Enables secure communication *without transmitting the key itself.*  
- Based on modular exponential mathematics.

<img width="516" height="293" alt="image" src="https://github.com/user-attachments/assets/3101c2ee-bef8-43b5-9312-f207ac79a04d" />


---

## 11. ElGamal Algorithm
- Asymmetric encryption algorithm.  
- Based on the Diffie–Hellman key exchange principle.  
- Ensures secure message encryption and decryption.

---

## References
- Behrouz Forouzan, *Introduction to Cryptography and Network Security*  
- [IETF RFC 2631 – Diffie-Hellman Key Agreement Method](https://www.ietf.org/rfc/rfc2631.txt)  
- [Wikipedia – Network Security](http://en.wikipedia.org)

---




