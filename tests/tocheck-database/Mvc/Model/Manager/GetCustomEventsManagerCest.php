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

namespace Phalcon\Tests\Integration\Mvc\Model\Manager;

use IntegrationTester;

/**
 * Class GetCustomEventsManagerCest
 */
class GetCustomEventsManagerCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: getCustomEventsManager()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcModelManagerGetCustomEventsManager(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Manager - getCustomEventsManager()');
        $I->skipTest('Need implementation');
    }
}
