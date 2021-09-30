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

namespace Phalcon\Tests\Unit\Acl\Component;

use Phalcon\Acl\Component;
use UnitTester;

/**
 * Class ToStringCest
 *
 * @package Phalcon\Tests\Unit\Acl\Component
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Acl\Component :: __toString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclComponentToString(UnitTester $I)
    {
        $I->wantToTest('Acl\Component - __toString()');

        $component = new Component('Customers');

        $I->assertEquals('Customers', $component->__toString());
        $I->assertEquals('Customers', (string) $component);
    }
}
