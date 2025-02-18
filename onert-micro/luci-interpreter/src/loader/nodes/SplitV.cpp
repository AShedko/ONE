/*
 * Copyright (c) 2021 Samsung Electronics Co., Ltd. All Rights Reserved
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

#include "Builders.h"

#include "kernels/SplitV.h"

namespace luci_interpreter
{

std::unique_ptr<Kernel> build_kernel_CircleSplitV(std::vector<const Tensor *> &&inputs,
                                                  std::vector<Tensor *> &&outputs,
                                                  const uint32_t op_index, KernelBuilder &builder)
{
  assert(inputs.size() == 3);

  const Tensor *input = inputs.at(0);
  const Tensor *sizes_data = inputs.at(1);
  const Tensor *axis = inputs.at(2);
  std::vector<Tensor *> output_tensors(outputs.size());

  for (uint32_t i = 0; i < outputs.size(); ++i)
  {
    output_tensors[i] = outputs.at(i).first;
  }

  // NOTE 'num_splits' attribute is ignored.
  return std::make_unique<kernels::SplitV>(input, sizes_data, axis, std::move(output_tensors));
}

} // namespace luci_interpreter
