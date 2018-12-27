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

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Subject;
use UnitTester;

/**
 * Class IsSubjectCest
 */
class IsSubjectCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isSubject()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsSubject(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isSubject()');
        $acl        = new Memory();
        $aclSubject = new Subject('Customers', 'Customer management');

        $acl->addSubject($aclSubject, 'search');
        $actual = $acl->isSubject('Customers');
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isSubject() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryIsSubjectUnknown(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isSubject() - unknown');
        $acl        = new Memory();
        $aclSubject = new Subject('Customers', 'Customer management');

        $acl->addSubject($aclSubject, 'search');
        $actual = $acl->isSubject('unknown');
        $I->assertFalse($actual);
    }
}
