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

use Phalcon\Http\Request;
use UnitTester;

class IsValidHttpMethodCest
{
    /**
     * Tests Phalcon\Http\Request :: isValidHttpMethod()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestIsValidHttpMethod(UnitTester $I)
    {
        $I->wantToTest('Http\Request - isValidHttpMethod()');

        $request = new Request();

        $I->assertTrue($request->isValidHttpMethod("GET"));
        $I->assertTrue($request->isValidHttpMethod("POST"));
        $I->assertTrue($request->isValidHttpMethod("PUT"));
        $I->assertTrue($request->isValidHttpMethod("DELETE"));
        $I->assertTrue($request->isValidHttpMethod("HEAD"));
        $I->assertTrue($request->isValidHttpMethod("OPTIONS"));
        $I->assertTrue($request->isValidHttpMethod("PATCH"));
        $I->assertTrue($request->isValidHttpMethod("PURGE"));
        $I->assertTrue($request->isValidHttpMethod("TRACE"));
        $I->assertTrue($request->isValidHttpMethod("CONNECT"));
        $I->assertTrue($request->isValidHttpMethod("get"));
        $I->assertTrue($request->isValidHttpMethod("post"));
        $I->assertTrue($request->isValidHttpMethod("put"));
        $I->assertTrue($request->isValidHttpMethod("delete"));
        $I->assertTrue($request->isValidHttpMethod("head"));
        $I->assertTrue($request->isValidHttpMethod("options"));
        $I->assertTrue($request->isValidHttpMethod("patch"));
        $I->assertTrue($request->isValidHttpMethod("purge"));
        $I->assertTrue($request->isValidHttpMethod("trace"));
        $I->assertTrue($request->isValidHttpMethod("connect"));
        $I->assertFalse($request->isValidHttpMethod("unknown"));
    }
}
