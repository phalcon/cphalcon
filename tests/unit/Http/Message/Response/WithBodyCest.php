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
use Phalcon\Http\Message\Stream;
use UnitTester;

/**
 * Class WithBodyCest
 */
class WithBodyCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: withBody()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseWithBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - withBody()');
        $fileName = dataDir('/assets/stream/bill-of-rights.txt');
        $stream   = new Stream($fileName, 'rb');
        $request  = new Response();

        $newInstance = $request->withBody($stream);

        $I->assertNotEquals($request, $newInstance);

        $expected = file_get_contents($fileName);
        $actual   = $newInstance->getBody();
        $I->assertEquals($expected, $actual);
    }
}
