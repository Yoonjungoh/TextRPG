
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
    
    // �ʵ� Ÿ�� ��ȿ�� üũ �����ϱ�
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
