<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Unit\Http\JWT\Token\Item;

use Phalcon\Http\JWT\Token\Item;
use UnitTester;

class GetCest
{
    /**
     * Unit Tests Phalcon\Http\JWT\Token\Item :: get()
     *
     * @since  2019-12-22
     */
    public function httpJWTTokenItemGet(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Item - get()');

        $item = new Item(['sub' => 'subject'], 'encoded-string-here');

        $I->assertEquals('subject', $item->get('sub'));
        $I->assertEquals('default', $item->get('jti', 'default'));
    }
}
