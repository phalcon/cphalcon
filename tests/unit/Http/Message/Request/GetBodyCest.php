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

namespace Phalcon\Test\Unit\Http\Message\Request;

use Phalcon\Http\Message\Request;
use Phalcon\Http\Message\Stream;
use UnitTester;

class GetBodyCest
{
    /**
     * Tests Phalcon\Http\Message\Request :: getBody()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getBody()');

        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');

        $stream = new Stream($fileName, 'rb');

        $request = new Request('GET', null, $stream);

        $I->assertEquals(
            file_get_contents($fileName),
            $request->getBody()
        );
    }

    /**
     * Tests Phalcon\Http\Message\Request :: getBody() - empty
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageRequestGetBodyEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Request - getBody() - empty');

        $request = new Request();

        $I->assertInstanceOf(
            Stream::class,
            $request->getBody()
        );
    }
}
