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

namespace Phalcon\Test\Unit\Acl\Operation;

use Phalcon\Acl\Operation;
use UnitTester;

/**
 * Class GetDescriptionCest
 */
class GetDescriptionCest
{
    /**
     * Tests Phalcon\Acl\Operation :: getDescription()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclOperationGetDescription(UnitTester $I)
    {
        $I->wantToTest('Acl\Operation - getDescription()');
        $operation = new Operation('Administrators', 'The admin unit');

        $expected = 'The admin unit';
        $actual   = $operation->getDescription();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Acl\Operation :: getDescription() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclOperationGetDescriptionEmpty(UnitTester $I)
    {
        $I->wantToTest('Acl\Operation - getDescription()');
        $operation = new Operation('Administrators');

        $actual = $operation->getDescription();
        $I->assertEmpty($actual);
    }
}
