#pragma once

template <typename TInput, typename TExpected>
struct TestCase
{
    TInput input;
    TExpected expected;
};
