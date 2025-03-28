# TEE Verification Framework

This repository provides **formal modeling and security property verification** of **VM-based Trusted Execution Environments (TEEs)** using [Rosette](https://emina.github.io/rosette/). We build design abstractions for TEEs and use symbolic execution to verify **confidentiality** and **integrity** guarantees of VM-based TEEs.

### ✨ Key Features

- Design- and property- based abstraction of **Intel TDX** and **AMD SEV** from Specification
- Tests to ensure the correctness of model through abstract refinement
- Generating Confidentiality and Integrity properties from Specification
- Symbolic execution using Rosette to verify properties.
- Unified testbench with traceable property failures

---

## 🧠 What are TEEs?

**Trusted Execution Environments (TEEs)** provide isolated environments for executing sensitive code and protecting data, even in the presence of advanced attacker.

### VM-based TEEs

VM-based TEEs integrate hardware-based protections into virtual machines. Unlike enclave-based TEEs (e.g., Intel SGX), they operate at the VM level and protect:

- Memory encryption and integrity
- Guest state and register isolation
- Confidentiality of guest secrets even from hypervisors

---

## 📌 Why security guarantees matter

Modern cloud platforms often colocate VMs from different tenants on shared infrastructure. Without proper isolation, a compromised hypervisor could:

- Access or modify guest memory
- Reuse stale secrets
- Intercept registers or migration data

Hence, **formal verification** ensures these attacks are provably prevented under the TEE design.

---

## 🧩 What’s modeled in this repo?

We build formal models (in Rosette) of:

- **Lifecycle states** (launch, run, send, receive, terminate)
- **Guest Context**, ASID and encryption key tables
- **Page validation and RMP logic** (SEV-SNP)
- **GHCB**, **VMPL**, **Page versioning**, and more

We verify properties such as:

- No ASID reuse without deallocation
- Memory encryption bound to ASID
- Register encryption on VMEXIT
- Page validation before use
- No unauthorized memory access

---

## 🛠 Repository Structure

```
verification/src/
├── sev/        # AMD SEV + SEV-ES + SEV-SNP model and properties
│   ├── abi.rkt
│   ├── tables.rkt
│   ├── confidentility.rkt
│   ├── common.rkt
│   └── test.rkt
│
├── tdx/        # Intel TDX model and properties (in progress)
│   ├── tables.rkt
│   ├── confidentility.rkt
│   ├── memory.rkt
│   ├── common.rkt
│   └── ...
```

---

## 📚 References

- **AMD SEV-SNP**: [AMD SEV-SNP Architecture Guide (PDF)](https://www.amd.com/system/files/TechDocs/56860.pdf)
- **Intel TDX**: [Intel TDX Key Concepts](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-trust-domain-extensions.html)

---

## 🐳 Docker Environment (Recommended)

This project is packaged in a Docker container for reproducible formal analysis.

### 🔧 Build the Docker image

From the `util/docker/` directory:

```bash
docker build -t rosset:1.0.0 .
```

### 🚀 Run inside a container

Map your local model folder into `/formal` and start an interactive session:

```bash
docker run --volume=/path_to_model:/formal -it rosset:1.0.0
```

Once inside, run:

```bash
racket tables.rkt
```

or run any of the symbolic property checkers:

```bash
racket confidentility.rkt
racket common.rkt
```

---

## 🤝 Contribution

Feel free to fork, add more properties, or expand the abstraction to other TEEs.

---

## 📄 License

MIT License.
