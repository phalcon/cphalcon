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

namespace Phalcon\Tests\Unit\Crypt;

use Phalcon\Http\Request;
use UnitTester;

class UseSigningCest
{
    /**
     * Tests Phalcon\Crypt :: useSigning()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-03-17
     */
    public function cryptUseSigning(UnitTester $I)
    {
        $I->wantToTest('Crypt - useSigning()');

        $store    = $_REQUEST ?? [];
        $_REQUEST = [
            'one' => 'two',
        ];

        $request = new Request();
        $I->assertTrue($request->has('one'));
        $I->assertFalse($request->has('unknown'));
        $I->assertEquals('two', $request->get('one'));

        $_REQUEST = $store;
    }
}
