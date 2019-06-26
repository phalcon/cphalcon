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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Http\Request;
use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class GetHeaderCest extends HttpBase
{
    /**
     * Tests getHeader empty
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGetEmpty(UnitTester $I)
    {
        $request = new Request();

        $I->assertEmpty(
            $request->getHeader('LOL')
        );
    }

    /**
     * Tests getHeader
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGet(UnitTester $I)
    {
        $request = new Request();
        $request->init(
            [
                'HTTP_LOL' => 'zup',
            ]
        );

        $actual = $request->getHeader('LOL');
        $I->assertEquals(
            'zup',
            $actual
        );
    }

    /**
     * Tests getHeader
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2294
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-10-19
     */
    public function testHttpRequestCustomHeaderGet(UnitTester $I)
    {
        $request = new Request();
        $request->init(
            [
                'HTTP_FOO'     => 'Bar',
                'HTTP_BLA_BLA' => 'boo',
                'HTTP_AUTH'    => true,
            ]
        );

        $expected = [
            'Foo'     => 'Bar',
            'Bla-Bla' => 'boo',
            'Auth'    => 1,
        ];

        $I->assertEquals(
            $expected,
            $request->getHeaders()
        );
    }
}
