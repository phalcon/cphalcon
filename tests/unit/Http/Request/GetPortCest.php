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

use Phalcon\Tests\Unit\Http\Helper\HttpBase;
use UnitTester;

class GetPortCest extends HttpBase
{
    /**
     * Tests Request::getPort
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-06-26
     */
    public function testHttpRequestPort(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $this->setServerVar('HTTPS', 'on');
        $this->setServerVar('HTTP_HOST', 'example.com');

        $I->assertEquals(
            443,
            $request->getPort()
        );


        $request = $this->getRequestObject();

        $this->setServerVar('HTTPS', 'off');
        $this->setServerVar('HTTP_HOST', 'example.com');

        $I->assertEquals(
            80,
            $request->getPort()
        );


        $request = $this->getRequestObject();

        $this->setServerVar('HTTPS', 'off');
        $this->setServerVar('HTTP_HOST', 'example.com:8080');

        $I->assertEquals(
            8080,
            $request->getPort()
        );


        $this->setServerVar('HTTPS', 'on');
        $this->setServerVar('HTTP_HOST', 'example.com:8081');

        $I->assertEquals(
            8081,
            $request->getPort()
        );

        unset(
            $_SERVER['HTTPS']
        );

        $this->setServerVar('HTTP_HOST', 'example.com:8082');

        $I->assertEquals(
            8082,
            $request->getPort()
        );
    }
}
