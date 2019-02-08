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

namespace Phalcon\Test\Unit\Acl\Component;

use Phalcon\Acl\Component;
use UnitTester;

/**
 * Class ToStringCest
 */
class ToStringCest
{
    /**
     * Tests Phalcon\Acl\Component :: __toString()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclComponentToString(UnitTester $I)
    {
        $I->wantToTest('Acl\Component - __toString()');
        $component = new Component('Customers');

        $expected = 'Customers';
        $actual   = $component->__toString();
        $I->assertEquals($expected, $actual);

        $expected = 'Customers';
        $actual   = (string) $component;
        $I->assertEquals($expected, $actual);
    }
}
