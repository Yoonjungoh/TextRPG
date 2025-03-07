
#include "FieldManager.h"=

FieldManager::FieldManager()
    :_fieldType(FieldType::None),
    _validFieldTypeSet
    {
        FieldType::Lobby,
        FieldType::Village,
        FieldType::Forest,
        FieldType::Battle
    }
{

}

FieldManager::~FieldManager()
{

}

FieldType FieldManager::GetFieldType()
{
    return _fieldType;
}

void FieldManager::SetFieldType(int fieldTypeInt)
{
    FieldType fieldType = static_cast<FieldType>(fieldTypeInt);
    
    // 필드 타입 유효성 체크 실행하기
    if (_validFieldTypeSet.find(fieldType) == _validFieldTypeSet.end())
    {
        _fieldType = FieldType::None;
        return;
    }

    SetFieldType(fieldType);
}

void FieldManager::SetFieldType(FieldType fieldType)
{
    _fieldType = fieldType;
}
