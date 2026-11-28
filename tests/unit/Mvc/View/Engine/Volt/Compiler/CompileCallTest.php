<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt\Compiler;

use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Mvc\View\Engine\Volt\Exceptions\CallNotSupported;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

class CompileCallTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcViewEngineVoltCompilerCompileCall(): void
    {
        $compiler = new Compiler();

        $this->expectException(CallNotSupported::class);
        $this->expectExceptionMessage(
            "The 'call' statement is not supported in index.volt on line 3"
        );

        $compiler->compileCall(
            [
                'file' => 'index.volt',
                'line' => 3,
            ],
            false
        );
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17676
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-19
     */
    public function testMvcViewEngineVoltCompilerCompileCallFromString(): void
    {
        $compiler = new Compiler();

        $this->expectException(CallNotSupported::class);
        $this->expectExceptionMessage(
            "The 'call' statement is not supported in eval code on line 1"
        );

        $compiler->compileString('{% call m(1) %}BODY{% endcall %}');
    }
}
