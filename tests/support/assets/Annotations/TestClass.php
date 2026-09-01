<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

/**
 * TestClass
 *
 * This is a test class, it's useful to make tests
 *
 * @Simple
 * @SingleParam("Param")
 * @MultipleParams("First", Second, 1, 1.1, -10, false, true, null)
 * @Params({"key1", "key2", "key3"});
 * @HashParams({"key1": "value", "key2": "value", "key3": "value"});
 * @NamedParams(first=some, second=other);
 * @AlternativeNamedParams(first: some, second: other);
 * @AlternativeHashParams({key1="value", "key2"=value, "key3"="value"});
 * @RecursiveHash({key1="value", "key2"=value, "key3"=[1, 2, 3, 4]});
 */
class TestClass
{
    /**
     * @Simple
     */
    const TEST_CONST1 = 'test-const-with-annotation';

    const TEST_CONST2 = 'test-const-without-annotation';

    /**
     * This is a property string
     *
     * @var string
     * @Simple
     * @SingleParam("Param")
     * @MultipleParams("First", Second, 1, 1.1, -10, false, true, null)
     */
    public $testProp1;

    /**
     *
     */
    public $testProp2;

    /**
     * @Simple @SingleParam("Param") @MultipleParams("First", Second, 1, 1.1,
     *         -10, false, true, null)
     */
    public $testProp3;

    /**
     * @Simple @SingleParam(
     * "Param") @MultipleParams(         "First",
     * Second, 1,    1.1
     * ,-10,
     * false,    true,
     * null)
     */
    public $testProp4;

    public $testProp5;

    /**
     * This is a comment
     */
    public $testProp6;

    /**
     * This is a property string
     *
     * @return string
     * @Simple
     * @SingleParam("Param")
     * @MultipleParams("First", Second, 1, 1.1, -10, false, true, null)
     * @NamedMultipleParams(first: "First", second: Second)
     */
    public function testMethod1()
    {
    }

    /**
     *
     */
    public function testMethod2()
    {
    }

    /**
     * @Simple @SingleParam("Param") @MultipleParams("First", Second, 1, 1.1,
     *         -10, false, true, null)
     */
    public function testMethod3()
    {
    }

    /**
     * @Simple @SingleParam(
     * "Param") @MultipleParams(         "First",
     * Second, 1,    1.1
     * ,-10,
     * false,    true,
     * null)
     */
    public function testMethod4()
    {
    }

    /** @Simple a good comment between annotations @SingleParam(
     * "Param") this is extra content @MultipleParams(         "First",
     * Second, 1,    1.1  ,-10,
     * false,    true,
     * null) more content here
     */
    public function testMethod5()
    {
    }
}
