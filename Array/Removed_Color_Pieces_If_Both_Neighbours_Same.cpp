// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

/*

First observation : If someone removed a piece from its place (Let's say Alice) It won't give the other player more moves to help him play more.🤔
Ex -> BBAAABB -> Alice plays -> BBAABB -> Bob loses
We can see that from the begining of the game, Bob doesn't have any pieces to move and Alice's move didn't give hime extra moves like it didn't make the string BBBB.🤯

Second observation : From first observation we can conclude and I mentioned it in the first one also, Every player have dedicated number of moves in the begining of the game and it can't be increased or decreased.😔

From these two observations the solution become much easier. Only count the moves for each player and if Alice has more moves then she wins and if Bob has more or equal moves then he wins.🚀🚀

*/

/*

    bool winnerOfGame(string colors) {
        int aCount=0;
        int bCount=0;
        if(colors.size()==2)
        {
            return false;
        }
        for(int i=1;i<colors.size()-1;i++)
        {
            if(colors[i]=='A'&&colors[i-1]=='A' &&colors[i+1]=='A')
            {
                aCount++;
            }
            if(colors[i]=='B'&&colors[i-1]=='B' &&colors[i+1]=='B')
            {
                bCount++;
            }
        }
        if(aCount>bCount)
        {
            return true;
        }
        return false;
    }

*/