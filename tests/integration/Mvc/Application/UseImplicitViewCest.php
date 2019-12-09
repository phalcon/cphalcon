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

namespace Phalcon\Test\Integration\Mvc\Application;

use IntegrationTester;

/**
 * Class UseImplicitViewCest
 */
class UseImplicitViewCest
{
    /**
     * Tests Phalcon\Mvc\Application :: useImplicitView()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcApplicationUseImplicitView(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Application - useImplicitView()');
        $I->skipTest('Need implementation');
    }
}
