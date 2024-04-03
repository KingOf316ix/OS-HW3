#include <iostream>
#include <unordered_map>

using namespace std;

const int PAGE_SIZE = 256;           
const int NUM_PAGES = 256;           
const int FRAME_SIZE = 256;          
const int NUM_FRAMES = 256;          

// Page/Frame Table Initialization
unordered_map<int, int> pageFrameTable;

void PageFrame() {
    for (int page = 0; page < NUM_PAGES; ++page) {
        pageFrameTable[page] = page % NUM_FRAMES;
    }
}

// Logical to Physical Address Conversion

void AddressConversion(int LogicAdd) {

    int pageNum = LogicAdd / PAGE_SIZE;  
    int offset = LogicAdd % PAGE_SIZE;      

    if (pageFrameTable.find(pageNum) == pageFrameTable.end()) {
        cout << "Page fault occurred for logical address: 0x" << hex << LogicAdd << endl;
        return;
    }

    int frameNum = pageFrameTable[pageNum];

    int PhysicAdd = frameNum * FRAME_SIZE + offset;

    // Output logical address, page number, offset, physical address

    cout << "Logical Address: 0x" << hex << LogicAdd << endl;
    cout << "Page Number: 0x" << hex << pageNum << endl;
    cout << "Offset: 0x" << hex << offset << endl;
    cout << "Physical Address: 0x" << hex << PhysicAdd << endl << endl;
}

int main() {
    PageFrame();

    int logicalAddresses[] = { 0x3A7F, 0xABCD, 0x5678 };

    for (int i = 0; i < 3; ++i) {
        AddressConversion(logicalAddresses[i]);
    }
    return 0;
}
