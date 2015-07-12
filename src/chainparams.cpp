// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.

        pchMessageStart[0] = 0x89;
        pchMessageStart[1] = 0x1f;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0x1e;

        vAlertPubKey = ParseHex("04ffde6668d0dff8ba92c67b1f751568e11608f23c8c0437eccd5a6ec713ae3638238478b816783593d552bc8b6a57147dd67596eb372b0cadc743d3835c43e9e3");

        nDefaultPort = 29100;
        nRPCPort = 29200;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);

        // Build the genesis block. Note that the output of the genesis coinbase cannot
        // be spent as it did not originally exist in the database.

        //CBlock(hash=00000034a85621dcdf6ba0e1525f6eff8d57c7a722c4c4a565c35dc197f642ae, ver=1, hashPrevBlock=0000000000000000000000000000000000000000000000000000000000000000, hashMerkleRoot=aebb4aaf2c1997edaec0f4fa179233647c2c64f061c41aabdc222a5e7ba3ba14, nTime=1435176000, nBits=1f00ffff, nNonce=31083197, vtx=1, vchBlockSig=)
        //Coinbase(hash=aebb4aaf2c1997edaec0f4fa179233647c2c64f061c41aabdc222a5e7ba3ba14, nTime=1435176000, ver=1, vin.size=1, vout.size=1, nLockTime=0)
        //  CTxIn(COutPoint(0000000000, 4294967295), coinbase 00012a094c6574732048657878)
        //  CTxOut(empty)
        //vMerkleTree:  aebb4aaf2c1997edaec0f4fa179233647c2c64f061c41aabdc222a5e7ba3ba14

        const char* pszTimestamp = "Lets Hexx";
        CTransaction txNew;
        txNew.nTime = 1435176000;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 0 << CBigNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].SetEmpty();
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1435176000;
        genesis.nBits    = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce   = 31083197;


        hashGenesisBlock = uint256("0x00000034a85621dcdf6ba0e1525f6eff8d57c7a722c4c4a565c35dc197f642ae");

        if (false && (genesis.GetHash() != hashGenesisBlock))
        {
            uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256()>>10;
            while (genesis.GetHash() > hashTarget)
            {
                ++genesis.nNonce;
                if (genesis.nNonce == 0)
                {
                    printf("NONCE WRAPPED, incrementing time");
                    ++genesis.nTime;
                }
            }
            cout << "genesis: \n" << genesis.ToString() << endl;
            cout << "genesis.GetHash(): " << genesis.GetHash().ToString() << endl;
            cout << "genesis.hashMerkleRoot: " << genesis.hashMerkleRoot.ToString() << endl;
            cout << "genesis.nTime: " << genesis.nTime << endl;
            cout << "genesis.nNonce: " << genesis.nNonce << endl;
        }

        hashGenesisBlock = genesis.GetHash(); 

        assert(hashGenesisBlock == uint256("0x00000034a85621dcdf6ba0e1525f6eff8d57c7a722c4c4a565c35dc197f642ae"));
        assert(genesis.hashMerkleRoot == uint256("0xaebb4aaf2c1997edaec0f4fa179233647c2c64f061c41aabdc222a5e7ba3ba14"));


        vSeeds.push_back(CDNSSeedData("seed1", "94.254.73.95"));
        vSeeds.push_back(CDNSSeedData("seed2", "108.61.198.84"));
        vSeeds.push_back(CDNSSeedData("seed3", "2.244.164.160"));
        vSeeds.push_back(CDNSSeedData("seed4", "108.61.99.205"));
        vSeeds.push_back(CDNSSeedData("seed5", "178.33.126.221"));
        vSeeds.push_back(CDNSSeedData("seed6", "2.244.164.160"));
        vSeeds.push_back(CDNSSeedData("seed7", "46.59.62.165"));
        vSeeds.push_back(CDNSSeedData("seed8", "74.77.15.47"));



        base58Prefixes[PUBKEY_ADDRESS] = list_of(40);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(100);
        base58Prefixes[SECRET_KEY] =     list_of(219);

        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nTargetSpacing = 60; // seconds

        nLastPOWBlock  = 10300;
        nInstaMinePoWReward = 0 * COIN;
        nInstaMineLastBlock = 60;
        nRegularPoWReward = 50 * COIN;

        nFirstPoSBlock = nLastPOWBlock - 300;
        nCoinbaseMaturity = 50;
        nLaunchTime = txNew.nTime;
        nStakeMinAge = 4 * 60 * 60;
        nModifierInterval = 1 * 60;
        nPoSCoinReward = 25; // percents
        nAdvisablePoSTxOut = 2500 * COIN;

        nMasternodeFixReward = 1 * COIN;
        nMasternodeProportionalReward = 0; // percents
        nMasternodeValue = 10000 * COIN;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.

        pchMessageStart[0] = 0x89;
        pchMessageStart[1] = 0x1f;
        pchMessageStart[2] = 0xb6;
        pchMessageStart[3] = 0x9e;

        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 16);

        vAlertPubKey = ParseHex("04d65960d060168c6ad6efd2f8cf7bd146ca0f3c9fe070e70f7104729b7abd2fcc25a76b4ceac500e5bd5a105f541be0347cd3294139018294f339431bd5f10d72");

        nDefaultPort = 29300;
        nRPCPort = 29400;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = bnProofOfWorkLimit.GetCompact();
        genesis.nNonce = 124855;

        hashGenesisBlock = uint256("0x00007e0844bc5aba4bfe0f0ee6018e8bb09b743c6ba5d1735eb8d804d6276937");

        if (true && (genesis.GetHash() != hashGenesisBlock))
        {
            uint256 hashTarget = CBigNum().SetCompact(genesis.nBits).getuint256();
            while (genesis.GetHash() > hashTarget)
            {
                ++genesis.nNonce;
                if (genesis.nNonce == 0)
                {
                    printf("NONCE WRAPPED, incrementing time");
                    ++genesis.nTime;
                }
            }
            cout << "genesis: \n" << genesis.ToString() << endl;
            cout << "genesis.GetHash(): " << genesis.GetHash().ToString() << endl;
            cout << "genesis.hashMerkleRoot: " << genesis.hashMerkleRoot.ToString() << endl;
            cout << "genesis.nTime: " << genesis.nTime << endl;
            cout << "genesis.nNonce: " << genesis.nNonce << endl;
        }

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x00007e0844bc5aba4bfe0f0ee6018e8bb09b743c6ba5d1735eb8d804d6276937"));


        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = list_of(40);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(100);
        base58Prefixes[SECRET_KEY]     = list_of(219);

        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x35)(0x87)(0xCF);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x35)(0x83)(0x94);

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nTargetSpacing = 10; // seconds

        nLastPOWBlock = 0x7fffffff;
        nInstaMinePoWReward = 0 * COIN;
        nInstaMineLastBlock = 60;
        nRegularPoWReward = 50 * COIN;

        nFirstPoSBlock = 7000;
        nCoinbaseMaturity = 50;
        nLaunchTime = 1435086000;
        nStakeMinAge = 1 * 60 * 60;
        nModifierInterval = 1 * 60;
        nPoSCoinReward = 25; // percents
        nAdvisablePoSTxOut = 2500 * COIN;

        nMasternodeFixReward = 1 * COIN;
        nMasternodeProportionalReward = 0; // percents
        nMasternodeValue = 10000 * COIN;
    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;

static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);
    
    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
