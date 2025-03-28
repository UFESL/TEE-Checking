# AMD SEV: Formal Model and Property Verification

This directory contains a formal model of **AMD SEV** (Secure Encrypted Virtualization), a VM-based **Trusted Execution Environment (TEE)** that provides **memory confidentiality and integrity** for guest virtual machines by encrypting guest memory and protecting CPU state transitions.

## 🔒 What is AMD SEV?

**AMD SEV** protects VMs from a potentially malicious hypervisor by encrypting memory with keys unique to each VM. SEV is built into AMD CPUs and secures data in-use, especially during cloud-based execution.

### Extensions to SEV:

- **SEV-ES**: Adds register state encryption on **VMEXIT**, preventing the hypervisor from snooping on CPU state.
- **SEV-SNP**: Adds advanced memory integrity, including Reverse Map Table (RMP), **Secure Nested Paging**, and **Page Validation (PVALIDATE)**.
- **SEV-TIO**: I/O protection layer (not modeled here as it doesn't affect guest lifecycle or memory state directly).

We **focus on SEV, SEV-ES, and SEV-SNP**, excluding SEV-TIO.

---

## 📦 What We Model

We formally model **guest lifecycle**, **security metadata**, and **secure API (ABI)** behavior. The model includes symbolic execution-based checking of **confidentiality** and **integrity** properties using [Rosette](https://emina.github.io/rosette/), a symbolic execution framework for Racket.

### ✅ Data Structures Modeled

| Name            | Description                                      | Modeled |
|-----------------|--------------------------------------------------|---------|
| GCTX            | Guest context: stores state, encryption keys     | ✅      |
| GSTATE          | Guest state machine                              | ✅      |
| ASIDT           | ASID table: maps ASIDs to guests                 | ✅      |
| MEKT            | Maps ASIDs to VEKs (encryption keys)             | ✅      |
| PEB             | Page encryption status                           | ✅      |
| RMP             | Reverse Map Table: physical addr to guest        | ✅      |
| GHCB            | Guest-Hypervisor Communication Block             | ✅      |
| VMCB            | Virtual Machine Control Block (registers)        | ✅      |
| VMPL            | Guest privilege levels (VMPL0–3)                 | ✅      |
| PageVersion     | Tracks page freshness (rollback protection)      | ✅      |
| PVALIDATE-Flag  | Indicates if a page was validated                | ✅      |

### ✅ ABIs Modeled

| Name               | Description                                      | Modeled |
|--------------------|--------------------------------------------------|---------|
| LAUNCH_START       | Begin guest initialization                       | ✅      |
| LAUNCH_UPDATE_DATA | Update encrypted memory                          | ✅      |
| LAUNCH_MEASURE     | Attestation placeholder                          | ✅      |
| LAUNCH_SECRET      | Secret injection                                 | ✅      |
| LAUNCH_FINISH      | Transition to RUNNING                            | ✅      |
| ACTIVATE / DEACTIVATE | Key assignment and teardown                  | ✅      |
| SEND / RECEIVE     | Migration-related operations                     | ✅      |
| VMEXIT / VMRUN     | Guest transitions triggering register save/load  | ✅      |
| PVALIDATE          | Page validation for memory integrity             | ✅      |

To verify the syntax of the model:
```bash
racket tables.rkt
racket abi.rkt
```

---

## 🧪 Test Cases and Abstract Refinement

We use `test.rkt` to perform unit tests and validate data structures and transition correctness through abstract refinement.

To run tests:
```bash
racket test.rkt
```

---

## 🔐 Confidentiality & Integrity Properties

### Confidentiality Properties 

| ID  | Property Description                                                 |
|-----|----------------------------------------------------------------------|
| CP1 | Only the assigned guest may access a page (RMP check)               |
| CP2 | No ASID reuse without deallocation                                  |
| CP3 | VEK key must not be reused across guests                            |
| CP4 | Page access requires prior validation (via PVALIDATE)               |
| CP5 | Memory encryption must not allow cross-ASID decryption              |
| CP6 | Register state must be encrypted on VMEXIT                          |
| CP7 | Guest cannot access pages assigned to others                        |

### Integrity Properties

| ID  | Property Description                                                 |
|-----|----------------------------------------------------------------------|
| IP1 | VMPL access control: VMPLi must not access pages of VMPLj > i       |
| IP2 | Pages must not be reassigned without deallocation                   |
| IP3 | Pages must be validated before execution                            |
| IP4 | Transition to RUNNING must only occur after proper LAUNCH sequence |
| IP5 | Registers must be restored only for the correct guest               |

To run the property checks:
```bash
racket confidentility.rkt   ;; for CP1–CP7
racket integrity.rkt        ;; for IP1–IP5 
```

### 🖥️ Output Description

Upon running, you’ll see property-specific printouts like:

```
[CP 1] Only the assigned guest may access the page (via RMP check)
✅ PASS: No unauthorized guest can access the page.

[CP 4] Page access requires validation
❌ FAIL: Unvalidated page was accessible!
Counterexample: guest-id = 1, page-addr = 0x1000
```

This indicates whether symbolic evaluation found a **counterexample**, i.e., a violation of the property.

---

## 🐳 Docker Setup and How to Run

To run this in a containerized setup:

### 1. Build Docker Image (from `util/docker/Dockerfile`)
```bash
docker build -t rosset:1.0.0 -f util/docker/Dockerfile .
```

### 2. Run Container with Model Mounted:
```bash
docker run --volume=/path_to_model:/formal -it rosset:1.0.0
```

Inside the container:
```bash
cd /formal/sev/src
racket test.rkt
racket confidentility.rkt
```

---

## 📎 Final Notes

- This work assumes the platform firmware (e.g., AMD-SP) behaves correctly and is out of scope.
- The focus is exclusively on **guest-level behavior modeling**, especially lifecycle and state handling.
