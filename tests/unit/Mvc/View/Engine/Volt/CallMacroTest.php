<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\View\Engine\Volt;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Mvc\View\Engine\Volt\Compiler;

class CallMacroTest extends AbstractUnitTestCase
{
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
