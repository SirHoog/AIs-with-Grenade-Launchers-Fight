## ⚠️ Disclaimer

 I have no idea what category of machine learning I'm using. So, please tell me what's wrong with my understanding so that future readers (if any 💀) may understand.

 Machine Learning is so complicated, I don't even know what I did. I guess I mixed multiple different approaches. If you want to help me out, check [this Wikipedia page](https://en.wikipedia.org/wiki/Machine_learning#Approaches) out.

## Usage:

Download, install [Boost](https://www.boost.org/), build, run. That's it.

### Keybinds:

- Spacebar: Play/pause : TPS = DefaultTPS/TPS = 0
- Tab: Display performance
- F11: Toggle fullscreen
- Up: TPS++
- Down: TPS--
- Numpad 0: TPS = DefaultTPS

### Mouse:

- click on AI: View Neural Network
- hold on map: Move camera around
- Scroll on map: Zoom in or out

## Genetic Algorithms in my own words:

 This AI is trained using (what I think is) a Genetic Algorithm. In my own words, it is a method of machine learning to train a Neural Network based off the best Neural Network of each generation.
 Multiple AIs are initialized with random weights in the first generation and are tested to see which one is the best. The next generation of AIs use the previous generation's best AI's Neural Network, but tweaks random weights called mutation.
 In my case, at the end, I want many generations of AIs to fight with their Grenade Launchers.
 If I complete this project, I may post a video on the fight.

## Better explanations:

- https://www.youtube.com/watch?v=I_p-yfdyP1A
- https://www.youtube.com/watch?v=-kpcAa-qKwY
- https://www.youtube.com/watch?v=a8Bo2DHrrow
- https://www.youtube.com/watch?v=SX08NT55YhA

## Inspiration:

- https://www.youtube.com/@PezzzasWork
- https://github.com/johnBuffer

## Learn about Neural Networks:

 Of course, I can just add more videos to this list, but if you want to look for yourself, [here](https://www.youtube.com/hashtag/some2) is a **great** place to look for videos on neural networks (and many other math related videos)

- https://www.youtube.com/watch?v=rEDzUT3ymw4 (Watch this if your lazy, but you learn **a lot** for just 1 minute)
- https://www.youtube.com/watch?v=VMp6pq6_QjI
- https://www.youtube.com/playlist?list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi (I learned most of the fundamental ideas here)
- https://www.youtube.com/watch?v=FBpPjjhJGhk
- https://www.youtube.com/watch?v=w8yWXqWQYmU (This is in python, but IDC, I think you can still learn from it)
- https://www.youtube.com/watch?v=9RN2Wr8xvro **(I learned the most from this)**
- https://reference.wolfram.com/language/guide/MachineLearning.html (I didn't read this, I'm just including it so you don't have to search any further) `<br><br>`
  (`<u>`I personally don't recommend`</u>` learning from `<u>`Brilliant.org`</u>` because it is **extremely** slow and basic at the start, and I think they're just there for your money)

## The FAQ:

...
Ask me questions... Please

## My FAQ:

 This exists because no one asked me any questions (yet), so these are just the things that stumped me when learning about Machine Learning.

- **Q**: Do I need to know a lot of math to learn about Machine Learning?

  - **A**: Depends on what your goal is. Neural Networks are complex, and easier ways of visualizing them is in matrix form. That is why I am using the xtensor library. For other categories of Machine Learning, you can use Gradient Descent, which is some Calculus thing that I don't understand or care about. `<br><br>`
    If you want to learn Linear Algebra or Calculus, you can go to [3Blue1Brown&#39;s Youtube Channel](https://www.youtube.com/@3blue1brown/courses) `<br>`
    Example of some of the math (timestamp at 13:26): https://www.youtube.com/watch?v=aircAruvnKk&list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi&index=3&t=806s
- **Q**: How do you know how many hidden layers to use and the size of them?

  - **A**: [I found this](https://stats.stackexchange.com/questions/181/how-to-choose-the-number-of-hidden-layers-and-nodes-in-a-feedforward-neural-netw) `<br>`
    There can be any amount of hidden layers, but too many can decrease performance, but one is enough.
    The amount of neurons in the hidden layers is typically the average of the amount of neurons in the input and output layer.
- **Q**: What is a bias neuron
- **Q**: How do you know which neurons to connect?

  - **A**: [This video at 1:27](https://www.youtube.com/watch?v=9RN2Wr8xvro&t=87s). `<br>`
    Fully connected layers are most used.
- **Q**: What range of numbers are allowed in a neural network?

  - **A**: [I found this](https://www.quora.com/What-range-of-values-can-a-weight-in-a-neural-network-take-on) `<br>`
    Normalized (range from -1 to 1) weights and activations are better.
- **Q**: Do Genetic Algorithms / Evolutionary Algorithms prove evolution in real life?

  - **A**: Genetic Algorithms **mimic** the process of natural selection. Genetic Algorithms change how the AI functions. In the real world, animals may have *learned* from watching their parents, but they didn't just gain their parents' knowledge genetically. In machine learning, the AI "learns", not evolves. You can say that it "learns" from its mistakes, and each generation, is another trial. If you want to know more, you can visit [this](https://creation.com/genetic-algorithms-do-they-show-that-evolution-works). If you want to discuss this topic to me personally, you can DM me on discord (sirhoog).

## Libraries used:

- https://www.sfml-dev.org/index.php
- https://github.com/nlohmann/json/tree/develop
- https://xtensor.readthedocs.io/en/latest/numpy.html

## I'm pretty new to C++, so here's some cool helpful people:

- https://www.youtube.com/@herbglitch - https://discord.gg/ntXyyEp - https://github.com/HerbGlitch (Do check him out, he helped me with all the C++, mingw, msys2 stuff)
