/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LUCI_INTERPRETER_INTERPRETER_H
#define LUCI_INTERPRETER_INTERPRETER_H

#include "luci_interpreter/core/Tensor.h"
#include "luci_interpreter/InterpreterConfigure.h"

#include "memory_managers/MemoryManager.h"

#include <memory>
#include <vector>
#include <unordered_map>

namespace luci_interpreter
{

class Interpreter
{
public:
  // Construct default interpreter with dynamic allocations and with input allocations
  explicit Interpreter(const char *model_data_raw);

  // Construct interpreter with configurations
  explicit Interpreter(const char *model_data_raw, const InterpreterConfigure &configuration);

  ~Interpreter();

  static void writeInputTensor(Tensor *input_tensor, const void *data, size_t data_size);

  static void writeInputTensorWithoutCopy(Tensor *input_tensor, const void *data);

  static void readOutputTensor(const Tensor *output_tensor, void *data, size_t data_size);

  void interpret();

  std::vector<Tensor *> getInputTensors();
  std::vector<Tensor *> getOutputTensors();

private:
  // _default_memory_manager should be before _runtime_module due to
  // the order of deletion in the destructor
  std::unique_ptr<IMemoryManager> _memory_manager;
  std::unique_ptr<class RuntimeModule> _runtime_module;
};

} // namespace luci_interpreter

#endif // LUCI_INTERPRETER_INTERPRETER_H
