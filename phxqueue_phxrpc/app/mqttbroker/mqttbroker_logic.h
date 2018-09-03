/*
Tencent is pleased to support the open source community by making PhxQueue available.
Copyright (C) 2017 THL A29 Limited, a Tencent company. All rights reserved.
Licensed under the BSD 3-Clause License (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

<https://opensource.org/licenses/BSD-3-Clause>

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
*/



#pragma once

#include "phxqueue/comm.h"
#include "phxqueue_phxrpc/app/logic/mqtt.h"


namespace phxqueue_phxrpc {

namespace mqttbroker {


phxqueue::comm::RetCode
AddSubscribe(const std::string &client_id, const uint32_t qos,
             phxqueue_phxrpc::logic::mqtt::TopicPb *const topic_pb);

phxqueue::comm::RetCode
RemoveSubscribe(const std::string &remove_client_id,
                phxqueue_phxrpc::logic::mqtt::TopicPb *const topic_pb);


}  // namespace mqttbroker

}  // namespace phxqueue_phxrpc
