#pragma once

#include "Singleton.h"
#include <unordered_set>

enum class FieldType
{
    None,
    Lobby,
    Village,
    Forest,
    Battle,
};

class FieldManager : public Singleton<FieldManager>
{
public:
    FieldType GetFieldType();

    void SetFieldType(int fieldTypeInt);
    void SetFieldType(FieldType fieldType);

private:
    friend class Singleton<FieldManager>;

    FieldManager();
    ~FieldManager();

    const std::unordered_set<FieldType> _validFieldTypeSet;
    FieldType _fieldType;
};