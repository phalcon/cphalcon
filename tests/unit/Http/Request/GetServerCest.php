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

class GetServerCest
{
    /**
     * Tests Phalcon\Http\Request :: getServer()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function httpRequestGetServer(UnitTester $I)
    {
        $I->wantToTest('Http\Request - getServer()');

        $store   = $_SERVER ?? [];
        $_SERVER = [
            'one' => 'two',
        ];

        $request = new Request();

        $I->assertTrue($request->hasServer('one'));
        $I->assertFalse($request->hasServer('unknown'));
        $I->assertEquals('two', $request->getServer('one'));

        $_SERVER = $store;
    }
}
