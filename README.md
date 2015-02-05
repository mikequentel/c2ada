c2ada
=====

## Introduction

__c2ada__ is a translator from C to Ada95. It is meant to be an aid in porting C programs to Ada.

On 2015-02-03, Mike Quentel imported the Sourceforge project C2Ada to GitHub.com as __c2ada__ with the intent of debugging and enhancing the software. 

## Background and Origin of __c2ada__
* Website at http://c2ada.sourceforge.net/c2ada.html

* The code for c2ada (originally Pascal-cased as _"C2Ada"_) at Sourceforge is licensed as "Public Domain"
  * The version here at GitHub is re-licensed as MIT type of licence.

* Mark Schimmel created _cbind_. Randy Hudson and Mitch Gart created C2Ada based on cbind. 

* In 2007, Nasser Abbasi ported C2Ada to Linux. Jeffrey Creem created the Sourceforge project. (Many thanks to Nasser and Jeffrey, and everyone else that contributed to c2ada on Sourceforge).

* Originally hosted at SourceForge, with contributions from jcreem, krischik, nmabbasi, simonjwright

* From the original C2Ada notes at SourceForge:

   * "port to linux by Nasser Abbasi"

   * "see http://12000.org/my_notes/ada/index.htm"

## Getting Started
* Prerequisites
   * Python 2.x
   * [gperf](ftp://ftp.gnu.org/gnu/gperf/)
   * Berkley Yacc (byacc)
1. Optionally fork, then clone c2ada
1. `cd` to the root directory of c2ada and modify `PYTHON_VER` in `setup` as needed.
1. Run `make`
* Expected result: creation of `c2ada` executable.
