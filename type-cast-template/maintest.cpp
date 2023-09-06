// type-cast-template.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <chrono>
#include "ClassDefinition.h"

class Parent
{
    DECLARE_ROOT_CLASS( Parent );

public:
    Parent() = default;
    virtual ~Parent() = default;

public:
    virtual void Cout() = 0;
};

class ChildDepth01 : public Parent
{
    DECLARE_CLASS( ChildDepth01, Parent )

public:
    ChildDepth01()
    {
        value = rand();
    }

public:
    void Cout() override
    {
        std::cout << "depth01 : " << value << std::endl;
    }

public:
    long value = 0;
};

class ChildDepth02 : public ChildDepth01
{
    DECLARE_CLASS( ChildDepth02, ChildDepth01 )

public:
    ChildDepth02()
    {
        value = rand();
    }

public:
    void Cout() override
    {
        std::cout << "depth02 : " << value << std::endl;
    }

public:
    long value = 0;
};

class ChildDepth03 : public ChildDepth02
{
    DECLARE_CLASS( ChildDepth03, ChildDepth02 )

public:
    ChildDepth03()
    {
        value = rand();
    }

public:
    void Cout() override
    {
        std::cout << "depth03 : " << value << std::endl;
    }

public:
    long value = 0;
};

class ChildDepth04 : public ChildDepth03
{
    DECLARE_CLASS( ChildDepth04, ChildDepth03 )

public:
    ChildDepth04()
    {
        value = rand();
    }

public:
    void Cout() override
    {
        std::cout << "depth04 : " << value << std::endl;
    }

public:
    long value = 0;
};

class ChildDepth05 : public ChildDepth04
{
    DECLARE_CLASS( ChildDepth05, ChildDepth04 )

public:
    ChildDepth05()
    {
        value = rand();
    }

public:
    void Cout() override
    {
        std::cout << "depth05 : " << value << std::endl;
    }

public:
    long value = 0;
};

class ChildDepth06 : public ChildDepth05
{
    DECLARE_CLASS( ChildDepth06, ChildDepth05 )

public:
    ChildDepth06()
    {
        value = rand();
    }

public:
    void Cout() override
    {
        std::cout << "depth06 : " << value << std::endl;
    }

public:
    long value = 0;
};

class ChildDepth07 : public ChildDepth06
{
    DECLARE_CLASS( ChildDepth07, ChildDepth06 )

public:
    ChildDepth07()
    {
        value = rand();
    }

public:
    void Cout() override
    {
        std::cout << "depth07 : " << value << std::endl;
    }

public:
    long value = 0;
};

class ChildDepth08 : public ChildDepth07
{
    DECLARE_CLASS( ChildDepth08, ChildDepth07 )

public:
    ChildDepth08()
    {
        value = rand();
    }

public:
    void Cout() override
    {
        std::cout << "depth08 : " << value << std::endl;
    }

public:
    long value = 0;
};

class ChildDepth09 : public ChildDepth08
{
    DECLARE_CLASS( ChildDepth09, ChildDepth08 )

public:
    ChildDepth09()
    {
        value = rand();
    }

public:
    void Cout() override
    {
        std::cout << "depth09 : " << value << std::endl;
    }

public:
    long value = 0;
};

class ChildDepth10 : public ChildDepth09
{
    DECLARE_CLASS( ChildDepth10, ChildDepth09 )

public:
    ChildDepth10()
    {
        value = rand();
    }

public:
    void Cout() override
    {
        std::cout << "depth10 : " << value << std::endl;
    }

public:
    long value = 0;
};


IMPLEMENT_ROOT_CLASS( Parent )
IMPLEMENT_CLASS( ChildDepth01 )
IMPLEMENT_CLASS( ChildDepth02 )
IMPLEMENT_CLASS( ChildDepth03 )
IMPLEMENT_CLASS( ChildDepth04 )
IMPLEMENT_CLASS( ChildDepth05 )
IMPLEMENT_CLASS( ChildDepth06 )
IMPLEMENT_CLASS( ChildDepth07 )
IMPLEMENT_CLASS( ChildDepth08 )
IMPLEMENT_CLASS( ChildDepth09 )
IMPLEMENT_CLASS( ChildDepth10 )


using namespace std;
using namespace chrono;

std::vector< Parent* > testParamList;

int vectorSize = 100000000;

