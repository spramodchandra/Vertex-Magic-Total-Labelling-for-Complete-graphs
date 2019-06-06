# Vertex Magic Total Labelling for Complete graphs
This is an implementation of the algorithm along with some improvements specified in the paper "Algorithms to Realize All Possible Vertex Magic Total Labeling and Super Vertex Magic Total Labeling Of Complete Graphs" by H. K. Krishnappa, N.K. Srinath, S. Manjunath ISSN: 2277-3754.
This implementation was done under the guidance of H. K. Krishnappa as minor project in my undergraduation.

A vertex magic total labelling of a graph 𝐺=(𝑉,𝐸) with |𝑉| vertices (𝑛) and |𝐸| edges (𝑚) is defined as one-to-one map 𝑓:𝑉∪𝐸→{1,2,3….,|𝑉|+|𝐸|} taking the vertices and edges on to the integers 1,2,3…,𝑛+𝑚 with the property that the sum of the label on a vertex and the labels on its incident edges is a constant. This constant is called a magic constant. Finding total vertex-magic labelling has many significant importance such as in cryptography applications, network security, etc.

In mathematical terms.
A vertex magic total labeling of a graph 𝐺=(𝑉,𝐸) is a bijection 𝑓 from 𝑉∪𝐸 to the set of integers 1,2,3,4,5··.,𝑛 + 𝑚 such that for every vertex 𝑣, <br/>
𝑓(𝑣)+Σ<sub>𝑣𝑤∈𝐸</sub>𝑓(𝑣𝑤)=𝑘, 𝑤ℎ𝑒𝑟𝑒 𝑘 𝑖𝑠 𝑎 𝑐𝑜𝑛𝑠𝑡𝑎𝑛𝑡.
### Flow Chart
The flow chart is splitted into two parts. This gives the basic idea about the implemention of the algorithm mentioned in the paper.<br/>
<img src="https://raw.githubusercontent.com/spramodchandra/Vertex-Magic-Total-Labelling-for-Complete-graphs/master/images/Flowchart_1.png"/>
<br/>

<img src="https://raw.githubusercontent.com/spramodchandra/Vertex-Magic-Total-Labelling-for-Complete-graphs/master/images/Flowchart_2.png"/>

### Results
<b>Vertices = 5 and Magic constant = 37</b><br/><br/>
<img src="https://raw.githubusercontent.com/spramodchandra/Vertex-Magic-Total-Labelling-for-Complete-graphs/master/images/n5k37_1.jpg"/>

<img src="https://raw.githubusercontent.com/spramodchandra/Vertex-Magic-Total-Labelling-for-Complete-graphs/master/images/n5k37_2.jpg"/>
<br/>

<b>Vertices = 7 and Magic constant = 93</b><br/><br/>
<img src="https://raw.githubusercontent.com/spramodchandra/Vertex-Magic-Total-Labelling-for-Complete-graphs/master/images/n7k93.png"/>
<br/>
<br/>
<b>Vertices = 7 and Magic constant = 100</b><br/><br/>
<img src="https://raw.githubusercontent.com/spramodchandra/Vertex-Magic-Total-Labelling-for-Complete-graphs/master/images/n7k100_1.jpg"/>
<img src="https://raw.githubusercontent.com/spramodchandra/Vertex-Magic-Total-Labelling-for-Complete-graphs/master/images/n7k100_2.jpg"/>
<br/>
<br/>

### Computational Analysis
As you can see in below graph, the computational time increases exponentially with increase in number of vertices, this can be used in network security for encryption.
<img src="https://raw.githubusercontent.com/spramodchandra/Vertex-Magic-Total-Labelling-for-Complete-graphs/master/images/analysis.png"/>
