#include "BluetoothPANImplementation.h"
#include "BluetoothBaseImplementation.h"

#include <pan_api.h>
#include <cutils/bitops.h>

__BEGIN_DECLS

void btpan_connection_state_callback_impl
    (
    btpan_connection_state_t state,
    bt_status_t error,
    const RawAddress* bd_addr,
    int local_role,
    int remote_role
    )
{

}

void btpan_control_state_callback_impl
    (
    btpan_control_state_t state,
    int local_role, bt_status_t error,
    const char* ifname
    )
{

}

__END_DECLS

BluetoothPANImplementation& BluetoothPANImplementation::GetInstance()
{
	static BluetoothPANImplementation instance;
	return instance;
}

BluetoothPANInterface& BluetoothPANInterface::GetInterface()
{
	return BluetoothPANImplementation::GetInstance();
}

void BluetoothPANImplementation::Init()
{
    bt_interface_t* interfaceBt = nullptr;
    interfaceBt = BluetoothBaseImplementation::GetInstance().GetBtInterface();
    m_pan_interface = (btpan_interface_t*)interfaceBt->get_profile_interface
        (BT_PROFILE_PAN_ID);

    memset(&m_callbacks, 0x00, sizeof(btpan_callbacks_t));
    m_callbacks.connection_state_cb = &btpan_connection_state_callback_impl;
    m_callbacks.control_state_cb = &btpan_control_state_callback_impl;
    m_pan_interface->init(&m_callbacks);

    m_pan_interface->enable(BTPAN_ROLE_PANU);


}

bool BluetoothPANImplementation::Connect(BluetoothAddress a_address)
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);
    m_pan_interface->connect(&address, BTPAN_ROLE_PANU, BTPAN_ROLE_PANNAP);
    return true;
}

bool BluetoothPANImplementation::disconnect(BluetoothAddress a_address)
{
    RawAddress address;
    memcpy(address.address, a_address.address, BluetoothAddress::kLength);
    m_pan_interface->disconnect(&address);
    return true;
}