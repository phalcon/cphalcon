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

class GetPortCest extends HttpBase
{
    /**
     * Tests Request::getPort
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-06-26
     */
    public function testHttpRequestPort(UnitTester $I)
    {
        $this->setServerVar('HTTPS', 'on');
        $this->setServerVar('HTTP_HOST', 'example.com');

        $request = $this->getRequestObject();

        $I->assertEquals(
            443,
            $request->getPort()
        );


        $this->setServerVar('HTTPS', 'off');
        $this->setServerVar('HTTP_HOST', 'example.com');

        $request = $this->getRequestObject();

        $I->assertEquals(
            80,
            $request->getPort()
        );


        $this->setServerVar('HTTPS', 'off');
        $this->setServerVar('HTTP_HOST', 'example.com:8080');

        $request = $this->getRequestObject();

        $I->assertEquals(
            8080,
            $request->getPort()
        );


        $this->setServerVar('HTTPS', 'on');
        $this->setServerVar('HTTP_HOST', 'example.com:8081');

        $request = $this->getRequestObject();

        $I->assertEquals(
            8081,
            $request->getPort()
        );

        unset(
            $_SERVER['HTTPS']
        );

        $this->setServerVar('HTTP_HOST', 'example.com:8082');

        $request = $this->getRequestObject();

        $I->assertEquals(
            8082,
            $request->getPort()
        );
    }
}
