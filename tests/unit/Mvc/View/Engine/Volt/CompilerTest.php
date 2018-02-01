<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Unit\Mvc\View\Engine\Volt;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Tag;
use Phalcon\Test\Module\UnitTest;

/**
 * Phalcon\Test\Unit\Mvc\View\Engine\Volt\CompilerTest
 *
 * Test VOLT template engine
 *
 * @package Phalcon\Test\Unit\Mvc\View\Engine\Volt
 */
class CompilerTest extends UnitTest
{
    /**
     * @var Compiler
     */
    protected $volt;

    /**
     * executed before each test
     */
    protected function _before()
    {
        $this->volt = new Compiler();
    }

    /**
     * executed after each test
     */
    protected function _after()
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(Tag::XHTML5);
    }

    /**
     * Tests Compiler::parse
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldReturnArrayParseFunction()
    {
        $this->specify(
            "Volt parser doesn't work as expected",
            function ($param, $count) {
                $intermediate = $this->volt->parse($param);

                expect(is_array($intermediate))->true();
                expect($intermediate)->count($count);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'volt/compilerTest/test_volt_parser.php'
            ]
        );
    }

    /**
     * Tests Compiler::compileString
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shoulrReturnCompiledString()
    {
        $this->specify(
            "Volt parser doesn't work as expected",
            function ($param, $expect) {
                $compilation = $this->volt->compileString($param);

                expect($compilation)->equals($expect);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'volt/compilerTest/volt_compile_string_equals.php'
            ]
        );
    }

    /**
     * Tests Compiler::compileString with option autoescape from options
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldEscapeStringFromOption()
    {
        $this->specify(
            "Volt parser doesn't work as expected",
            function ($param, $expect) {
                $this->volt->setOption("autoescape", true);

                $compilation = $this->volt->compileString($param);

                expect($compilation)->equals($expect);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'volt/compilerTest/volt_compile_string_autoescape.php'
            ]
        );
    }

    /**
     * Tests Compiler::addFunction test case linear function
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldReturnSingleStringFunction()
    {
        $this->specify(
            'Custom functions should work',
            function ($name, $funcName, $voltName, $result) {
                $this->volt->addFunction($name, $funcName);
                $compilation = $this->volt->compileString($voltName);

                expect($compilation)->equals($result);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'volt/compilerTest/volt_users_single_string_function.php'
            ]
        );
    }

    /**
     * Tests Compiler::addFunction test case with closure
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldReturnFunctionWithOneArgument()
    {
        $this->specify(
            'Custom functions with one argument should work',
            function ($name, $funcName, $voltName, $result) {
                $this->volt->addFunction($name, function ($arguments) use ($funcName) {
                    return $funcName . '(' . $arguments . ')';
                });
                $compilation = $this->volt->compileString($voltName);

                expect($compilation)->equals($result);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'volt/compilerTest/volt_users_function_with_closure.php'
            ]
        );
    }

    /**
     * Tests Compiler::addFilter test case linear filter
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldReturnStringWithAddedSingleStringFilter()
    {
        $this->specify(
            "Custom linear filters should work",
            function ($name, $filter, $voltName, $result) {
                $this->volt->addFilter($name, $filter);
                $compilation = $this->volt->compileString($voltName);

                expect($compilation)->equals($result);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'volt/compilerTest/volt_single_filter.php'
            ]
        );
    }

    /**
     * Tests Compiler::addFilter test case with closure filter
     *
     * @test
     * @issue  -
     * @author Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>
     * @since  2017-01-17
     */
    public function shouldReturnStringWithAddedFilterWithClosure()
    {
        $this->specify(
            "Custom linear filters should work",
            function ($name, $filter, $voltName, $result) {
                $this->volt->addFilter($name, function ($arguments) use ($filter) {
                    return $filter . '(",", '.$arguments.')';
                });
                $compilation = $this->volt->compileString($voltName);

                expect($compilation)->equals($result);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'volt/compilerTest/volt_closure_filter.php'
            ]
        );
    }
}
