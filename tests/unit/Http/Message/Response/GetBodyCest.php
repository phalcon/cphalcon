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
 * Class GetBodyCest
 */
class GetBodyCest
{
    /**
     * Tests Phalcon\Http\Message\Response :: getBody()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetBody(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getBody()');
        $fileName = dataFolder('/assets/stream/bill-of-rights.txt');
        $stream   = new Stream($fileName, 'rb');
        $request  = new Response($stream);

        $expected = file_get_contents($fileName);
        $actual   = $request->getBody();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\Response :: getBody() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-09
     */
    public function httpMessageResponseGetBodyEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Response - getBody() - empty');
        $request = new Response();

        $class  = Stream::class;
        $actual = $request->getBody();
        $I->assertInstanceOf($class, $actual);
    }
}
