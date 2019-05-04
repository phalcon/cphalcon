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

class GetBodyCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getBody()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getBody()');

        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');

        $stream = new Stream($fileName, 'rb');

        $request = new Response($stream);

        $I->assertEquals(
            file_get_contents($fileName),
            $request->getBody()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Response :: getBody() - empty
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetBodyEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getBody() - empty');

        $request = new Response();

        $I->assertInstanceOf(
            Stream::class,
            $request->getBody()
        );
    }
}
