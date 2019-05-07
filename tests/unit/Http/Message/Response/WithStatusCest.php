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

namespace Phalcon\Test\Unit\Http\Message\Response;

use Phalcon\Http\Message\Response;
use UnitTester;

/**
 * Class WithStatusCest
 */
class WithStatusCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: withStatus()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseWithStatus(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withStatus()');

        $code        = 420;
        $response    = new Response();
        $newInstance = $response->withStatus($code);
        $I->assertNotEquals($response, $newInstance);
        $I->assertEquals($code, $newInstance->getStatusCode());
    }

    /**
     * Tests Phalcon\Http\Message\Response :: withStatus() - other reason
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseWithStatusOtherReason(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withStatus() - other reason');

        $code        = 420;
        $reason      = 'Phalcon Response';
        $response    = new Response();
        $newInstance = $response->withStatus($code, $reason);
        $I->assertNotEquals($response, $newInstance);
        $I->assertEquals($code, $newInstance->getStatusCode());
        $I->assertEquals($reason, $newInstance->getReasonPhrase());
    }
}
