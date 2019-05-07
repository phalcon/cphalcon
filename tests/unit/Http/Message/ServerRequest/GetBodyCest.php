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

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use Phalcon\Http\Message\ServerRequest;
use Phalcon\Http\Message\Stream;
use UnitTester;

class GetBodyCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getBody()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getBody()');
        $fileName = dataDir('/assets/stream/bill-of-rights.txt');
        $stream   = new Stream($fileName, 'rb');
        $request  = new ServerRequest('GET', null, [], $stream);

        $expected = file_get_contents($fileName);
        $actual   = $request->getBody();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getBody() - empty
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetBodyEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getBody() - empty');
        $request = new ServerRequest();

        $class  = Stream\Input::class;
        $actual = $request->getBody();
        $I->assertInstanceOf($class, $actual);
    }
}
