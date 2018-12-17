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

namespace Phalcon\Test\Unit\Acl\Subject;

use Phalcon\Acl\Subject;
use UnitTester;

/**
 * Class GetDescriptionCest
 */
class GetDescriptionCest
{
    /**
     * Tests Phalcon\Acl\Subject :: getDescription()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclSubjectGetDescription(UnitTester $I)
    {
        $I->wantToTest('Acl\Subject - getDescription()');
        $resource = new Subject('Customers', 'Customer management');

        $expected = 'Customer management';
        $actual   = $resource->getDescription();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Acl\Subject :: getDescription() - empty
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclSubjectGetDescriptionEmpty(UnitTester $I)
    {
        $I->wantToTest("Acl\Subject - getDescription() - empty");
        $resource = new Subject('Customers');

        $actual = $resource->getDescription();
        $I->assertEmpty($actual);
    }
}
