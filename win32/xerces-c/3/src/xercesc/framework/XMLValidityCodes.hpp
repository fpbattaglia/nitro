// This file is generated, don't edit it!!

#if !defined(XERCESC_INCLUDE_GUARD_ERRHEADER_XMLValid)
#define XERCESC_INCLUDE_GUARD_ERRHEADER_XMLValid

#include <xercesc/framework/XMLErrorReporter.hpp>
#include <xercesc/util/XercesDefs.hpp>
#include <xercesc/dom/DOMError.hpp>

XERCES_CPP_NAMESPACE_BEGIN

class XMLValid
{
public :
    enum Codes
    {
        NoError                            = 0
      , E_LowBounds                        = 1
      , ElementNotDefined                  = 2
      , AttNotDefined                      = 3
      , NotationNotDeclared                = 4
      , RootElemNotLikeDocType             = 5
      , RequiredAttrNotProvided            = 6
      , ElementNotValidForContent          = 7
      , BadIDAttrDefType                   = 8
      , InvalidEmptyAttValue               = 9
      , ElementAlreadyExists               = 10
      , MultipleIdAttrs                    = 11
      , ReusedIDValue                      = 12
      , IDNotDeclared                      = 13
      , UnknownNotRefAttr                  = 14
      , UndeclaredElemInDocType            = 15
      , EmptyNotValidForContent            = 16
      , AttNotDefinedForElement            = 17
      , BadEntityRefAttr                   = 18
      , UnknownEntityRefAttr               = 19
      , ColonNotValidWithNS                = 20
      , NotEnoughElemsForCM                = 21
      , NoCharDataInCM                     = 22
      , DoesNotMatchEnumList               = 23
      , AttrValNotName                     = 24
      , NoMultipleValues                   = 25
      , NotSameAsFixedValue                = 26
      , RepElemInMixed                     = 27
      , FeatureUnsupported                 = 28
      , GroupContentRestricted             = 29
      , UnknownBaseDatatype                = 30
      , NoContentForRef                    = 31
      , DatatypeError                      = 32
      , ProhibitedAttributePresent         = 33
      , IllegalXMLSpace                    = 34
      , WrongTargetNamespace               = 35
      , SimpleTypeHasChild                 = 36
      , NoDatatypeValidatorForSimpleType   = 37
      , GrammarNotFound                    = 38
      , DisplayErrorMessage                = 39
      , NillNotAllowed                     = 40
      , NilAttrNotEmpty                    = 41
      , FixedDifferentFromActual           = 42
      , NoDatatypeValidatorForAttribute    = 43
      , GenericError                       = 44
      , ElementNotQualified                = 45
      , ElementNotUnQualified              = 46
      , VC_IllegalRefInStandalone          = 47
      , NoDefAttForStandalone              = 48
      , NoAttNormForStandalone             = 49
      , NoWSForStandalone                  = 50
      , VC_EntityNotFound                  = 51
      , PartialMarkupInPE                  = 52
      , DatatypeValidationFailure          = 53
      , UniqueParticleAttributionFail      = 54
      , NoAbstractInXsiType                = 55
      , NoDirectUseAbstractElement         = 56
      , NoUseAbstractType                  = 57
      , BadXsiType                         = 58
      , NonDerivedXsiType                  = 59
      , NoSubforBlock                      = 60
      , AttributeNotQualified              = 61
      , AttributeNotUnQualified            = 62
      , IC_FieldMultipleMatch              = 63
      , IC_UnknownField                    = 64
      , IC_AbsentKeyValue                  = 65
      , IC_KeyNotEnoughValues              = 66
      , IC_KeyMatchesNillable              = 67
      , IC_DuplicateUnique                 = 68
      , IC_DuplicateKey                    = 69
      , IC_KeyRefOutOfScope                = 70
      , IC_KeyNotFound                     = 71
      , NonWSContent                       = 72
      , EmptyElemNotationAttr              = 73
      , EmptyElemHasContent                = 74
      , ElemOneNotationAttr                = 75
      , AttrDupToken                       = 76
      , ElemChildrenHasInvalidWS           = 77
      , E_HighBounds                       = 78
      , W_LowBounds                        = 79
      , W_HighBounds                       = 80
      , F_LowBounds                        = 81
      , F_HighBounds                       = 82
    };

    static bool isFatal(const XMLValid::Codes toCheck)
    {
        return ((toCheck >= F_LowBounds) && (toCheck <= F_HighBounds));
    }

    static bool isWarning(const XMLValid::Codes toCheck)
    {
        return ((toCheck >= W_LowBounds) && (toCheck <= W_HighBounds));
    }

    static bool isError(const XMLValid::Codes toCheck)
    {
        return ((toCheck >= E_LowBounds) && (toCheck <= E_HighBounds));
    }

    static XMLErrorReporter::ErrTypes errorType(const XMLValid::Codes toCheck)
    {
       if ((toCheck >= W_LowBounds) && (toCheck <= W_HighBounds))
           return XMLErrorReporter::ErrType_Warning;
       else if ((toCheck >= F_LowBounds) && (toCheck <= F_HighBounds))
            return XMLErrorReporter::ErrType_Fatal;
       else if ((toCheck >= E_LowBounds) && (toCheck <= E_HighBounds))
            return XMLErrorReporter::ErrType_Error;
       return XMLErrorReporter::ErrTypes_Unknown;
    }
    static DOMError::ErrorSeverity  DOMErrorType(const XMLValid::Codes toCheck)
    {
       if ((toCheck >= W_LowBounds) && (toCheck <= W_HighBounds))
           return DOMError::DOM_SEVERITY_WARNING;
       else if ((toCheck >= F_LowBounds) && (toCheck <= F_HighBounds))
            return DOMError::DOM_SEVERITY_FATAL_ERROR;
       else return DOMError::DOM_SEVERITY_ERROR;
    }

private:
    // -----------------------------------------------------------------------
    //  Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    XMLValid();
};

XERCES_CPP_NAMESPACE_END

#endif

