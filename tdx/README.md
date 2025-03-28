# Intel TDX: Formal Model and Property Verification

This directory contains a formal model of **Intel TDX** (Trust Domain Extensions), a VM-based **Trusted Execution Environment (TEE)** that ensures **memory confidentiality and integrity** for virtual machines by isolating guest VMs from the hypervisor using encryption, access control, and hardware support.

## 🔒 What is Intel TDX?

**Intel TDX** provides hardware-isolated **Trust Domains (TDs)** within a system, protecting them from a potentially malicious hypervisor. TDX leverages **Multi-Key Total Memory Encryption (MKTME)** and secure VM lifecycle management to ensure strong **confidentiality** and **integrity** guarantees.

### Key Features of Intel TDX:

- **SEAM mode**: A secure VMX root operation mode that enables TDX-specific instructions and modules.
- **HKID-tagged encryption**: Memory is encrypted using hardware keys unique to each TD.
- **TD Owner Bit**: Ensures access to TD memory only from authorized SEAM contexts.
- **Secure VM Lifecycle**: Controlled creation, configuration, blocking, and teardown of TDs.

---

## 📦 What We Model

We formally model the **TD lifecycle**, **cache mechanisms**, **TDX-specific data structures**, and **ABI behaviors** using [Rosette](https://emina.github.io/rosette/) to check **confidentiality** and **integrity** through symbolic execution.

### ✅ Data Structures Modeled

| Name   | Description |
|--------|-------------|
| EPT    | Extended Page Table: GPA to HPA mapping, shared/private state |
| KET    | Key Encryption Table: Maps HKIDs to ephemeral encryption keys |
| KOT    | KeyID Ownership Table: Tracks HKID lifecycle |
| TDR    | Trust Domain Root: Root metadata for a TD |
| PAMT   | Physical Address Metadata Table |
| TDCS   | Trust Domain Control Structure |
| Cache  | 4-way associative cache with HKID or TD-owner-bit support |

### ✅ ABIs Modeled

| ABI Name               | Description |
|------------------------|-------------|
| TDH_MNG_CREATE         | TD creation with HKID assignment |
| TDH_MNG_KEY_CONFIG     | Key configuration for the TD |
| TDH_MNG_VPFLUSH        | Flushes VCPU state and cache for TD |
| TDH_MNG_KEY_FREEID     | Reclaims and tears down TD by freeing HKID |

---

## 🧪 Test Cases and Execution

All properties and ABIs are tested through Rosette’s symbolic engine. The symbolic evaluation uses both **HKID-tagged cache** and **TD-owner-bit cache** implementations.

To run tests:
```bash
racket test.rkt
```

---

## 🔐 Confidentiality & Integrity Properties

### Confidentiality Properties

| ID   | Description |
|------|-------------|
| cP1  | GPA to HPA mappings in EPT are private |
| cP2  | HKID encryption keys in KET must not be leaked |
| cP3  | HKID assignment state remains confidential |
| cP4  | TDR lifecycle state is not observable |
| cP5  | EPT page states must not leak sensitive mappings |
| cP6–cP10 | Cover state confidentiality and isolation of key setup |
| cP11–cP15 | Cache-level confidentiality through HKID/owner-bit tagging |

### Integrity Properties

| ID   | Description |
|------|-------------|
| iP1  | EPT mappings cannot be "blocked" incorrectly |
| iP2  | TDR lifecycle does not regress to INIT or FATAL |
| iP3  | HKID states follow valid transitions only |
| iP4–iP9 | Cache integrity properties (validity, uniqueness, owner-bit checks) |

---

## 🖥️ Output Description

Results indicate pass/fail status of each property. For example:

```
[cP13] Cache isolation with HKID
✅ PASS: Unauthorized HKID access blocked.

[iP5] Unique tags within cache set
❌ FAIL: Duplicate tags found in same set.
Counterexample: set=3, way1=2, way2=0
```

---

## 🐳 Docker Setup

To build and run the Docker container:

### 1. Build Docker Image
```bash
docker build -t tdx-model:1.0.0 -f util/docker/Dockerfile .
```

### 2. Run Container:
```bash
docker run --volume=/path_to_model:/formal -it tdx-model:1.0.0
```

Inside the container:
```bash
cd /formal/tdx/src
racket test.rkt
```

---

## 📎 Final Notes

- This work models the **TD lifecycle**, **secure memory access**, and **cache protections** under Intel TDX.
- The **platform firmware (e.g., SEAM loader)** is assumed trusted and out of scope.
- Emphasis is on **verifying confidentiality and integrity** in the presence of a compromised hypervisor.