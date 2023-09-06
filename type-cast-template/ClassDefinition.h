////////////////////////////////////////////////////////////////////////////////////
///	@author jimin Kim 
///
///	@brief 기본 클래스 정의 매크로 파일
/// 
/// @date 2023.08.09
////////////////////////////////////////////////////////////////////////////////////


#pragma once


////////////////////////////////////////////////////////////////////////////////////
///	@class UClass 
///
///	@brief 클래스 정보 정의 클래스
////////////////////////////////////////////////////////////////////////////////////
class UClass
{
public:
	UClass() = default;
	virtual ~UClass() = default;
	UClass* superUClass;
};

//////////////////////////////////////////////////////////////////////////////////// 
///	@brief Declare Root Class
////////////////////////////////////////////////////////////////////////////////////
#define DECLARE_ROOT_CLASS( TClass )														\
	_DECLARE_CLASS( TClass )																\
																							\
public:																						\
	virtual UClass* GetCurUClass()															\
	{																						\
		return TClass::GetPrivateStaticUClass();											\
	}																						\
																							\
	bool IsA( UClass* baseClass )															\
	{																						\
		if ( nullptr == baseClass )															\
			return false;																	\
																							\
		for ( UClass* tempUClass = GetCurUClass(); ; tempUClass = tempUClass->superUClass )	\
		{																					\
			if ( nullptr == tempUClass )													\
				return false;																\
																							\
			if ( tempUClass == baseClass )													\
				return true;																\
		}																					\
																							\
		return false;																		\
	}																						\
																							\
public:																						\
	static void InitializePrivateStaticUClass##TClass( UClass* curClass )					\
	{																						\
		LinkToSuperUClass( curClass, nullptr );												\
	}																						\
																							\
public:																						\
	template< typename To>																	\
	To* Cast()																				\
	{																						\
		if ( this && this->IsA( To::GetPrivateStaticUClass() ) )							\
			return ( To* )( this );															\
																							\
		return nullptr;																		\
	}																

//////////////////////////////////////////////////////////////////////////////////// 
///	@brief Declare Class 
////////////////////////////////////////////////////////////////////////////////////
#define DECLARE_CLASS( TClass, TSuper )														\
	_DECLARE_CLASS( TClass )																\
																							\
private:																					\
	typedef TSuper SuperClass;																\
																							\
public:																						\
	virtual UClass* GetCurUClass() override													\
	{																						\
		return TClass::GetPrivateStaticUClass();											\
	}																						\
																							\
public:																						\
	static void InitializePrivateStaticUClass##TClass( UClass* curClass )					\
	{																						\
		LinkToSuperUClass( curClass, TSuper::GetPrivateStaticUClass() );					\
	}																						

//////////////////////////////////////////////////////////////////////////////////// 
///	@brief _Declare Class 
////////////////////////////////////////////////////////////////////////////////////
#define _DECLARE_CLASS( TClass )															\
private:																					\
	typedef TClass ThisClass;																\
																							\
private:																					\
	static UClass* privateStaticUClass;														\
																							\
public:																						\
	static UClass* GetPrivateStaticUClass()													\
	{																						\
		if ( !privateStaticUClass )															\
		{																					\
			privateStaticUClass = new UClass();												\
			InitializePrivateStaticUClass##TClass( privateStaticUClass );					\
		}																					\
																							\
		return privateStaticUClass;															\
	}																						\
																							\
	static void LinkToSuperUClass( UClass* childUClass, UClass* parentUClass )				\
	{																						\
		childUClass->superUClass = parentUClass;											\
	}																															

//////////////////////////////////////////////////////////////////////////////////// 
///	@brief Implement Root Class 
////////////////////////////////////////////////////////////////////////////////////
#define IMPLEMENT_ROOT_CLASS( TClass )														\
	_IMPLEMENT_CLASS( TClass )

//////////////////////////////////////////////////////////////////////////////////// 
///	@brief Implement Class 
////////////////////////////////////////////////////////////////////////////////////
#define IMPLEMENT_CLASS( TClass )															\
	_IMPLEMENT_CLASS( TClass )

//////////////////////////////////////////////////////////////////////////////////// 
///	@brief _Implement Class 
////////////////////////////////////////////////////////////////////////////////////
#define _IMPLEMENT_CLASS( TClass )	\
	UClass* TClass::privateStaticUClass = nullptr;
