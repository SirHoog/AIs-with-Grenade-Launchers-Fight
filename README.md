## ⚠️ Disclaimer
 I have no idea what category of machine learning I'm using. So, please tell me what's wrong with my understanding so that future readers (if any 💀) may understand.

 Machine Learning is so complicated, I don't even know what I did. I guess I mixed multiple different approaches. If you want to help me out, check [this wikipedia page](https://en.wikipedia.org/wiki/Machine_learning#Approaches) out.

## Usage:

Download, build, run.

### Keybinds:
- Spacebar: Play/pause : TPS = DefaultTPS/TPS = 0
- Tab: Display performance
- F11: Fullscreen
- Up: TPS++
- Down: TPS--
- Numpad 0: TPS = DefaultTPS
### Mouse:
- MB1 on AI: View Neural Network
- MB1 on map: Move camera around
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
- https://www.youtube.com/watch?v=rEDzUT3ymw4 (Watch this if your lazy. You do learn the basics)
- https://www.youtube.com/watch?v=VMp6pq6_QjI
- https://www.youtube.com/playlist?list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi (I learned most of the fundamental ideas here)
- https://www.youtube.com/watch?v=w8yWXqWQYmU (This is in python, but IDC, I think you can still learn from it)
- https://www.youtube.com/watch?v=9RN2Wr8xvro **(I learned the most from this)**
- https://reference.wolfram.com/language/guide/MachineLearning.html (I didn't read this, I'm just including it so you don't have to search any further) <br><br>
 **(<u>I personally don't recommend</u> learning from <u>Brilliant.org</u> because it is *extremely* slow and basic at the start)**

## The FAQ:
...
Ask me questions... Please

## My FAQ:
 This exists because no one asked me any questions (yet), so these are just the things that stumped me when learning about Machine Learning.
 - **Q**: Do I need to know a lot of math to learn about Machine Learning?
    - **A**: Possibly. Neural Networks are complex, and easier ways of visualizing them is with Linear Algebra. That is why I am using the xtensor library. For other applications different from my own, use Gradient Descent, which is some Calculus thing that I don't care about. <br><br>
    If you want to learn Linear Algebra or Calculus, you can go to [3Blue1Brown's Youtube Channel](https://www.youtube.com/@3blue1brown)
 
 - **Q**: How do you know how many hidden layers to use and the size of them?
    - **A**: [I found this](https://stats.stackexchange.com/questions/181/how-to-choose-the-number-of-hidden-layers-and-nodes-in-a-feedforward-neural-netw) <br>
    There can be any amount of hidden layers, but too much can decrease performance, and usually one is enough.
    The size of the layer is typically the average between the input and output layer's size.

- **Q**: How do you know which neurons to connect?
    - **A**: [This video at 1:27](https://www.youtube.com/watch?v=9RN2Wr8xvro&t=87s). <br>
    Fully connected layers is most used.

- **Q**: What range of numbers are allowed in a neural network?
    - **A**: [I found this](https://www.quora.com/What-range-of-values-can-a-weight-in-a-neural-network-take-on) <br>
    Normalized (range from -1 to 1) weights and activations are better.

- **Q**: Do Genetic Algorithms / Machine Learning prove that evolution is real?
    - **A**: Genetic Algorithms mimics the process of natural selection according to [Wikipedia](https://en.wikipedia.org/wiki/Machine_learning#Genetic_algorithms). Genetic Algorithms change how the AI functions. It does not transform like evolutionists claim. Many people have programmed evolution in a way, and their AIs did "transform", but it transformed based off of the "experience" of other AIs. In the real world, animals may have *learned* by their parents from experience, but they didn't just gain their parent's knowledge telepathically or genetically. If you want to know more, you can visit [this](https://creation.com/genetic-algorithms-do-they-show-that-evolution-works). If you want to talk to me about this, you can DM me on discord (sirhoog).

## Libraries used:
- https://www.sfml-dev.org/index.php
- https://github.com/nlohmann/json/tree/develop
- https://xtensor.readthedocs.io/en/latest/numpy.html

## I'm pretty new to C++, so here's some cool helpful people:
- https://www.youtube.com/@herbglitch - https://discord.gg/ntXyyEp - https://github.com/HerbGlitch