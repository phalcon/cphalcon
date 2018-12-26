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
 * Class AddSubjectCest
 */
class AddSubjectCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addSubject() - string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddSubjectString(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addSubject() - string');
        $acl     = new Memory();
        $subject = new Subject('Customer', 'Customer subject');

        $actual = $acl->addSubject('Customer', ['index']);
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addSubject() - object
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddSubjectObject(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addSubject() - object');
        $acl     = new Memory();
        $subject = new Subject('Customer', 'Customer subject');

        $actual = $acl->addSubject($subject, ['index']);
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addSubject() - numeric key
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddSubjectNumericKey(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addSubject() - numeric key');
        $acl     = new Memory();
        $subject = new Subject('11', 'Customer subject');

        $actual = $acl->addSubject($subject, ['index']);
        $I->assertTrue($actual);
        $actual = $acl->isSubject('11');
        $I->assertTrue($actual);
    }
}
