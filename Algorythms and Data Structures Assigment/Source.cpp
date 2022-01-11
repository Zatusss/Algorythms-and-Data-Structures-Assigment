#include "AStarImplementation.h"
#include "Grid.h"


//[ASSIGMENT TASKS MENAGMENT]
//Not Done Task
/*


-keep sliding in the chosen direction until they
hit the wall surrounding the area, or one of the
rocks

*/
//Started need more work
/*

Task 3 
    (20 marks). 
        Add a simple parser which can read a map like the one in the example
        from an input file. 
        
        It needs to determine the width and height and the locations of the start
        and finish square as well as the rocks.  
        
        The structure of the files will look like in the example,
        i.e., use ‘.’/’0’/’S’/’F’ for empty (ice) squares, rocks, the start and the finish.

        Your parser should be able to handle all input files which have this format. We will provide
        benchmark examples for your performance analysis, but you may also want to create some
        yourself to test your implementation.

Task 5 
    (30 marks)
        Write a brief report (no more than 3 A4 pages) containing the following:

            a) A short explanation of your choice of data structure and algorithm.

            b) A run of your algorithm on a small benchmark example. This should include the
            supporting information as described in Task 4.

            c) A performance analysis of your algorithmic design and implementation. This can be
            based either on an empirical study, e.g., doubling hypothesis, or on purely
            theoretical considerations, as discussed in the lectures and tutorials. It should
            include a suggested order-of-growth classification (Big-O notation).

*/
//Done Task
/*
Done Task

Task 1 
    (10 marks)
        Set up a project (Java or C++) as you did for the tutorial exercises.

Task 2 
    (20 marks)
        Choose and implement a data structure which can represent maps such
        as the one in the example.

        It must provide the necessary infrastructure for finding a shortest
        path from the start to the finish.



Task 4 
    (20 marks)
        Choose and implement an algorithm which finds a shortest path from the
        start to the finish in any given map, if one exists (all the benchmarks 
        we provide will have a solution). 

        It should output all the steps of the solution it found, e.g., for the example above:
        1. Start at (10,1)
        2. Move left to (7,1)
        3. Move down to (7,2)
        4. Move left to (6,2)
        5. Move down to (6,10)
        6. Move right to (8,10)
        7. Move up to (8,8)
        8. Move right to (9,8)
        9. Move up to (9,6)
        10. Move left to (3,6)
        11. Move up to (3,1)
        12. Move left to (1,1)
        13. Move down to (1,2)
        14. Move right to (4,2)
        15. Move down to (4,3)
        16. Move left to (2,3)
        17. Move down to (2,5)
        18. Done!
        Where the squares are numbered left to right, top to bottom.


*/
//[USEFULL LINKS]
/*
[ALGORYTHMS LINKS]

Links

[1]Best resource ever
https://www.redblobgames.com/pathfinding/a-star/introduction.html
https://www.redblobgames.com/pathfinding/a-star/implementation.html#cpp-astar

https://www.geeksforgeeks.org/a-search-algorithm/

https://medium.com/@urna.hybesis/pathfinding-algorithms-the-four-pillars-1ebad85d4c6b
https://rosettacode.org/wiki/A*_search_algorithm
https://www.bogotobogo.com/Algorithms/path_finding_algorithm.php
https://neo4j.com/docs/graph-data-science/current/algorithms/astar/

Videos
https://www.youtube.com/watch?v=NJOf_MYGrYs&ab_channel=iGunSlingeRv2
https://www.youtube.com/watch?v=icZj67PTFhc&ab_channel=javidx9
https://www.youtube.com/watch?v=eSOJ3ARN5FM&ab_channel=ComputerScience


[DATA STRUCTURE LINKS]
https://www.redblobgames.com/pathfinding/grids/graphs.html
https://stackoverflow.com/questions/5867889/graph-traversal-with-a-algorithm

Videos
https://www.youtube.com/watch?v=S8kfl_Rx7Rg&ab_channel=AlleyB

*/


int main()
{   



    AStarImplementation a;
    a.RunChoosenAlgorythm();

    return 0;
};


