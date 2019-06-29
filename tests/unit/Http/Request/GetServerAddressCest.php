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

use Phalcon\Test\Unit\Http\Helper\HttpBase;
use UnitTester;

class GetServerAddressCest extends HttpBase
{
    /**
     * Tests getServerAddress default
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestGetServerAddressDefault(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $I->assertEquals(
            '127.0.0.1',
            $request->getServerAddress()
        );
    }

    /**
     * Tests getServerAddress
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestGetServerAddress(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $this->setServerVar('SERVER_ADDR', '192.168.4.1');
        $actual = $request->getServerAddress();
        $this->unsetServerVar('SERVER_ADDR');

        $I->assertEquals(
            '192.168.4.1',
            $actual
        );
    }
}
