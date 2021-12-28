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

namespace Phalcon\Tests\Integration\Mvc\View\Engine\Volt\Extensions;

use IntegrationTester;
use Phalcon\Mvc\View\Engine\Volt\Compiler;

class PhpCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Extensions :: php()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-28
     */
    public function mvcViewEngineVoltExtensionsPhp(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt\Extensions - php');

        $compiler  = new Compiler();

        $expected = "<?= \$this->callMacro("
            . "'str_replace', ['a', 'b', 'aabb']) ?>";
        $actual   = $compiler->compileString('{{ str_replace("a", "b", "aabb") }}');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Extensions :: does not exist
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-12-28
     */
    public function mvcViewEngineVoltExtensionsDoesNotExist(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt\Extensions - does not exist');

        $compiler  = new Compiler();

        $expected = "<?= \$this->callMacro("
            . "'myfunction', ['a']) ?>";
        $actual   = $compiler->compileString('{{ myfunction("a") }}');
        $I->assertEquals($expected, $actual);
    }
}
