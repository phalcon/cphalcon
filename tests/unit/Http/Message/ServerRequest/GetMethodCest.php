<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\Message\ServerRequest;

use InvalidArgumentException;
use Phalcon\Http\Message\ServerRequest;
use UnitTester;

class GetMethodCest
{
    /**
     * Tests Phalcon\Http\Message\ServerRequest :: getMethod()
     *
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
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
