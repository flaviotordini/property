#ifndef PROPERTY_H
#define PROPERTY_H

/// Inspired by https://kuanyui.github.io/2017/08/16/macros-for-qproperty/

// clang-format off

#define PROPERTY_INTERNAL(Type, Name, Getter, Setter, DefaultValue, writeSetter)\
    public:\
        Type Getter() const { return Name ; }\
    public Q_SLOTS:\
        void Setter(Type value) {\
        if (Name == value) { return; }\
        Name = value;\
        emit Name##Changed(Name);}\
    Q_SIGNALS:\
        void Name##Changed(Type Name);\
    private:\
        Q_PROPERTY(Type Name READ Getter writeSetter NOTIFY Name##Changed);\
        Type Name DefaultValue;

// rw property
#define PROPERTY(Type, Name, Getter, Setter)\
    PROPERTY_INTERNAL(Type, Name, Getter, Setter, , WRITE Setter)

// rw property with default value
#define PROPERTY_DEFAULT(Type, Name, Getter, Setter, DefaultValue)\
    PROPERTY_INTERNAL(Type, Name, Getter, Setter, = DefaultValue, WRITE Setter)

// ro property
#define PROPERTY_RO(Type, Name, Getter, Setter)\
    PROPERTY_INTERNAL(Type, Name, Getter, Setter, , )

// ro property with default value
#define PROPERTY_RO_DEFAULT(Type, Name, Getter, Setter, DefaultValue)\
    PROPERTY_INTERNAL(Type, Name, Getter, Setter, = DefaultValue, )

// clang-format on

#endif // PROPERTY_H
