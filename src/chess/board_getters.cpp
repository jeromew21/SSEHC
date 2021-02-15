#include "game/chessboard.hpp"

Color Board::get_turn() const {
  return state_.turn;
}

u64 Board::get_hash() const {
  return hash_;
}

CMove Board::last_move() const {
  return state_.last_move;
}

bool Board::can_unmake() const {
  return state_stack_.can_pop();
}

u64 Board::occupancy() const
{
  return occupancy(White) | occupancy(Black);
}

u64 Board::occupancy(Color color) const
{
  assert(color == White || color == Black);
  if (color == White)
  {
    return bitboard_[piece::white::king] | bitboard_[piece::white::queen] | bitboard_[piece::white::bishop] |
           bitboard_[piece::white::pawn] | bitboard_[piece::white::rook] | bitboard_[piece::white::knight];
  }
  return bitboard_[piece::black::king] | bitboard_[piece::black::queen] | bitboard_[piece::black::bishop] |
         bitboard_[piece::black::pawn] | bitboard_[piece::black::rook] | bitboard_[piece::black::knight];
}