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

namespace Phalcon\Test\Integration\Mvc\Application;

use IntegrationTester;

/**
 * Class SendCookiesOnHandleRequestCest
 */
class SendCookiesOnHandleRequestCest
{
    /**
     * Tests Phalcon\Mvc\Application :: sendCookiesOnHandleRequest()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcApplicationSendCookiesOnHandleRequest(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Application - sendCookiesOnHandleRequest()');
        $I->skipTest('Need implementation');
    }
}
