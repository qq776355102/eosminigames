# EOSMINIGAMES

The compiled contract is deployed on the EOS mainnet account [eosminigames](https://eospark.com/MainNet/account/eosminigames).

The project aims to build decentralized games that are absolutely fair. Players are protected by the code itself.

Many more games will be included in the future. Currently, the contract includes the following:

- Blackjack (also known as twenty-one)

## Blackjack

In the blackjack game, each player plays against a dealer. The game is provably fair with the use of the following procedure:

1. The dealer opens a game by submitting the hash of a `dealer secret`
2. A player then joins the game by submitting a `player secret` (just the random number, not the hash of it).
3. The dealer computes the sum of the two secrets as the `shuffle seed` on his own computer.
4. The dealer uses the seed to shuffle a deck of 52 cards in a pre-defined way on his own computer.
5. The game begins. The dealer *must* respond with the card within a given time interval when the player asks to draw a card.
6. After the game ends, the dealer *must* submit the `dealer secret` for the contract to validate. Failure to submit the correct secret in time or submitting an invalid secret would all make the player win automatically.

There's a small change in the game's rule: if the game results in a "push" (same score), the player wins. The change is to make the game absolutely fair, as the dealer would know the complete order of the cards during the whole game. It's true but it doesn't matter with the change of rule as there's nothing the dealer can do with this knowledge. After the player finishes his round, the dealer has no choice but to keep drawing until his hand exceeds the player's.