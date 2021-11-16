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

/**
 * Class ResolveTestCest
 */
class ResolveTestCest
{
    /**
     * Tests Phalcon\Mvc\View\Engine\Volt\Compiler :: resolveTest()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcViewEngineVoltCompilerResolveTest(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\View\Engine\Volt\Compiler - resolveTest()');
        $I->skipTest('Need implementation');
    }
}
