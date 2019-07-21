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

class IsStrictHostCheckCest extends HttpBase
{
    /**
     * Tests strict host check
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-06-26
     */
    public function testHttpStrictHostCheck(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $request->setStrictHostCheck(true);

        $this->setServerVar('SERVER_NAME', 'LOCALHOST:80');

        $I->assertEquals(
            'localhost',
            $request->getHttpHost()
        );


        $request = $this->getRequestObject();

        $request->setStrictHostCheck(false);

        $this->setServerVar('SERVER_NAME', 'LOCALHOST:80');

        $I->assertEquals(
            'LOCALHOST:80',
            $request->getHttpHost()
        );


        $request = $this->getRequestObject();

        $I->assertFalse(
            $request->isStrictHostCheck()
        );


        $request->setStrictHostCheck(true);

        $I->assertTrue(
            $request->isStrictHostCheck()
        );


        $request->setStrictHostCheck(false);

        $I->assertFalse(
            $request->isStrictHostCheck()
        );
    }
}
