#include "../src/polkadot.h"
#include "helpers/mockjsonrpc.h"
#undef NDEBUG
#include <cassert>

int main(int argc, char *argv[]) {
    LoggerStub log;
    CMockJsonRpcSystemInfo mockRpc;

    CPolkaApi app(&log, &mockRpc);
    app.connect();

    auto resp3 = app.getSystemInfo();

    // Check chainId
    assert(strcmp(resp3->chainId, "Alexander") == 0);

    // Check chainName
    assert(strcmp(resp3->chainName, "parity-polkadot") == 0);

    // Check version
    assert(strcmp(resp3->version, "0.4.4") == 0);

    // Check tokenSymbol
    assert(strcmp(resp3->tokenSymbol, "DOT") == 0);

    // Check tokenDecimals
    assert(resp3->tokenDecimals == 15);

    app.disconnect();

    cout << "success" << endl;

    return 0;
}
