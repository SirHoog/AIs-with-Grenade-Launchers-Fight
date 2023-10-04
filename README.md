## ⚠️ Disclaimer
 I may be wrong on what category of machine learning I'm using. So, please tell me what's wrong with my understanding so that future readers (if any 💀) may understand.

 Machine learning is complicated, and I'm not sure if I understood everything completely. If you want to learn more about machine learning, check [this Wikipedia page](https://en.wikipedia.org/wiki/Machine_learning#Approaches) out.

## Usage:
Download, install [Boost](https://www.boost.org/) and [SFML](https://www.sfml-dev.org/index.php), compile, and run. That's it.

### Keyboard:
- Spacebar: Play/pause : TPS = DefaultTPS/TPS = 0
- Tab: Display performance
- F11: Toggle fullscreen
- Up Arrow: TPS++
- Down Arrow: TPS--
- Zero: TPS = DefaultTPS

### Mouse:
- Click on AI: View Neural Network
- Drag on map: Move camera around
- Scroll on map: Zoom in or out

## Genetic Algorithms in my own words:
 I won't explain what neural networks are here, because there are plenty of videos on them, but it's basically the (artificial) brain of an AI. If you're here to learn about them, here's a great place to start: https://www.youtube.com/playlist?list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi
 This AI is trained using (what I think is) a Genetic Algorithm. In my own words, it is a way to train a neural network based off of its fitness, which is just how good it has done.
 In the first generation, multiple AIs are initialized with random weights and are tested to see which . The next generation of AIs use the previous generation's best AI's neural network, but tweaks random weights in a process called mutation.
 If this sounds similar to the theory of evolution, that's because it is directly inspired from the theory of evolution. It works in code, but not in reality.

 If I complete this project, I may post a video of the AIs fighting.
### Better explanations:
- https://www.youtube.com/watch?v=I_p-yfdyP1A
- https://www.youtube.com/watch?v=-kpcAa-qKwY
- https://www.youtube.com/watch?v=a8Bo2DHrrow
- https://www.youtube.com/watch?v=SX08NT55YhA

## The FAQ:
...
Ask me questions

## My FAQ:
 This exists because no one asked me any questions (yet), so these are just the things that stumped me when learning about machine learning.

- **Q**: Do I need to know a lot of math to learn about machine learning?
- **A**: It depends on what your goal is. Neural networks are complex, and coding them may require you to understand of linear algebra and calculus. That's why I am using the NumCpp library, which is the Python library, NumPy, but in C++. For other categories of machine learning, like Deep Learning, you use Gradient Descent, which is some calculus thing that I don't understand or care about. <br><br>
  If you want to learn linear algebra or calculus, you can go to [3Blue1Brown's Youtube channel](https://www.youtube.com/@3blue1brown/courses) <br>
  Example of some of the math (timestamp at 13:26): https://www.youtube.com/watch?v=aircAruvnKk&list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi&index=3&t=806s
- **Q**: How do you know how many hidden layers to use and the size of them?
- **A**: [I found this](https://stats.stackexchange.com/questions/181/how-to-choose-the-number-of-hidden-layers-and-nodes-in-a-feedforward-neural-netw) <br>
  It doesn't matter how many hidden layers there are, but too many can slow performance.
  The size of a hidden layer also varies, but they can also slow performance.
  In short, hidden layers allow for more complicated task, but if too large, can be costly on performance.
- **Q**: What is a bias neuron?
- **A**: It's a neuron that shifts the output of the layer it's in. It has no in-going weights, but it does have out-going weights. Since it has no in-going weights, its activation is always constant, and only its weights are changed during training. Since there is no layer after the output layer, the output layer has no bias neuron.
- **Q**: How do you know which neurons to connect?
- **A**: [Timestamp: 1:27](https://www.youtube.com/watch?v=9RN2Wr8xvro&t=87s). <br>
  You don't have to fully connect layers, but they are the easiest and most commonly used.
- **Q**: What is the range of a neuron's activation and weights?
- **A**: [I found this](https://www.quora.com/What-range-of-values-can-a-weight-in-a-neural-network-take-on) <br>
  Normalized (range from -1 to 1) weights and activations are better so , but some people use ranges from 0 to 1 for

## Libraries used:
- https://www.sfml-dev.org/index.php
- https://github.com/nlohmann/json/tree/develop
- https://xtensor.readthedocs.io/en/latest/numpy.html

## Inspiration:
- https://www.youtube.com/@PezzzasWork
- https://github.com/johnBuffer

## I'm pretty new to C++, so here's some cool helpful people:
- https://www.youtube.com/@herbglitch - https://discord.gg/ntXyyEp - https://github.com/HerbGlitch (Do check him out, he helped me with all the C++, mingw, msys2 stuff)