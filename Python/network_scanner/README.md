# 🔍 Python Port and Network Scanner

This project includes two Python scripts for scanning ports and discovering active devices on a subnet. It uses the `socket` module (and optionally `scapy`) to test connectivity and identify open ports.

---

## 📁 Features

### 1. **Basic Port Scanner**
Scans a specific host (e.g., `10.10.1.84`) for open **TCP ports** from 1 to 1024.

```python
port_scan("10.10.1.84")
