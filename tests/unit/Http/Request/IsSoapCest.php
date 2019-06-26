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

class IsSoapCest extends HttpBase
{
    /**
     * Tests isSoap default
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-23
     */
    public function testHttpRequestIsSoapDefault(UnitTester $I)
    {
        $request = $this->getRequestObject();

        $I->assertFalse(
            $request->isSoap()
        );
    }

    /**
     * Tests isSoap
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testHttpRequestIsSoap(UnitTester $I)
    {
        $this->setServerVar('CONTENT_TYPE', 'application/soap+xml');

        $request = $this->getRequestObject();

        $actual = $request->isSoap();
        $this->unsetServerVar('CONTENT_TYPE');

        $I->assertTrue($actual);
    }
}
