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

namespace Phalcon\Test\Integration\Mvc\Router\Group;

use IntegrationTester;

/**
 * Class BeforeMatchCest
 */
class BeforeMatchCest
{
    /**
     * Tests Phalcon\Mvc\Router\Group :: beforeMatch()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcRouterGroupBeforeMatch(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Router\Group - beforeMatch()');
        $I->skipTest('Need implementation');
    }
}
