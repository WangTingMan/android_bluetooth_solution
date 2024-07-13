#pragma once
#include <BT/StackLayer/BluetoothBaseInterface.h>

#include <hardware/bluetooth.h>

class BluetoothBaseImplementation : public BluetoothBaseInterface
{

public:

    static BluetoothBaseImplementation& GetInstance();

    BluetoothBaseImplementation();

    void InitPlatform() override;

    void Init() override;

    void Enable(bool a_enable = true) override;

    void StartSearch(bool a_search = true) override;

    void PairWithDevice(BluetoothAddress a_address) override;

    void DeletePairedDevice(BluetoothAddress a_address) override;

    void SetLocalName(std::string const& a_name) override;

    bool SetLocalDeviceSettings
        (
        bool a_pairable,     //!< [in] whether BT module is pairable
        bool a_discoverable, //!< [in] whether BT module is discoverable
        bool a_connectable   //!< [in] whether BT module is connectable
        ) override;

    bool SspPairingReply
        (
        BluetoothAddress a_address,
        bool             a_accept,
        SppPairingMethod a_pairingMethod,
        uint32_t a_passkey
        ) override;

    void* GetFakeAudioInterfaceFromModule() override;

    void test() override;

public:

    void OnPairedDeviceAddressReceived
        (
        std::vector<BluetoothAddress> a_addresses
        );

    bt_interface_t* GetBtInterface()const
    {
        return m_interface;
    }

private:

    bool LoadBluetoothLibrary();

    bt_callbacks_t m_callback_;
    bt_os_callouts_t m_callout;
    bt_interface_t* m_interface = nullptr;
    void* m_fakeAudioInterface = nullptr;
};

