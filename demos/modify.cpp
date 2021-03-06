#include <iostream>
#include "zippy.hpp"
#include <OpenXLSX.hpp>

#include "tkc/fs.h"
#include "tkc/mem.h"

using namespace std;
using namespace Zippy;
using namespace OpenXLSX;

static ret_t zip_replace_entry(const char* zip_filename, const char* entry_name, const char* filename) {
  uint8_t* data = NULL;
  uint32_t size = 0;

  ZipArchive zip(zip_filename);

  data = (uint8_t*)file_read(filename,  &size);
  return_value_if_fail(data != NULL, RET_BAD_PARAMS);

  ZipEntryData edata(size);
  memcpy(edata.data(), data, size);
  TKMEM_FREE(data);

  zip.DeleteEntry(entry_name);
  zip.AddEntry(entry_name, edata);

  zip.Save();
  zip.Close();

  return RET_OK;
}

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

    zip_replace_entry("modified.xlsx", "xl/media/image2.jpeg", "data/orange.jpeg");
  
    return 0;
}
