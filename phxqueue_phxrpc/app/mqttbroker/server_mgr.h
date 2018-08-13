/*
Tencent is pleased to support the open source community by making
PhxRPC available.
Copyright (C) 2016 THL A29 Limited, a Tencent company.
All rights reserved.

Licensed under the BSD 3-Clause License (the "License"); you may
not use this file except in compliance with the License. You may
obtain a copy of the License at

https://opensource.org/licenses/BSD-3-Clause

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
implied. See the License for the specific language governing
permissions and limitations under the License.

See the AUTHORS file for names of contributors.
*/

#pragma once

#include "phxrpc/rpc.h"

#include "event_loop_server.h"


class ServerMgr {
  public:
    // TODO:
    //ServerMgr(const HshaServerConfig *const config);
    ServerMgr();
    virtual ~ServerMgr();

    phxrpc::HshaServer *hsha_server() const;
    void set_hsha_server(phxrpc::HshaServer *const hsha_server);
    EventLoopServer *event_loop_server() const;
    void set_event_loop_server(EventLoopServer *const event_loop_server);

    void Send(const uint64_t session_id, phxrpc::BaseResponse *const resp);
    int SendAndWaitAck(const uint64_t session_id, phxrpc::BaseResponse *const resp,
                       phxrpc::UThreadEpollScheduler *const uthread_scheduler,
                       const std::string &ack_key, void *&ack_value);
    int Ack(const std::string &ack_key, void *const ack_value);

  private:
    phxrpc::HshaServer *hsha_server_{nullptr};
    EventLoopServer *event_loop_server_{nullptr};
    // TODO:
    //const HshaServerConfig *config_{nullptr};
    std::map<std::string, std::unique_ptr<phxrpc::UThreadNotifier>> notifier_map_;
};
