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

#ifndef LUCI_INTERPRETER_LOADER_KERNELBUILDER_H
#define LUCI_INTERPRETER_LOADER_KERNELBUILDER_H

#include "core/Kernel.h"
#include "core/RuntimeGraph.h"

#include "luci_interpreter/core/reader/CircleMicroReader.h"

#include <memory>
#include <unordered_map>

namespace luci_interpreter
{

class KernelBuilderRegistry;

class KernelBuilder
{
public:
  KernelBuilder(IBaseRuntimeGraph *runtime_graph, CircleReader *circle_reader);

  ~KernelBuilder();

  std::unique_ptr<Kernel> build(std::vector<const Tensor *> &&inputs,
                                std::vector<Tensor *> &&output,
                                const circle::BuiltinOperator opcode, const int32_t op_index);

  CircleReader *get_circle_reader() { return _circle_reader; }

  IBaseRuntimeGraph *get_runtime_graph() { return _runtime_graph; }

private:
  std::unique_ptr<KernelBuilderRegistry> _builder_registry;
  IBaseRuntimeGraph *_runtime_graph;
  CircleReader *_circle_reader;
};

} // namespace luci_interpreter

#endif // LUCI_INTERPRETER_LOADER_KERNELBUILDER_H
