/***********************************************************************************************************************
 *  OpenStudio(R), Copyright (c) 2008-2017, Alliance for Sustainable Energy, LLC. All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 *  following conditions are met:
 *
 *  (1) Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 *  disclaimer.
 *
 *  (2) Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *  following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *  (3) Neither the name of the copyright holder nor the names of any contributors may be used to endorse or promote
 *  products derived from this software without specific prior written permission from the respective party.
 *
 *  (4) Other than as required in clauses (1) and (2), distributions in any form of modifications or other derivative
 *  works may not use the "OpenStudio" trademark, "OS", "os", or any other confusingly similar designation without
 *  specific prior written permission from Alliance for Sustainable Energy, LLC.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER, THE UNITED STATES GOVERNMENT, OR ANY CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 *  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 **********************************************************************************************************************/

#ifndef MODEL_MATERIALPROPERTYMOISTUREPENETRATIONDEPTHSETTINGS_IMPL_HPP
#define MODEL_MATERIALPROPERTYMOISTUREPENETRATIONDEPTHSETTINGS_IMPL_HPP

#include "ModelAPI.hpp"
#include "ResourceObject_Impl.hpp"

namespace openstudio {
namespace model {

namespace detail {

  /** MaterialPropertyMoisturePenetrationDepthSettings_Impl is a ResourceObject_Impl that is the implementation class for MaterialPropertyMoisturePenetrationDepthSettings.*/
  class MODEL_API MaterialPropertyMoisturePenetrationDepthSettings_Impl : public ResourceObject_Impl {
  
  public:

    /** @name Constructors and Destructors */
    //@{

    MaterialPropertyMoisturePenetrationDepthSettings_Impl(const IdfObject& idfObject,
                                                          Model_Impl* model,
                                                          bool keepHandle);

    MaterialPropertyMoisturePenetrationDepthSettings_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                          Model_Impl* model,
                                                          bool keepHandle);

    MaterialPropertyMoisturePenetrationDepthSettings_Impl(const MaterialPropertyMoisturePenetrationDepthSettings_Impl& other,
                                                          Model_Impl* model,
                                                          bool keepHandle);

    virtual ~MaterialPropertyMoisturePenetrationDepthSettings_Impl() {}

    //@}
    /** @name Virtual Methods */
    //@{

    virtual const std::vector<std::string>& outputVariableNames() const;

    virtual IddObjectType iddObjectType() const;

    //@}
    /** @name Getters */
    //@{

    double waterVaporDiffusionResistanceFactor() const;

    double moistureEquationCoefficientA() const;

    double moistureEquationCoefficientB() const;

    double moistureEquationCoefficientC() const;

    double moistureEquationCoefficientD() const;
    
    std::vector<double> moistureEquationCoefficients() const;

    boost::optional<double> surfaceLayerPenetrationDepth();

    bool isSurfaceLayerPenetrationDepthAutocalculated();

    boost::optional<double> deepLayerPenetrationDepth();

    bool isDeepLayerPenetrationDepthAutocalculated();

    double coatingLayerThickness() const;

    double coatingLayerWaterVaporDiffusionResistanceFactor() const;

    //@}
    /** @name Setters */
    //@{

    void setWaterVaporDiffusionResistanceFactor(double waterVaporDiffusionResistanceFactor);

    void setMoistureEquationCoefficientA(double moistureEquationCoefficientA);

    void setMoistureEquationCoefficientB(double moistureEquationCoefficientB);

    void setMoistureEquationCoefficientC(double moistureEquationCoefficientC);

    void setMoistureEquationCoefficientD(double moistureEquationCoefficientD);
    
    void setMoistureEquationCoefficients(double moistureEquationCoefficientA, double moistureEquationCoefficientB, double moistureEquationCoefficientC, double moistureEquationCoefficientD);

    void setSurfaceLayerPenetrationDepth(double value);

    void autocalculateSurfaceLayerPenetrationDepth();

    void setDeepLayerPenetrationDepth(double value);

    void autocalculateDeepLayerPenetrationDepth();

    void setCoatingLayerThickness(double coatingLayerThickness);

    void setCoatingLayerWaterVaporDiffusionResistanceFactor(double coatingLayerWaterVaporDiffusionResistanceFactor);

    //@}
    /** @name Other */
    //@{

    //@}
   protected:
   private:
    REGISTER_LOGGER("openstudio.model.MaterialPropertyMoisturePenetrationDepthSettings");
  };

} // detail

} // model
} // openstudio

#endif // MODEL_MATERIALPROPERTYMOISTUREPENETRATIONDEPTHSETTINGS_IMPL_HPP