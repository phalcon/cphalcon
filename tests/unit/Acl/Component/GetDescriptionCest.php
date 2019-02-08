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
 * Class GetDescriptionCest
 */
class GetDescriptionCest
{
    /**
     * Tests Phalcon\Acl\Component :: getDescription()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclComponentGetDescription(UnitTester $I)
    {
        $I->wantToTest('Acl\Component - getDescription()');
        $component = new Component('Customers', 'Customer management');

        $expected = 'Customer management';
        $actual   = $component->getDescription();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Acl\Component :: getDescription() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclComponentGetDescriptionEmpty(UnitTester $I)
    {
        $I->wantToTest("Acl\Component - getDescription() - empty");
        $component = new Component('Customers');

        $actual = $component->getDescription();
        $I->assertEmpty($actual);
    }
}
