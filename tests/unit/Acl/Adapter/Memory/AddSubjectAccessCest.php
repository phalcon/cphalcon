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
use Phalcon\Acl\Exception;
use Phalcon\Acl\Subject;
use UnitTester;

/**
 * Class AddSubjectAccessCest
 */
class AddSubjectAccessCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addSubjectAccess()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddSubjectAccess(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addSubjectAccess()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addSubjectAccess() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddSubjectAccessUnknown(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addSubjectAccess() - unknown');
        $I->expectThrowable(
            new Exception("Subject 'Post' does not exist in ACL"),
            function () {
                $acl = new Memory();
                $acl->addSubjectAccess('Post', ['update']);
            }
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addSubjectAccess() - wrong access
     * list
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddSubjectAccessWrongAccessList(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addSubjectAccess() - wrong access list');
        $I->expectThrowable(
            new Exception('Invalid value for accessList'),
            function () {
                $acl  = new Memory();
                $post = new Subject('Post');
                $acl->addSubject($post, ['update']);
                $acl->addSubjectAccess('Post', 123);
            }
        );
    }
}
