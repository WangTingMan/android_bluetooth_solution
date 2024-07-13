#pragma once
#include <BT/StackLayer/BluetoothGattClientInterface.h>
#include <BT/BluetoothCommonDefs.h>

#include <hardware/bt_common_types.h>
#include <hardware/bt_gatt_client.h>

struct GattClientBaseMessage
{
    enum class Type
    {
        Unknown,
        RegisterClient,
        ConnectStatusChanged,
        SearchComplete,
        RegisterForNotification,
        Notify,
        ReadCharacteristic,
        WriteCharacteristic,
        ReadDescriptor,
        WriteDescriptor,
        ExecuteWrite,
        ReadRemoteRssi,
        ConfigureMtu,
        CongestionClient,
        GetGattDb,
        ServicesRemoved,
        ServicesAdded,
        PhyClientUpdated,
        ConnClientUpdated,
        DiscoveryDone
    };
    Type m_type = Type::Unknown;

    virtual ~GattClientBaseMessage() {}
};

struct RegisterClientMessage : public GattClientBaseMessage
{
    RegisterClientMessage() { m_type = GattClientBaseMessage::Type::RegisterClient; }
    int status = 0;
    int client_if = 0;
    std::vector<uint8_t> uuid;
};

struct ConnectStatusMessage : public GattClientBaseMessage
{
    ConnectStatusMessage() { m_type = GattClientBaseMessage::Type::ConnectStatusChanged; }
    int conn_id;
    ConnectionStatus status;
    int client_if;
    BluetoothAddress address;
};

struct SearchCompleteMessage : public GattClientBaseMessage
{
    SearchCompleteMessage() { m_type = GattClientBaseMessage::Type::SearchComplete; }
    int conn_id = 0;
    int status = 0;
};

struct RegisterForNotificationMessage : public GattClientBaseMessage
{
    RegisterForNotificationMessage() { m_type = GattClientBaseMessage::Type::RegisterForNotification; }
    int conn_id = 0;
    int registered = 0;
    int status = 0;
    uint16_t handle = 0;
};

struct GetGattDbMessage : public GattClientBaseMessage
{
    GetGattDbMessage() { m_type = GattClientBaseMessage::Type::GetGattDb; }
    int conn_id = 0;
    std::vector<btgatt_db_element_t> db_elements;
};

struct NotifyMessage : public GattClientBaseMessage
{
    static constexpr uint32_t MAX_ATTR_SIZE = 600;
    NotifyMessage() { m_type = GattClientBaseMessage::Type::Notify; }
    int conn_id = 0;
    uint8_t value[MAX_ATTR_SIZE] = {};
    BluetoothAddress bda;
    uint16_t handle = 0;
    uint16_t len = 0;
    uint8_t is_notify = 0;
};

struct ReadCharacteristicMessage : public GattClientBaseMessage
{
    ReadCharacteristicMessage() { m_type = GattClientBaseMessage::Type::ReadCharacteristic; }
    int conn_id;
    int status;
    btgatt_read_params_t data;
};

struct WriteCharacteristicMessage : public GattClientBaseMessage
{
    WriteCharacteristicMessage() { m_type = GattClientBaseMessage::Type::WriteCharacteristic; }
    int conn_id;
    int status;
    uint16_t handle;
};

struct ReadDescriptorMessage : public GattClientBaseMessage
{
    ReadDescriptorMessage() { m_type = GattClientBaseMessage::Type::ReadDescriptor; }
    int conn_id;
    int status;
    btgatt_read_params_t data;
};

struct WriteDescriptorMessage : public GattClientBaseMessage
{
    WriteDescriptorMessage() { m_type = GattClientBaseMessage::Type::WriteDescriptor; }
    int conn_id;
    int status;
    uint16_t handle;
};

struct ExecuteWriteMessage : public GattClientBaseMessage
{
    ExecuteWriteMessage() { m_type = GattClientBaseMessage::Type::ExecuteWrite; }
    int conn_id;
    int status;
};

struct ReadRemoteRssiMessage : public GattClientBaseMessage
{
    ReadRemoteRssiMessage() { m_type = GattClientBaseMessage::Type::ReadRemoteRssi; }
    int client_if;
    RawAddress bda;
    int rssi;
    int status;
};

struct ConfigureMtuMessage : public GattClientBaseMessage
{
    ConfigureMtuMessage() { m_type = GattClientBaseMessage::Type::ConfigureMtu; }
    int conn_id;
    int status;
    int mtu;
};

struct CongestionClientMessage : public GattClientBaseMessage
{
    CongestionClientMessage() { m_type = GattClientBaseMessage::Type::CongestionClient; }
    int conn_id;
    bool congested;
};

struct ServicesRemovedMessage : public GattClientBaseMessage
{
    ServicesRemovedMessage() { m_type = GattClientBaseMessage::Type::ServicesRemoved; }
    int conn_id;
    uint16_t start_handle;
    uint16_t end_handle;
};

struct ServicesAddedMessage : public GattClientBaseMessage
{
    ServicesAddedMessage() { m_type = GattClientBaseMessage::Type::ServicesAdded; }
    int conn_id;
    btgatt_db_element_t added;
    int added_count;
};

struct PhyClientUpdatedMessage : public GattClientBaseMessage
{
    PhyClientUpdatedMessage() { m_type = GattClientBaseMessage::Type::PhyClientUpdated; }
    int conn_id;
    uint8_t tx_phy;
    uint8_t rx_phy;
    uint8_t status;
};

struct ConnClientUpdatedMessage : public GattClientBaseMessage
{
    ConnClientUpdatedMessage() { m_type = GattClientBaseMessage::Type::ConnClientUpdated; }
    int conn_id;
    uint16_t interval;
    uint16_t latency;
    uint16_t timeout;
    uint8_t status;
};

struct DiscoveryDoneMessage : public GattClientBaseMessage
{
    DiscoveryDoneMessage() { m_type = GattClientBaseMessage::Type::DiscoveryDone; }
    BluetoothAddress address;
};

class BluetoothGattClientInterfaceImpl : public BluetoothGattClientInterface
{

};

