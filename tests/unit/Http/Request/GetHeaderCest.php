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

namespace Phalcon\Test\Unit\Http\Request;

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class GetHeaderCest extends HttpBase
{
    /**
     * Tests getHeader empty
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGetEmpty(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $I->assertEmpty(
            $request->getHeader('LOL')
        );
    }

    /**
     * Tests getHeader
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2014-10-04
     */
    public function testHttpRequestHeaderGet(UnitTester $I)
    {
        $request = $this->getRequestObject();
        $this->setServerVar('HTTP_LOL', 'zup');
        $actual = $request->getHeader('LOL');
        $this->unsetServerVar('HTTP_LOL');

        $I->assertEquals(
            'zup',
            $actual
        );
    }

    /**
     * Tests getHeader
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/2294
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-10-19
     */
    public function testHttpRequestCustomHeaderGet(UnitTester $I)
    {
        $_SERVER['HTTP_FOO']     = 'Bar';
        $_SERVER['HTTP_BLA_BLA'] = 'boo';
        $_SERVER['HTTP_AUTH']    = true;

        $request = $this->getRequestObject();

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
