<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\View\Engine\Volt\Compiler;

use IntegrationTester;

/**
 * Class CompileForeachCest
 */
class CompileForeachCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: compileForeach()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcViewEngineVoltCompilerCompileForeach(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt\Compiler - compileForeach()');
        $I->skipTest('Need implementation');
    }
}
