# TODO

- Finish board representation
- Research ways of generating moves
- Implement a history element so we can backtrack

# Chess Engine

This is an implementation of a basic chess-engine written in the C programming language. I utilise bitboards/bitmaps in this project to optimise the engine. 

# Magic Bitboards

## How it works
A magic move-bitboard generation technique consists of four key steps:

1. Mask the relevant occupancy bits to form a key. For exmaple if you had a rook on a1, the relevant occupancy bits ill be from a2-a7 and b1-g1.

2. Multiply the key by a "magic number" to obtain an index mapping. This amgic number can be generated by bruce-orce trial and error quite easily although it isn't 100% certain that the magic number is the best possible.

3. Right shift the index mapping by 64-n bits to create an index, where n is the number of bits in the index. A better magice number will have less bits required in the index.

4. Use the index to refernce a preinitialized move database.

## Implementation

Using a single 64-bit word, we can store positions of all pieces of type x, by representing the squares as bits in the 64-bit bitmap.

An example of a map is a1 = 0, h1=7, a8=56, and h8=63. 

The simplest implemations is to use 12 of these bitmaps, to represent the locations of the twelve difference pieces (king, queen, rook, bishop, knight and pawn). Thus giving us 12 different bitmaps, 6 ofr black, six for white. We can label these WhitePawns, WhiteKnights,.., WhiteKing, BlackPawns, BlackKnights,...BlackKing. It is also efficient to add two more bitmaps, BlackPieces, WhitePieces.