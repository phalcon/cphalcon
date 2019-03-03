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
 * Class GetNameCest
 */
class GetNameCest
{
    /**
     * Tests Phalcon\Acl\Component :: getName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclComponentGetName(UnitTester $I)
    {
        $I->wantToTest('Acl\Component - getName()');
        $component = new Component('Customers');

        $expected = 'Customers';
        $actual   = $component->getName();
        $I->assertEquals($expected, $actual);
    }
}
