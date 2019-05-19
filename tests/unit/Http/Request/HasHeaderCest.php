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

class HasHeaderCest extends HttpBase
{
    /**
     * Tests hasHeader
     *
     * @author limx <715557344@qq.com>
     * @since  2017-10-26
     */
    public function testHttpRequestCustomHeaderHas(UnitTester $I)
    {
        $_SERVER['HTTP_FOO']  = 'Bar';
        $_SERVER['HTTP_AUTH'] = true;

        $request = $this->getRequestObject();

        $I->assertTrue(
            $request->hasHeader('HTTP_FOO')
        );

        $I->assertTrue(
            $request->hasHeader('AUTH')
        );

        $I->assertTrue(
            $request->hasHeader('HTTP_FOO')
        );
    }
}
