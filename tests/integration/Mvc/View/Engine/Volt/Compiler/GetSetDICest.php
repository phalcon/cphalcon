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

namespace Phalcon\Tests\Integration\Mvc\View\Engine\Volt\Compiler;

use IntegrationTester;
use Phalcon\Di\Di;
use Phalcon\Mvc\View\Engine\Volt\Compiler;

class GetSetDICest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: getDI() / setDI()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-22
     */
    public function mvcViewEngineVoltCompilerGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt\Compiler - getDI() / setDI()');

        $compiler = new Compiler();

        $container = new Di();

        $compiler->setDI($container);

        $I->assertSame(
            $container,
            $compiler->getDI()
        );
    }
}
