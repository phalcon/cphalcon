<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\Response;

use Phalcon\Http\Message\Exception\InvalidArgumentException;
use Phalcon\Http\Message\Response;
use Phalcon\Http\Message\Stream;
use function dataDir;
use UnitTester;

class WithStatusCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: withStatus()
     *
     * @since  2019-03-09
     */
    public function httpMessageResponseWithStatus(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withStatus()');

        $code        = 420;
        $response    = new Response();
        $newInstance = $response->withStatus($code);

        $I->assertNotEquals($response, $newInstance);

        $I->assertEquals(
            $code,
            $newInstance->getStatusCode()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Response :: withStatus() - other reason
     *
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

        $I->assertEquals(
            $code,
            $newInstance->getStatusCode()
        );

        $I->assertEquals(
            $reason,
            $newInstance->getReasonPhrase()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Response :: withStatus() - exception invalid code
     *
     * @since  2019-03-09
     */
    public function httpMessageResponseWithStatusExceptionInvalidCode(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withStatus() - exception invalid code');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Invalid status code; it must be an integer or string'
            ),
            function () {
                $response = new Response();
                $newInstance = $response->withStatus(true, '');
            }
        );
    }

    /**
     * Tests Phalcon\Http\Message\Response :: withStatus() - exception invalid phrase
     *
     * @since  2019-03-09
     */
    public function httpMessageResponseWithStatusExceptionInvalidPhrase(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withStatus() - exception invalid phrase');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Invalid response reason'
            ),
            function () {
                $response = new Response();
                $newInstance = $response->withStatus(200, true);
            }
        );
    }
}
