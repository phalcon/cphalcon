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

class ConstructCest
{
    /**
     * Unit Tests Phalcon\Security\JWT\Token\Item :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-22
     */
    public function securityJWTTokenItemConstruct(UnitTester $I)
    {
        $I->wantToTest('Security\JWT\Token\Item - __construct()');

        $item = new Item(['sub' => 'subject'], 'encoded-string-here');

        $I->assertInstanceOf(Item::class, $item);
    }
}
