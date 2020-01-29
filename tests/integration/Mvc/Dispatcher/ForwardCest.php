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

namespace Phalcon\Test\Integration\Mvc\Dispatcher;

use IntegrationTester;

/**
 * Class ForwardCest
 */
class ForwardCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: forward()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcDispatcherForward(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - forward()');
        $I->skipTest('Need implementation');
    }
}
