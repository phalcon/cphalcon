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

class IsStrictHostCheckCest extends HttpBase
{
    /**
     * Tests strict host check
     *
     * @author Phalcon Team <team@phalcon.io>
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
