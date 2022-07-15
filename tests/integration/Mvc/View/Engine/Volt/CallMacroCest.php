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

namespace Phalcon\Tests\Integration\Mvc\View\Engine\Volt;

use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;

class CallMacroCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt :: callMacro() - PHP function
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-28
     * @issue  https://github.com/phalcon/cphalcon/issues/15842
     */
    public function mvcViewEngineVoltCallMacroPhpFunction(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt - callMacro() - php function');

        $compiler  = new Compiler();

        $source   = '{{ str_replace("a", "b", "aabb") }}';
        $expected = "<?= \$this->callMacro("
            . "'str_replace', ['a', 'b', 'aabb']) ?>";
        $actual   = $compiler->compileString($source);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt :: callMacro() - PHP function
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-28
     * @issue  https://github.com/phalcon/cphalcon/issues/15842
     */
    public function mvcViewEngineVoltCallMacroPhpFunctionDoesNotExist(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt - callMacro() - php function does not exist');

        $compiler  = new Compiler();

        $source   = '{{ myfunction("a") }}';
        $expected = "<?= \$this->callMacro('myfunction', ['a']) ?>";
        $actual   = $compiler->compileString($source);
        $I->assertEquals($expected, $actual);
    }
}
