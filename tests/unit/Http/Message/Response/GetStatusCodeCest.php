<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\Response;

use InvalidArgumentException;
use Phalcon\Http\Message\Response;
use UnitTester;

class GetStatusCodeCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getStatusCode()
     *
     * @since  2019-03-09
     */
    public function httpMessageResponseGetStatusCode(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getStatusCode()');

        $response = new Response();

        $I->assertEquals(
            200,
            $response->getStatusCode()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Response :: getStatusCode() - exception
     *
     * @since  2019-03-09
     */
    public function httpMessageResponseGetStatusCodeException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getStatusCode() - exception');

        $I->expectThrowable(
            new InvalidArgumentException(
                "Invalid status code '847', (allowed values 100-599)"
            ),
            function () {
                $response = new Response('php://memory', 847);
            }
        );
    }
}
