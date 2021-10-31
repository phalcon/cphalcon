<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Item;

use Phalcon\Encryption\Security\JWT\Token\Item;
use UnitTester;

/**
 * Class GetCest
 *
 * @package Phalcon\Tests\Unit\Encryption\Security\JWT\Token\Item
 */
class GetCest
{
    /**
     * Unit Tests Phalcon\Encryption\Security\JWT\Token\Item :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function httpJWTTokenItemGet(UnitTester $I)
    {
        $I->wantToTest('Http\JWT\Token\Item - get()');

        $item = new Item(['sub' => 'subject'], 'encoded-string-here');

        $I->assertEquals('subject', $item->get('sub'));
        $I->assertEquals('default', $item->get('jti', 'default'));
    }
}
