<?php
/**
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
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
     * @Simple @SingleParam("Param") @MultipleParams("First", Second, 1, 1.1, -10, false, true, null)
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
     * @Simple @SingleParam("Param") @MultipleParams("First", Second, 1, 1.1, -10, false, true, null)
     */
    public function testMethod3()
    {
    }

    /**
     @Simple @SingleParam(
     "Param") @MultipleParams(         "First",
     Second, 1,    1.1
     ,-10,
     false,    true,
     null)
     */
    public function testMethod4()
    {
    }

/** @Simple a good comment between annotations @SingleParam(
"Param") this is extra content @MultipleParams(         "First",
 Second, 1,    1.1  ,-10,
     false,    true,
null) more content here */
    public function testMethod5()
    {
    }
}
