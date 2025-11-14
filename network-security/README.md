# Network Security

This document provides a concise overview of **Network Security** concepts, covering both fundamental and advanced security protocols, authentication mechanisms, and key management systems.

---

## 1. Public Key Cryptography
Public key cryptography uses pairs of keys, where the public key is openly shared and the private key remains confidential. This system enables secure data transmission, digital signatures, and authentication without requiring both parties to share a secret key in advance.

---

## 2. Entity Authentication
Entity authentication refers to the methods used to verify the identity of a communicating party. The entity that needs to prove its identity is known as the claimant, while the verifier is responsible for confirming that identity.

---

## 3. Data Origin vs. Entity Authentication
Data origin authentication ensures the authenticity of the source of received data. Entity authentication, on the other hand, focuses on confirming the identity of the sender. Although related, one concerns the validity of the data while the other concerns the legitimacy of the communicating party.

---

## 4. Verification Categories
Authentication systems can be based on knowledge such as passwords or PINs, on possession such as tokens or smart cards, or on biometric characteristics such as fingerprints or facial recognition. These categories represent different approaches to establishing trust during communication.

---

## 5. Password Systems

### Fixed Password
A fixed password is used repeatedly and remains the same over multiple authentication attempts. Although simple, such systems are vulnerable to brute-force and dictionary attacks. Security can be improved with techniques like hashing, salting, and multi-factor authentication.

---

## 6. Cryptographic Hash Functions
Cryptographic hash functions ensure data integrity by producing a fixed-size output from input data in a one-way manner. The same input always produces the same output, while reversing the process is computationally infeasible.

### SHA-512
SHA-512 is a hash function that produces a 512-bit output. It offers strong security guarantees and is widely used in modern cryptographic systems.

---

## 7. Zero-Knowledge Proofs (ZKP)
Zero-knowledge proofs allow one party to prove that they possess certain knowledge without revealing the information itself. They are commonly used in privacy-preserving authentication systems.

### Protocols

**Fiat–Shamir Protocol**  
<img width="559" height="404" alt="Fiat-Shamir Protocol" src="https://github.com/user-attachments/assets/d5afd071-8eaa-42c3-9cb1-fba60da2e942" />

**Feige–Fiat–Shamir Protocol**  
<img width="595" height="417" alt="Feige-Fiat-Shamir Protocol" src="https://github.com/user-attachments/assets/e64209c5-0ad2-4f6f-a241-66b2e18b2ee6" />

**Guillou–Quisquater Protocol**  
<img width="541" height="412" alt="Guillou-Quisquater Protocol" src="https://github.com/user-attachments/assets/f1b592bb-65b6-474e-a83e-4da46756bfc9" />

---

## 8. Biometrics
Biometrics rely on physical characteristics such as fingerprint patterns, iris structure, or facial features to authenticate users. While they offer strong security, they raise concerns about privacy and the protection of sensitive biometric data.

---

## 9. Key Management
Key management addresses the processes of generating, distributing, updating, and revoking cryptographic keys. Systems such as the Key Distribution Center (KDC) provide centralized mechanisms for securely distributing keys. Kerberos is a well-known authentication protocol built on top of KDC architecture.

### KDC-Based Protocols

**Needham–Schroeder Protocol**  
<img width="569" height="548" alt="image" src="https://github.com/user-attachments/assets/e026501d-89c1-4c0f-942b-d5ca6a145f55" />

**Otway–Rees Protocol**  
<img width="564" height="606" alt="image" src="https://github.com/user-attachments/assets/76f38083-6f2f-48f9-a4eb-29b16dc3f523" />

**Kerberos Protocol**  
<img width="578" height="754" alt="image" src="https://github.com/user-attachments/assets/9c0d92eb-3585-41aa-bd8a-f1171bbabde6" />

---

## 10. Diffie–Hellman (DH) Key Exchange
Diffie–Hellman allows two parties to create a shared secret key without transmitting the key itself. The security of the method relies on the difficulty of solving discrete logarithm problems.

<img width="516" height="293" alt="image" src="https://github.com/user-attachments/assets/3101c2ee-bef8-43b5-9312-f207ac79a04d" />

---

## 11. ElGamal Algorithm
The ElGamal algorithm is an asymmetric encryption scheme based on the principles of Diffie–Hellman. It supports secure encryption and decryption and is widely used in systems that require strong confidentiality.

---

## References
Behrouz Forouzan, *Introduction to Cryptography and Network Security*  
IETF RFC 2631 – Diffie-Hellman Key Agreement Method  
Wikipedia – Network Security

---
