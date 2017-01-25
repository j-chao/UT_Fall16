Sequence Alignment Tool using Needleman-Wunsch 
=================
url: https://juchao@bitbucket.org/juchao/stc_project.git  
authors: Justin Chao <justin_chao@utexas.edu>, Chase Meyer
<chasemeyer3@gmail.com>, Bria Lacour <brialacour@utexas.edu>  
license: MIT License      
updated: 12 December, 2016      

About
=====
A sequence alignment tool for comparing protein sequences.

The Needleman-Wunsch algorithm will be used to dynamicaly calculate alignments
using user-set parameters for scoring reference.

Features:  
- Takes in two sequnces as Command Line arguments.    
- Dynamic programming of similarity matrix using Needleman-Wunsch algorithm.    
- Scoring based on user-set parameters.    
- Visual pretty output of final alignments and score.    
- Build using CMake and run on Lonestar5 system.  

A comprehensive report of this project is available in the doc/final_report
directory as final_report.pdf.

Build
=====
Download build files:
    
    $ git clone --recursive https://juchao@bitbucket.org/juchao/stc_project.git

To update:

    $ git pull

To build and run program on Lonestar5:
    
    run make in bin
    run ./Needleman_Wunsch <Sequence1> <Sequence2>

References
==========
Reference code for comparison is made available by Public Domain in src/reference_code.


License
=======
MIT License

Copyright (c) [2016] [Justin Chao, Chase Meyer, Bria Lacour]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

