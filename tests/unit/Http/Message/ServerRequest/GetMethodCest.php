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

use InvalidArgumentException;
use Phalcon\Http\Message\ServerRequest;
use UnitTester;

/**
 * Class GetMethodCest
 */
class GetMethodCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getMethod()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetMethod(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getMethod()');
        $request = new ServerRequest('POST');

        $expected = 'POST';
        $actual   = $request->getMethod();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getMethod() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetMethodEmpty(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getMethod() - empty');
        $request = new ServerRequest();

        $expected = 'GET';
        $actual   = $request->getMethod();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getMethod() - exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageServerRequestGetMethodWxception(UnitTester $I)
    {
        $I->wantToTest('Http\Message\ServerRequest - getMethod() - exception');
        $I->expectThrowable(
            new InvalidArgumentException('Invalid or unsupported method UNKNOWN'),
            function () {
                $request = new ServerRequest('UNKNOWN');
            }
        );
    }
}
