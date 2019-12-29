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

namespace Phalcon\Test\Integration\Mvc\Micro;

use IntegrationTester;

/**
 * Class StopCest
 */
class StopCest
{
    /**
     * Tests Phalcon\Mvc\Micro :: stop()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcMicroStop(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Micro - stop()');
        $I->skipTest('Need implementation');
    }
}
