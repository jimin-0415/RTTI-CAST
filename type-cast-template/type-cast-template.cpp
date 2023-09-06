// type-cast-template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


class UClass
{
public:
    UClass() : SuperClass( nullptr ) { }
    virtual ~UClass() { }
    UClass* SuperClass;

private:

};

//class Parent
//{
//private:
//    typedef Parent ThisClass;
//
//public:
//    static UClass* uClass;
//    
//    virtual UClass* GetCurClass() const
//    {
//        return Parent::GetStaticClass();
//    }
//
//    static UClass* GetStaticClass()
//    {
//        if ( !uClass )
//        {
//            uClass = new UClass();
//            InitializeStaticClass( uClass );
//        }
//        return uClass;
//    }
//
//    static void InitializeStaticClass(UClass* curClass)
//    {
//        LinkingUClass( curClass, nullptr );
//    }
//
// 
//    //// 공용
//    static void LinkingUClass( UClass* child, UClass* parent )
//    {
//        child->SuperClass = parent;
//    }
//
//    // 공용
//    bool IsA( UClass* someBase )
//    {
//        if ( someBase == nullptr )
//            return true;
//
//        for ( UClass* tempClass = GetCurClass(); ; tempClass = tempClass->SuperClass )
//        {
//            if ( tempClass == nullptr )
//                return true;
//
//            if ( tempClass == someBase )
//                return true;
//        }
//        return false;
//    }
//};
//
//UClass* Parent::uClass = nullptr;
//
//class Child : public Parent
//{
//private:
//    typedef Parent SuperClass;
//    typedef Child  ThisClass;
//
//public:
//    Child() = default;
//    virtual ~Child() = default;
//
//public:
//   static UClass* CurClass;
//
//   virtual UClass* GetCurClass() const override
//   {
//       return Child::GetStaticClass();
//   }
//   
//   static UClass* GetStaticClass()
//   {
//       if ( !uClass )
//       {
//           uClass = new UClass();
//           InitializeStaticClass( uClass );
//       }
//       return uClass;
//   }
//
//   static void InitializeStaticClass( UClass* curClass )
//   {
//       LinkingUClass( curClass, Child::SuperClass::GetStaticClass() );
//   }
//
//public:
//    int m_value = 23523525;
//};
//
//UClass* Child::CurClass = nullptr;
//
//template<typename To, typename From>
//To* Cast( From* src )
//{
//    if ( !src )
//        return nullptr;
//    
//    return src->IsA( To::GetStaticClass() ) ? ( To* )( src ) : nullptr;
//}


//int main()
//{
//    Parent* parent = new Child();
//    
//
//    Child* child = Cast<Child>( parent );
//    if ( child )
//    {
//        std::cout << child->m_value;
//    }
//
//    return 0;
//}