void ChildDepth01Test()
{
    testParamList.clear();

    cout << "=============================Depth01=============================" <<endl;

    system_clock::time_point start = system_clock::now();
    for ( int i = 0; i < vectorSize; i++ )
    {
        testParamList.push_back( new ChildDepth01() );
    }
    system_clock::time_point end = system_clock::now();

    cout << "Pushback ChildDepthClass Count : " << testParamList.size() << " Time : " << chrono::duration_cast< chrono::milliseconds >( end - start ).count() <<endl;

    start = system_clock::now();
    long long result = 0;
    for ( int i = 0; i< testParamList.size(); i++ )
    {
        ChildDepth01* childDepth01 = testParamList[ i ]->Cast<ChildDepth01>();
        result += childDepth01->value;
    }
    end = system_clock::now();

    cout << "Cast To Custom type Cast Time : "  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    start = system_clock::now();
    result = 0;
    for ( int i = 0; i < testParamList.size(); i++ )
    {
        ChildDepth01* childDepth01 = dynamic_cast< ChildDepth01* >( testParamList[ i ] );
        result += childDepth01->value;
    }
    end = system_clock::now();

    cout << "Cast To Dynamic Cast Time :"  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    for ( int i = 0; i < testParamList.size(); i++ )
    {
        delete testParamList[ i ];
    }

    testParamList.clear();

    cout << "=================================================================" <<endl;
}

