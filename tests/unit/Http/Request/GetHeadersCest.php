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

namespace Phalcon\Tests\Unit\Http\Request;

use Phalcon\Http\Request;
use UnitTester;

class GetHeadersCest
{
    /**
     * Tests Phalcon\Http\Request :: getHeaders()
     *
     * @issue  2294
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-10-19
     */
    public function httpRequestGetHeaders(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getHeaders()');

        $store   = $_SERVER ?? [];
        $time    = $_SERVER['REQUEST_TIME_FLOAT'];
        $_SERVER = [
            'REQUEST_TIME_FLOAT' => $time,
            'HTTP_FOO'     => 'Bar',
            'HTTP_BLA_BLA' => 'boo',
            'HTTP_AUTH'    => true,
        ];

        $request = new Request();

        $expected = [
            'Foo'     => 'Bar',
            'Bla-Bla' => 'boo',
            'Auth'    => true,
        ];

        $I->assertSame($expected, $request->getHeaders());

        $_SERVER = $store;
    }
}
