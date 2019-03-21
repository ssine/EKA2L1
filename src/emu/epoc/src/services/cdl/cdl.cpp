/*
 * Copyright (c) 2019 EKA2L1 Team.
 * 
 * This file is part of EKA2L1 project.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <epoc/services/cdl/cdl.h>
#include <epoc/services/cdl/ops.h>

#include <common/e32inc.h>
#include <e32err.h>

namespace eka2l1 {
    cdl_server_session::cdl_server_session(service::typical_server *svr, service::uid client_ss_uid)
        : service::typical_session(svr, client_ss_uid) {
    }

    void cdl_server_session::fetch(service::ipc_context *ctx) {
        switch (ctx->msg->function) {
        case epoc::cdl_server_cmd_notify_change: {
            notifier.requester = ctx->msg->own_thr;
            notifier.sts = ctx->msg->request_sts;

            break;
        }

        default: {
            LOG_ERROR("Unimplemented IPC opcode for CDL server session: 0x{:X}", ctx->msg->function);
            break;
        }
        }
    }

    cdl_server::cdl_server(eka2l1::system *sys)
        : service::typical_server(sys, "CdlServer") {
    }

    void cdl_server::connect(service::ipc_context ctx) {
        create_session<cdl_server_session>(&ctx);
        ctx.set_request_status(KErrNone);
    }
}
