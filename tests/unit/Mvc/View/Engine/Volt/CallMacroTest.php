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

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use Phalcon\Mvc\View\Engine\Volt;
use Phalcon\Mvc\View\Engine\Volt\Compiler;
use Phalcon\Mvc\View\Simple;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use TypeError;

class CallMacroTest extends AbstractUnitTestCase
{
    /**
     * A null macro throws the TypeError of call_user_func(), the same as
     * cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/821
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-17
     */
    public function testMvcViewEngineVoltCallMacroNull(): void
    {
        $volt = new class (new Simple()) extends Volt {
            public function setNullMacro(string $name): void
            {
                $this->macros[$name] = null;
            }
        };

        $volt->setNullMacro('m');

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func(): Argument #1 ($callback) must be a valid '
            . 'callback, no array or string given'
        );

        $volt->callMacro('m', [1]);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/15842
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-28
     */
    public function testMvcViewEngineVoltCallMacroPhpFunction(): void
    {
        $compiler = new Compiler();

        $source   = '{{ str_replace("a", "b", "aabb") }}';
        $expected = "<?= \$this->callMacro("
            . "'str_replace', ['a', 'b', 'aabb']) ?>";
        $actual   = $compiler->compileString($source);
        $this->assertEquals($expected, $actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/15842
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-28
     */
    public function testMvcViewEngineVoltCallMacroPhpFunctionDoesNotExist(): void
    {
        $compiler = new Compiler();

        $source   = '{{ myfunction("a") }}';
        $expected = "<?= \$this->callMacro('myfunction', ['a']) ?>";
        $actual   = $compiler->compileString($source);
        $this->assertEquals($expected, $actual);
    }
}
