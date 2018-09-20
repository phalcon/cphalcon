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
use Phalcon\Mvc\View\Exception;
use Phalcon\Test\Module\UnitTest;

/**
 * Phalcon\Test\Unit\Mvc\View\Engine\Volt\CompilerExceptionsTest
 *
 * Test VOLT template engine's exceptions
 *
 * @package Phalcon\Test\Unit\Mvc\View\Engine\Volt
 */
class CompilerExceptionsTest extends UnitTest
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
     * Tests Compiler::parse
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
     * @since  2017-01-15
     */
    public function shouldThrowExceptionParseFunction()
    {
        $volt = $this->volt;
        $this->specify(
            "Volt parser doesn't throw the proper syntax error",
            function ($code, $message) use ($volt) {
                $this->expectException(Exception::class);
                $this->expectExceptionMessage($message);

                $volt->parse($code);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'volt/compilerExceptionsTest/volt_syntax_error.php'
            ]
        );
    }

    /**
     * Tests Compiler::compileString
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
     * @since  2017-01-15
     *
     */

    public function shouldThrowExceptionCompileStringFunction()
    {
        $volt = $this->volt;
        $this->specify(
            "Volt parser doesn't throw the proper runtime error",
            function ($code, $message) use ($volt) {
                $this->expectException(Exception::class);
                $this->expectExceptionMessage($message);

                $volt->compileString($code);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'volt/compilerExceptionsTest/volt_compile_string.php'
            ]
        );
    }

    /**
     * Tests Compiler::parse
     *
     * @test
     * @author Sergii Svyrydenko <sergey.v.svyrydenko@gmail.com>
     * @since  2017-01-15
     */
    public function testVoltExtendsError()
    {
        $volt = $this->volt;
        $this->specify(
            "Volt parser doesn't throw the proper extends error",
            function ($code, $message) use ($volt) {
                $this->expectException(Exception::class);
                $this->expectExceptionMessage($message);

                $volt->parse($code);
            },
            [
                'examples' => include_once PATH_FIXTURES . 'volt/compilerExceptionsTest/volt_extends_error.php'
            ]
        );
    }
}
