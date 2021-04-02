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

use Phalcon\Http\Request;
use UnitTester;

class IsMethodCest
{
    /**
     * Tests Phalcon\Http\Request :: isMethod()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestIsMethod(UnitTester $I)
    {
        $I->wantToTest('Http\Request - isMethod()');

        $store   = $_SERVER ?? [];
        $_SERVER = [
            'REQUEST_METHOD' => 'POST',
        ];

        $request = new Request();

        $I->assertTrue($request->isMethod('POST'));
        $I->assertTrue($request->isMethod(['GET', 'POST']));

        $_SERVER['REQUEST_METHOD'] = 'GET';

        $I->assertTrue($request->isMethod('GET'));
        $I->assertTrue($request->isMethod(['GET', 'POST']));

        $_SERVER = $store;
    }
}
