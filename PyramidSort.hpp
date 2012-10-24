/**
================================================================================
Copyright (c) 2012 Oliveri Dario

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to
    deal in the Software without restriction, including without limitation the
    rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
    sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
================================================================================
*/

/**
    @brief: this is mostly an educational only algorithm since heapsort and
    Tim's sort are far better than this algorithm. I developed this code in 2-3
    hours after teachers at my school introduced sorting algorithms.
    (Originally I tried to improve bubblesort, this code is the final
     version of my work.).

    I really don't know if someone already tried a similiar algorithm.
    I don't intend to steal any IP. I just worked on that alone.
    If someone else already invented that algorithm I'll be happy
    to credit him here :).

    Looking now at the algorithm it is much more similiar to Selection
    Sort. When there are ~50 or more elements to be sorted in the array
    the speed of this sorting algorithm starts to be faster
    than BubbleSort ( for bigger arrays the speed up is between
    2x and 4x). (Only random arrays tested.)

    The only thing that make this algorithm useless (or at least
    I can't imagine some usefull task for this code).
    Is that heapsort is already faster than Bubblesort just
    with only 8 elements.

    Pyramid sort is never faster than heapsort (nether for 2 elements)

    ALGORITHM:
    (MEMORY CELLS THAT ARE MOVED ARE MARKED WITH "*")
    The algorithm start iterating the whole array once,
    during that travel, MAX and MIN are found.

            MAX                   MIN
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |2| | | |9| | | | | | | | | | |1| | | | |3|
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    After that MAX and MIN are placed in correct positions:
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |1| | | |2| | | | | | | | | | |3| | | | |9|
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
     *       *                     *         *

    If you see MAX and MIX are swapped with (2,3). 2 and
    3 are already placed in order. Maybe in future
    this can be helpfull to improve further the
    algorithm.


    When MIN and MAX are found, the have to
    consider only a sub-array (2 cells smaller)

    OLD ARRAY.
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    |1| | | |2| | | | | | | | | | |3| | | | |9|
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    NEW ARRAY,
      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
      |8| | |2| | | | | | | | | | |3| | | | |
      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    Again we search for MAX and MIN:
      MAX    MIN
      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
      |8| | |2| | | | | | | | | | |3| | | |6|
      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    And we reposition MIN and MAX
      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
      |2| | |6| | | | | | | | | | |3| | | |8|
      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
       *     *                             *

    The algorithm proceeds until we have 2 or 3 cell left

    2 cells left

                      +-+-+
                      |5|4|
                      +-+-+

                    are swapped

                      +-+-+
                      |4|5|
                      +-+-+

    3 cells left
                     MAX MIN
                      +-+-+-+
                      |6|4|5|
                      +-+-+-+

                    MAX and MIN are found and then swapped

                      +-+-+-+
                      |4|5|6|
                      +-+-+-+

    After that 1 cell left

                        +-+
                        |5|
                        +-+

    But at this point nothing is done.

    ---------------------------------------------------------------------------
    Little explanation about the name I gave to the algorithm :)

    PYRAMID SORT.

    Because since every time we remove 2 cells if we take every array
    and put it on the top of the other array they will look like a pyramid.


          +-+-+-+-+-+-+-+-+-+-+
          | | | | | | | | | | |
          +-+-+-+-+-+-+-+-+-+-+
        +-+-+-+-+-+-+-+-+-+-+-+-+
        | | | | | | | | | | | | |
        +-+-+-+-+-+-+-+-+-+-+-+-+
      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+
      | | | | | | | | | | | | | | |
      +-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
    | | | | | | | | | | | | | | | | |
    +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


    ---------------------------------------------
    SWAPPING FROM 2 to 4 VALUES. Now there's
    another nice part of the algorithm. You should have noticed
    that the algorithm requires to change position to usually
    3 or 4 values. (well in some case there's only the need to
    swap only 2 values).

    How I solved thi problem?

    Very simple,
    Instead of immediatly swapping the values, I just "take
    note" of what is moved.

    So for example I have 3 values lets say:

    300,400,100

    These values are respectively in position

    3,7,20.

    Now I Know 3 values of wich 1 is MIN and 1 is MAX.

    And I know 3 positions, of wich 1 is posMIN, and 1 is posMAX.

    What I have to do is just to sort those values indipendently.
    (and for sort those values.. I'm using BubbleSort!)

    well,

    3,7,20 are alredy in correct positions.

    100,300,400 are sorted hopefull correctly.

    then

    Array[3] = 100;
    Array[7] = 300;
    Array[20]= 400;

    Now you should have understood that in the next pass
    of the algorithm we will do.

    Array[4] = something  (3+1)
    ...
    Array[19]= something else. (20-1)

    ----------------------------------------------------------
    Complexity:
    This algorithm executes exactly N*(N/2) (rounded down)
    cycles. This is a not adaptive algorithm since running
    time is always fixed and depend on number of elements and
    not on order of elements. The algorithm is executed "in Place"
    and is not Stable. O(1) memory requird.
*/

namespace edu
{

template<typename T>
void PyramidSort(T a[],int L)
{
    const int maxI = (L/2)-1; //for L =(10,11)  half = (4,4)
    for(int i=0; i<=maxI; i++)
    {
        const int maxJ = L-1-i; //for L=(10,11) maxJ = (9,10)... for i=4 maxJ=(5,6)
        int j=i;

        T val[4]= {a[i],a[i],a[i],a[i]};
        int idx[4]= {i,i,i,i};

        val[2] = a[i];
        idx[2] = i;
        for(; j<=maxJ; j++)
        {
            if(a[j]>val[0])
            {
                val[0] = a[j];
                idx[0] = j;
            }
            else if (a[j]<val[1])
            {
                val[1] = a[j];
                idx[1] = j;
            }
        }
        j--;
        val[3] = a[j];
        idx[3] = j;

        /**
        FOLLOWING CODE IS INTERESTING TOO and PART OF THE MAGIC IS DONE HERE.
        */

        //Here i remove duplicated indices by setting them to -1
        int count = 0;
        T val_stack[4];
        int idx_stack[4];

        for(int k=0; k<4; k++)
        {
            for(int m=k+1; m<4; m++)
            {
                //assert(m!=k);

                if(idx[k]==idx[m])
                {
                    if(idx[m]!=-1)
                    {
                        idx[m]=-1;
                    }
                }
            }

            if(idx[k]!=-1)
            {
                val_stack[count]  = val[k];
                idx_stack[count++]= idx[k];
            }
        }

        //count now contains the number of values that are not duplicated.
        for(int k=0; k<count; k++)
        {
            for(int m=k+1; m<count; m++)
            {
                //BUBBLE SORT. Sound hugly? I found that a nice choice.
                //Using bubbleSort for going faster than BubbleSort
                //is something a lot funny!
                if(val_stack[k]>val_stack[m])
                {
                    const T temp = val_stack[k];
                    val_stack[k] = val_stack[m];
                    val_stack[m] = temp;
                }

                //even if you expect indices to be already sorted, don't comment out
                //this code! :). Because I remove duplicated indices by setting them to -1
                //and so additional sorting is required.
                if(idx_stack[k]>idx_stack[m])
                {
                    const T temp = idx_stack[k];
                    idx_stack[k] = idx_stack[m];
                    idx_stack[m] = temp;
                }
            }

            a[idx_stack[k]] = val_stack[k]; //put values in the right place.
        }
    }
}

} // namespace edu.
