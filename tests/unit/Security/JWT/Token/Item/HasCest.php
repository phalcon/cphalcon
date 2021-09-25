<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Security\JWT\Token\Item;

use Phalcon\Security\JWT\Token\Item;
use UnitTester;

class HasCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Token\Item :: has()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTTokenItemHas(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Token\Item - has()');

        $item = new Item(['sub' => 'subject'], 'encoded-string-here');

        $I->assertTrue($item->has('sub'));
        $I->assertFalse($item->has('jti'));
    }
}