void ChildDepth02Test()
{
    testParamList.clear();

    cout << "=============================Depth02=============================" <<endl;

    system_clock::time_point start = system_clock::now();
    for ( int i = 0; i < vectorSize; i++ )
    {
        testParamList.push_back( new ChildDepth02() );
    }
    system_clock::time_point end = system_clock::now();

    cout << "Pushback ChildDepthClass Count : " << testParamList.size() << " Time : " << chrono::duration_cast< chrono::milliseconds >( end - start ).count() <<endl;

    start = system_clock::now();
    long long result = 0;
    for ( int i = 0; i< testParamList.size(); i++ )
    {
        ChildDepth02* childDepth = testParamList[ i ]->Cast<ChildDepth02>();
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Custom type Cast Time : "  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    start = system_clock::now();
    result = 0;
    for ( int i = 0; i < testParamList.size(); i++ )
    {
        ChildDepth02* childDepth = dynamic_cast< ChildDepth02* >( testParamList[ i ] );
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Dynamic Cast Time :"  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    for ( int i = 0; i < testParamList.size(); i++ )
    {
        delete testParamList[ i ];
    }

    testParamList.clear();

    cout << "=================================================================" <<endl;
}
void ChildDepth03Test()
{
    testParamList.clear();

    cout << "=============================Depth03=============================" <<endl;

    system_clock::time_point start = system_clock::now();
    for ( int i = 0; i < vectorSize; i++ )
    {
        testParamList.push_back( new ChildDepth03() );
    }
    system_clock::time_point end = system_clock::now();

    cout << "Pushback ChildDepthClass Count : " << testParamList.size() << " Time : " << chrono::duration_cast< chrono::milliseconds >( end - start ).count() <<endl;

    start = system_clock::now();
    long long result = 0;
    for ( int i = 0; i< testParamList.size(); i++ )
    {
        ChildDepth03* childDepth = testParamList[ i ]->Cast<ChildDepth03>();
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Custom type Cast Time : "  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    start = system_clock::now();
    result = 0;
    for ( int i = 0; i < testParamList.size(); i++ )
    {
        ChildDepth03* childDepth = dynamic_cast< ChildDepth03* >( testParamList[ i ] );
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Dynamic Cast Time :"  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    for ( int i = 0; i < testParamList.size(); i++ )
    {
        delete testParamList[ i ];
    }

    testParamList.clear();

    cout << "=================================================================" <<endl;
}

void ChildDepth04Test()
{
    testParamList.clear();

    cout << "=============================Depth04=============================" <<endl;

    system_clock::time_point start = system_clock::now();
    for ( int i = 0; i < vectorSize; i++ )
    {
        testParamList.push_back( new ChildDepth04() );
    }
    system_clock::time_point end = system_clock::now();

    cout << "Pushback ChildDepthClass Count : " << testParamList.size() << " Time : " << chrono::duration_cast< chrono::milliseconds >( end - start ).count() <<endl;

    start = system_clock::now();
    long long result = 0;
    for ( int i = 0; i< testParamList.size(); i++ )
    {
        ChildDepth04* childDepth = testParamList[ i ]->Cast<ChildDepth04>();
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Custom type Cast Time : "  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    start = system_clock::now();
    result = 0;
    for ( int i = 0; i < testParamList.size(); i++ )
    {
        ChildDepth04* childDepth = dynamic_cast< ChildDepth04* >( testParamList[ i ] );
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Dynamic Cast Time :"  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    for ( int i = 0; i < testParamList.size(); i++ )
    {
        delete testParamList[ i ];
    }

    testParamList.clear();

    cout << "=================================================================" <<endl;
}
void ChildDepth05Test()
{
    testParamList.clear();

    cout << "=============================Depth05=============================" <<endl;

    system_clock::time_point start = system_clock::now();
    for ( int i = 0; i < vectorSize; i++ )
    {
        testParamList.push_back( new ChildDepth05() );
    }
    system_clock::time_point end = system_clock::now();

    cout << "Pushback ChildDepthClass Count : " << testParamList.size() << " Time : " << chrono::duration_cast< chrono::milliseconds >( end - start ).count() <<endl;

    start = system_clock::now();
    long long result = 0;
    for ( int i = 0; i< testParamList.size(); i++ )
    {
        ChildDepth05* childDepth = testParamList[ i ]->Cast<ChildDepth05>();
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Custom type Cast Time : "  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    start = system_clock::now();
    result = 0;
    for ( int i = 0; i < testParamList.size(); i++ )
    {
        ChildDepth05* childDepth = dynamic_cast< ChildDepth05* >( testParamList[ i ] );
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Dynamic Cast Time :"  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    for ( int i = 0; i < testParamList.size(); i++ )
    {
        delete testParamList[ i ];
    }

    testParamList.clear();

    cout << "=================================================================" <<endl;
}
void ChildDepth06Test()
{
    testParamList.clear();

    cout << "=============================Depth06=============================" <<endl;

    system_clock::time_point start = system_clock::now();
    for ( int i = 0; i < vectorSize; i++ )
    {
        testParamList.push_back( new ChildDepth06() );
    }
    system_clock::time_point end = system_clock::now();

    cout << "Pushback ChildDepthClass Count : " << testParamList.size() << " Time : " << chrono::duration_cast< chrono::milliseconds >( end - start ).count() <<endl;

    start = system_clock::now();
    long long result = 0;
    for ( int i = 0; i< testParamList.size(); i++ )
    {
        ChildDepth06* childDepth = testParamList[ i ]->Cast<ChildDepth06>();
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Custom type Cast Time : "  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    start = system_clock::now();
    result = 0;
    for ( int i = 0; i < testParamList.size(); i++ )
    {
        ChildDepth06* childDepth = dynamic_cast< ChildDepth06* >( testParamList[ i ] );
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Dynamic Cast Time :"  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    for ( int i = 0; i < testParamList.size(); i++ )
    {
        delete testParamList[ i ];
    }

    testParamList.clear();

    cout << "=================================================================" <<endl;

}

void ChildDepth07Test()
{
    testParamList.clear();

    cout << "=============================Depth07=============================" <<endl;

    system_clock::time_point start = system_clock::now();
    for ( int i = 0; i < vectorSize; i++ )
    {
        testParamList.push_back( new ChildDepth07() );
    }
    system_clock::time_point end = system_clock::now();

    cout << "Pushback ChildDepthClass Count : " << testParamList.size() << " Time : " << chrono::duration_cast< chrono::milliseconds >( end - start ).count() <<endl;

    start = system_clock::now();
    long long result = 0;
    for ( int i = 0; i< testParamList.size(); i++ )
    {
        ChildDepth07* childDepth = testParamList[ i ]->Cast<ChildDepth07>();
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Custom type Cast Time : "  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    start = system_clock::now();
    result = 0;
    for ( int i = 0; i < testParamList.size(); i++ )
    {
        ChildDepth07* childDepth = dynamic_cast< ChildDepth07* >( testParamList[ i ] );
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Dynamic Cast Time :"  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    for ( int i = 0; i < testParamList.size(); i++ )
    {
        delete testParamList[ i ];
    }

    testParamList.clear();

    cout << "=================================================================" <<endl;

}

void ChildDepth08Test()
{
    testParamList.clear();

    cout << "=============================Depth08=============================" <<endl;

    system_clock::time_point start = system_clock::now();
    for ( int i = 0; i < vectorSize; i++ )
    {
        testParamList.push_back( new ChildDepth08() );
    }
    system_clock::time_point end = system_clock::now();

    cout << "Pushback ChildDepthClass Count : " << testParamList.size() << " Time : " << chrono::duration_cast< chrono::milliseconds >( end - start ).count() <<endl;

    start = system_clock::now();
    long long result = 0;
    for ( int i = 0; i< testParamList.size(); i++ )
    {
        ChildDepth08* childDepth = testParamList[ i ]->Cast<ChildDepth08>();
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Custom type Cast Time : "  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    start = system_clock::now();
    result = 0;
    for ( int i = 0; i < testParamList.size(); i++ )
    {
        ChildDepth08* childDepth = dynamic_cast< ChildDepth08* >( testParamList[ i ] );
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Dynamic Cast Time :"  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    for ( int i = 0; i < testParamList.size(); i++ )
    {
        delete testParamList[ i ];
    }

    testParamList.clear();

    cout << "=================================================================" <<endl;

}

void ChildDepth09Test()
{

    testParamList.clear();

    cout << "=============================Depth09=============================" <<endl;

    system_clock::time_point start = system_clock::now();
    for ( int i = 0; i < vectorSize; i++ )
    {
        testParamList.push_back( new ChildDepth09() );
    }
    system_clock::time_point end = system_clock::now();

    cout << "Pushback ChildDepthClass Count : " << testParamList.size() << " Time : " << chrono::duration_cast< chrono::milliseconds >( end - start ).count() <<endl;

    start = system_clock::now();
    long long result = 0;
    for ( int i = 0; i< testParamList.size(); i++ )
    {
        ChildDepth09* childDepth = testParamList[ i ]->Cast<ChildDepth09>();
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Custom type Cast Time : "  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    start = system_clock::now();
    result = 0;
    for ( int i = 0; i < testParamList.size(); i++ )
    {
        ChildDepth09* childDepth = dynamic_cast< ChildDepth09* >( testParamList[ i ] );
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Dynamic Cast Time :"  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    for ( int i = 0; i < testParamList.size(); i++ )
    {
        delete testParamList[ i ];
    }

    testParamList.clear();

    cout << "=================================================================" <<endl;
}

void ChildDepth10Test()
{
    testParamList.clear();

    cout << "=============================Depth10=============================" <<endl;

    system_clock::time_point start = system_clock::now();
    for ( int i = 0; i < vectorSize; i++ )
    {
        testParamList.push_back( new ChildDepth10() );
    }
    system_clock::time_point end = system_clock::now();

    cout << "Pushback ChildDepthClass Count : " << testParamList.size() << " Time : " << chrono::duration_cast< chrono::milliseconds >( end - start ).count() <<endl;

    start = system_clock::now();
    long long result = 0;
    for ( int i = 0; i< testParamList.size(); i++ )
    {
        ChildDepth10* childDepth = testParamList[ i ]->Cast<ChildDepth10>();
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Custom type Cast Time : "  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    start = system_clock::now();
    result = 0;
    for ( int i = 0; i < testParamList.size(); i++ )
    {
        ChildDepth10* childDepth = dynamic_cast< ChildDepth10* >( testParamList[ i ] );
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Dynamic Cast Time :"  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    for ( int i = 0; i < testParamList.size(); i++ )
    {
        delete testParamList[ i ];
    }

    testParamList.clear();

    cout << "=================================================================" <<endl;
}

void ChildDepth10Test_FindMidle()
{
    testParamList.clear();

    cout << "=============================Depth10_Find_Depth05=============================" <<endl;

    system_clock::time_point start = system_clock::now();
    for ( int i = 0; i < vectorSize; i++ )
    {
        testParamList.push_back( new ChildDepth10() );
    }
    system_clock::time_point end = system_clock::now();

    cout << "Pushback ChildDepthClass Count : " << testParamList.size() << " Time : " << chrono::duration_cast< chrono::milliseconds >( end - start ).count() <<endl;
    start = system_clock::now();
    long long result = 0;
    for ( int i = 0; i< testParamList.size(); i++ )
    {
        ChildDepth05* childDepth = testParamList[ i ]->Cast<ChildDepth05>();
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Custom type Cast Time : "  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    start = system_clock::now();
    result = 0;
    for ( int i = 0; i < testParamList.size(); i++ )
    {
        ChildDepth05* childDepth = dynamic_cast< ChildDepth05* >( testParamList[ i ] );
        result += childDepth->value;
    }
    end = system_clock::now();

    cout << "Cast To Dynamic Cast Time :"  << chrono::duration_cast< chrono::milliseconds >( end - start ).count() << " ResultValue :" << result << endl;

    for ( int i = 0; i < testParamList.size(); i++ )
    {
        delete testParamList[ i ];
    }

    testParamList.clear();

    cout << "=================================================================" <<endl;
}

int main()
{
    ChildDepth10Test();
    ChildDepth01Test();
    ChildDepth10Test_FindMidle();

    ChildDepth01Test();
    ChildDepth02Test();
    ChildDepth03Test();
    ChildDepth04Test();
    ChildDepth05Test();
    ChildDepth06Test();
    ChildDepth07Test();
    ChildDepth08Test();
    ChildDepth09Test();
    ChildDepth10Test();
    ChildDepth10Test_FindMidle();
    return 0;
}


