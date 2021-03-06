#include <OpenXLSX.hpp>
#include <iostream>

using namespace std;
using namespace OpenXLSX;

int main()
{
    cout << "********************************************************************************\n";
    cout << "DEMO PROGRAM #02: Sheet Handling\n";
    cout << "********************************************************************************\n";

    XLDocument doc;
    doc.open("data/template.xlsx");
   auto wks = doc.workbook().worksheet("Sheet1");

    wks.cell(XLCellReference("A1")).value() = 3.14159;
    wks.cell(XLCellReference("B1")).value() = 42;
    wks.cell(XLCellReference("C1")).value() = "  Hello AWTK!  ";

    doc.saveAs("modified.xlsx");

    return 0;
}
