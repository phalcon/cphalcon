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

use Phalcon\Acl;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Operation;
use Phalcon\Acl\Subject;
use Phalcon\Test\Fixtures\Acl\TestOperationSubjectAware;
use UnitTester;

/**
 * Class IsAllowedCest
 */
class IsAllowedCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - default
     *
     * @param UnitTester $I
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12573
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-01-25
     */
    public function aclAdapterMemoryIsAllowedDefault(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - default');
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);
        $acl->addSubject(new Subject('Post'), ['index', 'update', 'create']);
        $acl->addOperation(new Operation('Guests'));

        $acl->allow('Guests', 'Post', 'index');
        $actual = $acl->isAllowed('Guests', 'Post', 'index');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Guests', 'Post', 'update');
        $I->assertFalse($actual);
    }


    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - objects
     *
     * @param UnitTester $I
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function aclAdapterMemoryIsAllowedObjects(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - objects');
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);
        $operation = new Operation('Guests');
        $subject   = new Subject('Post');
        $acl->addOperation($operation);
        $acl->addSubject($subject, ['index', 'update', 'create']);

        $acl->allow('Guests', 'Post', 'index');

        $actual = $acl->isAllowed($operation, $subject, 'index');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($operation, $subject, 'update');
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: isAllowed() - same class
     *
     * @param UnitTester $I
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function aclAdapterMemoryIsAllowedSameClass(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - isAllowed() - same class');
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);
        $operation = new TestOperationSubjectAware(1, 'User', 'Admin');
        $subject   = new TestOperationSubjectAware(2, 'User', 'Admin');
        $acl->addOperation('Admin');
        $acl->addSubject('User', ['update']);
        $acl->allow(
            'Admin',
            'User',
            ['update'],
            function (TestOperationSubjectAware $admin, TestOperationSubjectAware $user) {
                return $admin->getUser() == $user->getUser();
            }
        );

        $actual = $acl->isAllowed($operation, $subject, 'update');
        $I->assertFalse($actual);
        $actual = $acl->isAllowed($operation, $operation, 'update');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($subject, $subject, 'update');
        $I->assertTrue($actual);
    }
}
