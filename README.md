<h1 align="center">
  <img src="https://github.com/senthilpoo10/badges/blob/main/badges/philosophersm.png" width="200"/>
</h1>

<p align="center">
  <b><i>The Dining Philosophers Problem</i></b><br>
  <i>"I never thought philosophy would be so deadly"</i>
</p>

<p align="center">
  <img alt="score" src="https://img.shields.io/badge/score-125%2F100-brightgreen" />
  <img alt="solo" src="https://img.shields.io/badge/solo-yellow" />
  <img alt="time spent" src="https://img.shields.io/badge/time%20spent-60%20hours-blue" />
  <img alt="XP earned" src="https://img.shields.io/badge/XP%20earned-672-orange" />
<p align="center">
  <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/senthilpoo10/philosophers?color=lightblue" />
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/senthilpoo10/philosophers?color=blue" />
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/senthilpoo10/philosophers?color=green" />
</p>

## 📚 About The Project

This project solves the classic Dining Philosophers problem using thread synchronization techniques. It demonstrates multi-threading, mutexes, and proper resource management to prevent deadlocks and starvation.

**Key Concepts Implemented:**
- Thread synchronization with mutexes
- Deadlock prevention
- Time management with microsecond precision
- Resource allocation strategies
- Process monitoring

## 🏁 Getting Started

### 🛠️ Installation & Usage

**Mandatory Part (Threads):**
```bash
cd philo
make
./philo 5 800 200 200 7
```

**Bonus Part (Processes):**
```bash
cd philo_bonus
make
./philo_bonus 4 410 200 200
```

### 📝 Program Arguments
| Argument | Description | Example Value |
|----------|-------------|---------------|
| 1 | Number of philosophers | 5 |
| 2 | Time to die (ms) | 800 |
| 3 | Time to eat (ms) | 200 |
| 4 | Time to sleep (ms) | 200 |
| 5 | [Optional] Meal count | 7 |

## 🧠 Technical Implementation

### Core Architecture
| Component | Implementation Details |
|-----------|------------------------|
| **Thread Management** | Each philosopher is a pthread with dedicated monitoring |
| **Mutex Locks** | Fork states protected by mutexes (1 mutex per fork) |
| **Timing System** | Uses `gettimeofday()` for microsecond precision |
| **Death Check** | Independent monitor thread verifies philosopher states |
| **Logging** | Protected by output mutex to prevent message overlap |

### Performance Metrics
| Scenario | Target | Achieved |
|----------|--------|----------|
| 5 philos (no death) | No starvation | Stable for 100+ meals |
| 200 philos stress test | No data races | Verified with Helgrind |
| 1 philosopher case | Immediate death | Dies at correct time |
| Meal count limit | Stops when satisfied | Accurate count tracking |

## 🧪 Testing Protocol

1. Basic test (should not die):
```bash
./philo 4 410 200 200
```

2. Death test:
```bash
./philo 2 310 200 100
```

3. Meal count test:
```bash
./philo 5 800 200 200 7
```

4. Bonus process test:
```bash
./philo_bonus 3 410 200 200
```

## 📝 Evaluation Criteria

1. **Correctness**: No data races, proper synchronization
2. **Performance**: Meets timing requirements precisely
3. **Error Handling**: Graceful exit on invalid input
4. **Memory**: No leaks (verified with Valgrind)
5. **Bonus**: Working process-based implementation

### 🧑‍💻 Peer Evaluations (3/3)

> **Peer 1**: "Poonkodi has done a great job with the project. I haven't started the project myself so Poonkodi had to explain everything in detail for me in which she did a great job! we followed the evaluation for and checked that everything worked as intended. We went through her code and she explained it to me very well. Thank you and good luck with the rest of the evaluations! ☀️🐝"

> **Peer 2**: "The code was very clean and she explained me everything how she wrote and how it works to a person who has not done this project yet. It also checks out all the tests we performed. Thank you and good luck :)"

> **Peer 3**: "A very interesting evaluation because i have not done the project myself yet. Poonkodi explained everything to me very well and answered all my questions. We tested both the mandatory and bonus part according to the evaluation form and made sure everything works. Good job and good luck with your minishell!"
