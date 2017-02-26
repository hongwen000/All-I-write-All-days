#include <string>
#include <experimental/optional>
#include <iostream>
using namespace std;
struct sanitized { };
struct unsanitized { };
template <typename T>
class FormData {
    public:
        explicit
        FormData(const string& input) : m_input(input) { }
        FormData<unsanitized> operator+=(const string& input)
        {
            m_input += input;
            return *this;
        }
        const string getData() const
        {
            return m_input;
        }
    private:
        string m_input;
};
FormData<unsanitized> GetFormData()
{
    FormData<unsanitized> data("unsanitized data");
    return data;
}
experimental::optional<FormData<sanitized>>
SantizeFormData(FormData<unsanitized> data)
{
    if(!data.getData().empty()) {
        data += string(" now santized");
        FormData<sanitized> sanitized_data (data.getData());
        return sanitized_data;
    }
    else 
        return { };
}
const string ExecuteQuery(const FormData<sanitized> data)
{
    return data.getData();
}
//int main()
//{
//    if(experimental::optional<FormData<sanitized>> date_sanitized = SantizeFormData(GetFormData()))
//        ExecuteQuery(*date_sanitized);
//    return 0;
//}
#include "test.h"
TEST_CASE( "TRY!", "[ExecuteQuery]" ) {
    REQUIRE( ExecuteQuery( *SantizeFormData(GetFormData())) == "unsanitized data now santized");
} 
