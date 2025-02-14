// Copyright (c) 2002-2023, The OpenMS Team -- EKU Tuebingen, ETH Zurich, and FU Berlin
// SPDX-License-Identifier: BSD-3-Clause
//
// --------------------------------------------------------------------------
// $Authors: Simon Gene Gottlieb $
// --------------------------------------------------------------------------

#pragma once

#include <OpenMS/FORMAT/ParamCTDFile.h>

namespace OpenMS
{

  /**
  @brief Load from JSON (in a Common Workflow Language (CWL) compatible way) into the Param class.

        The JSON file must contain one top level mapping of param value names to actual values.
        These values can be one of the following types:
            - null
            - boolean
            - int
            - long
            - float
            - double
            - string
            - a CWL style file path ({ "class": "File", "path": "./myFolder/myFile.txt" })
            - an array of these

        param value names match the command line option without the leading '-'. Optionally the ':'
        can be replaced with a double underscore "__".
@code
{
    "in": {
        "class": "File",
        "path": "./myFolder/myFile.txt"
    },
    "out_prefix": "test_cwl_",
    "algorithm:threshold": 5,
    "algorithm:score_type": "ID"
}
@endcode

Same file with "__" instead of ':' as the section separator.
@code
{
    "in": {
        "class": "File",
        "path": "./myFolder/myFile.txt"
    },
    "out_prefix": "test_cwl_",
    "algorithm__threshold": 5,
    "algorithm__score_type": "ID"
}
@endcode
*/
  class OPENMS_DLLAPI ParamCWLFile
  {
  public:
    /**
      @brief Read JSON file that is formatted in CWL conforming style.

      @param filename The file from where to read the Param object.
      @param param A param object with pre-filled defaults, which are updated by the values in the JSON file
      @return returns true if file was successfully loaded; false if an unknown (non-default) parameter name was encountered in the JSON file

      @exception Exception::FileNotFound is thrown if the file could not be found
      @exception Exception::ParseError is thrown if an error occurs during parsing
    */
    static bool load(const std::string& filename, Param& param);
  };
} // namespace OpenMS
