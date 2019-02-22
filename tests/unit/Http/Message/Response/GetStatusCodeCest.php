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

use InvalidArgumentException;
use Phalcon\Http\Message\Response;
use UnitTester;

/**
 * Class GetStatusCodeCest
 */
class GetStatusCodeCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getStatusCode()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageResponseGetStatusCode(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getStatusCode()');
        $response = new Response();

        $expected = 200;
        $actual   = $response->getStatusCode();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Response :: getStatusCode() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageResponseGetStatusCodeException(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getStatusCode() - exception');
        $I->expectThrowable(
            new InvalidArgumentException(
                "Invalid status code '847', (allowed values 100-599)"
            ),
            function () {
                $response = new Response("php://memory", 847);
            }
        );
    }
}
