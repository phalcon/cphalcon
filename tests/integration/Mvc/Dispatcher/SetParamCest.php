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

namespace Phalcon\Test\Integration\Mvc\Dispatcher;

use IntegrationTester;

/**
 * Class SetParamCest
 */
class SetParamCest
{
    /**
     * Tests Phalcon\Mvc\Dispatcher :: setParam()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcDispatcherSetParam(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Dispatcher - setParam()');
        $I->skipTest('Need implementation');
    }
}
