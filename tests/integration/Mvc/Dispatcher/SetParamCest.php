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

namespace Phalcon\Tests\Integration\Mvc\Dispatcher;

use IntegrationTester;

class SetParamCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: setParam()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function mvcDispatcherSetParam(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - setParam()');
        $I->skipTest('Need implementation');
    }
}
