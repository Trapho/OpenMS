// Copyright (c) 2002-2023, The OpenMS Team -- EKU Tuebingen, ETH Zurich, and FU Berlin
// SPDX-License-Identifier: BSD-3-Clause
//
// --------------------------------------------------------------------------
// $Maintainer: Timo Sachsenberg $
// $Authors: Stephan Aiche, Samuel Wein $
// --------------------------------------------------------------------------

#pragma once

#include <OpenMS/config.h>

#include <OpenMS/ANALYSIS/QUANTITATION/IsobaricQuantitationMethod.h>

namespace OpenMS
{
  /**
    @brief TMT 16plex quantitation to be used with the IsobaricQuantitation.

    @htmlinclude OpenMS_TMTSixteenPlexQuantitationMethod.parameters
  */
  class OPENMS_DLLAPI TMTSixteenPlexQuantitationMethod :
    public IsobaricQuantitationMethod
  {
public:
    /// Default c'tor
    TMTSixteenPlexQuantitationMethod();

    /// d'tor
    ~TMTSixteenPlexQuantitationMethod() override = default;

    /// Copy c'tor
    TMTSixteenPlexQuantitationMethod(const TMTSixteenPlexQuantitationMethod& other);

    /// Assignment operator
    TMTSixteenPlexQuantitationMethod & operator=(const TMTSixteenPlexQuantitationMethod& rhs);

    /// @brief Methods to implement from IsobaricQuantitationMethod
    /// @{

    const String& getMethodName() const override;

    const IsobaricChannelList& getChannelInformation() const override;

    Size getNumberOfChannels() const override;

    Matrix<double> getIsotopeCorrectionMatrix() const override;

    Size getReferenceChannel() const override;

    /// @}

  private:
    /// the actual information on the different tmt16plex channels.
    IsobaricChannelList channels_;

    /// The name of the quantitation method.
    static const String name_;

    /// The reference channel for this experiment.
    Size reference_channel_;

    /// List of available channel names as they are presented to the user
    static const std::vector<std::string> channel_names_;

  protected:
    /// implemented for DefaultParamHandler
    void setDefaultParams_();

    /// implemented for DefaultParamHandler
    void updateMembers_() override;
  };
} // namespace

