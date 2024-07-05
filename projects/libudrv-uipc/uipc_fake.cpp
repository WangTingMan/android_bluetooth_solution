#include "udrv/include/uipc.h"

const char* dump_uipc_event( tUIPC_EVENT event )
{
    return "No Implementation";
}

std::unique_ptr<tUIPC_STATE> UIPC_Init()
{
    return std::make_unique<tUIPC_STATE>();
}

bool UIPC_Open( tUIPC_STATE& uipc, tUIPC_CH_ID ch_id, tUIPC_RCV_CBACK* p_cback,
                const char* socket_path )
{
    return true;
}

void UIPC_Close( tUIPC_STATE& uipc, tUIPC_CH_ID ch_id )
{

}

bool UIPC_Send( tUIPC_STATE& uipc, tUIPC_CH_ID ch_id, uint16_t msg_evt,
                const uint8_t* p_buf, uint16_t msglen )
{
    return true;
}

uint32_t UIPC_Read( tUIPC_STATE& uipc, tUIPC_CH_ID ch_id, uint8_t* p_buf,
                    uint32_t len )
{
    return 0;
}

bool UIPC_Ioctl( tUIPC_STATE& uipc, tUIPC_CH_ID ch_id, uint32_t request,
                 void* param )
{
    return true;
}

