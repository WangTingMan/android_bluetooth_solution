#pragma once

class BluetoothAdvScannerImplementation
{

public:

    static BluetoothAdvScannerImplementation& GetInstance();

    BluetoothAdvScannerImplementation();

    void init();

    void StartFullScan( bool a_start = true);

private:

    void StartFilterScan();

};

