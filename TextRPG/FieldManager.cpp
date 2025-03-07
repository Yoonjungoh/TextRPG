
#include "FieldManager.h"=

FieldManager::FieldManager()
    :_fieldType(FieldType::None),
    _validFieldTypeSet
    {
          static_cast<int>(FieldType::Lobby),
          static_cast<int>(FieldType::Village),
          static_cast<int>(FieldType::Forest),
          static_cast<int>(FieldType::Battle) 
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
    // 필드 타입 유효성 체크 실행하기
    if (_validFieldTypeSet.find(fieldTypeInt) == _validFieldTypeSet.end())
    {
        _fieldType = FieldType::None;
        return;
    }

    FieldType fieldType = static_cast<FieldType>(fieldTypeInt);
    SetFieldType(fieldType);
}

void FieldManager::SetFieldType(FieldType fieldType)
{
    _fieldType = fieldType;
}
