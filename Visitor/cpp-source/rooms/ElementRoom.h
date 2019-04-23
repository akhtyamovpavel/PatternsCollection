//
// Created by Pavel Akhtyamov on 2019-04-23.
//

#pragma once

#include <string>

#include "../workers/Visitor.h"

struct Surface {
  std::string material;
  std::string color;

  virtual void Show();
};

class ElementRoom {
 public:
  virtual void Accept(Visitor* visitor) = 0;
  virtual std::string GetName() = 0;
  virtual ~ElementRoom() = default;

  // TODO(akhtyamovpavel) realize ostream operator
  virtual void ShowDecorations();
  Surface wall;
  Surface floor;
  Surface ceiling;

};



