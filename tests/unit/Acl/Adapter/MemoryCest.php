<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl\Adapter;

use Phalcon\Acl;
use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Operation;
use Phalcon\Acl\Subject;
use UnitTester;

class MemoryCest
{
    /**
     * Tests the wildcard allow/deny
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclWildcardAllowDeny(UnitTester $I)
    {
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);

        $aclOperations = [
            'Admin'  => new Operation('Admin'),
            'Users'  => new Operation('Users'),
            'Guests' => new Operation('Guests'),
        ];

        $aclSubjects = [
            'welcome' => ['index', 'about'],
            'account' => ['index'],
        ];

        foreach ($aclOperations as $operation => $object) {
            $acl->addOperation($object);
        }

        foreach ($aclSubjects as $subject => $actions) {
            $acl->addSubject(new Subject($subject), $actions);
        }
        $acl->allow("*", "welcome", "index");

        foreach ($aclOperations as $operation => $object) {
            $actual = $acl->isAllowed($operation, 'welcome', 'index');
            $I->assertTrue($actual);
        }

        $acl->deny("*", "welcome", "index");
        foreach ($aclOperations as $operation => $object) {
            $actual = $acl->isAllowed($operation, 'welcome', 'index');
            $I->assertFalse($actual);
        }
    }

    /**
     * Tests the ACL objects
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclObjects(UnitTester $I)
    {
        $acl          = new Memory();
        $aclOperation = new Operation('Administrators', 'Super User access');
        $aclSubject   = new Subject('Customers', 'Customer management');

        $acl->setDefaultAction(Acl::DENY);

        $acl->addOperation($aclOperation);
        $acl->addSubject($aclSubject, ['search', 'destroy']);

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $expected = Acl::ALLOW;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $I->assertEquals($expected, $actual);

        $acl          = new Memory();
        $aclOperation = new Operation('Administrators', 'Super User access');
        $aclSubject   = new Subject('Customers', 'Customer management');

        $acl->setDefaultAction(Acl::DENY);

        $acl->addOperation($aclOperation);
        $acl->addSubject($aclSubject, ['search', 'destroy']);

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $expected = Acl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests serializing the ACL
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclSerialize(UnitTester $I)
    {
        $filename = $I->getNewFileName('acl', 'log');

        $acl          = new Memory();
        $aclOperation = new Operation('Administrators', 'Super User access');
        $aclSubject   = new Subject('Customers', 'Customer management');

        $acl->addOperation($aclOperation);
        $acl->addSubject($aclSubject, ['search', 'destroy']);

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $contents = serialize($acl);
        file_put_contents(cacheFolder($filename), $contents);

        $acl = null;

        $contents = file_get_contents(cacheFolder($filename));

        $I->safeDeleteFile(cacheFolder($filename));

        $acl    = unserialize($contents);
        $actual = ($acl instanceof Memory);
        $I->assertTrue($actual);

        $actual = $acl->isOperation('Administrators');
        $I->assertTrue($actual);

        $actual = $acl->isSubject('Customers');
        $I->assertTrue($actual);

        $expected = Acl::ALLOW;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $I->assertEquals($expected, $actual);

        $expected = Acl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests negation of inherited operations
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/65
     *
     * @author  Phalcon Team <team@phalconphp.com>
     * @since   2014-10-04
     */
    public function testAclNegationOfInheritedOperations(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::DENY);

        $acl->addOperation('Guests');
        $acl->addOperation('Members', 'Guests');

        $acl->addSubject('Login', ['help', 'index']);

        $acl->allow('Guests', 'Login', '*');
        $acl->deny('Guests', 'Login', ['help']);
        $acl->deny('Members', 'Login', ['index']);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'index');
        $I->assertFalse($actual);

        $actual = (bool) $acl->isAllowed('Guests', 'Login', 'index');
        $I->assertTrue($actual);

        $actual = (bool) $acl->isAllowed('Guests', 'Login', 'help');
        $I->assertFalse($actual);
    }

    /**
     * Tests function in Acl Allow Method
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12004
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-07-22
     */
    public function testIssue12004(UnitTester $I)
    {
        $acl = new Memory();

        $acl->setDefaultAction(Acl::DENY);

        $operationGuest      = new Operation("guest");
        $operationUser       = new Operation("user");
        $operationAdmin      = new Operation("admin");
        $operationSuperAdmin = new Operation("superadmin");

        $acl->addOperation($operationGuest);
        $acl->addOperation($operationUser, $operationGuest);
        $acl->addOperation($operationAdmin, $operationUser);
        $acl->addOperation($operationSuperAdmin, $operationAdmin);

        $acl->addSubject("payment", ["paypal", "facebook",]);

        $acl->allow($operationGuest->getName(), "payment", "paypal");
        $acl->allow($operationGuest->getName(), "payment", "facebook");
        $acl->allow($operationUser->getName(), "payment", "*");

        $actual = $acl->isAllowed($operationUser->getName(), "payment", "notSet");
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($operationUser->getName(), "payment", "*");
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($operationAdmin->getName(), "payment", "notSet");
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($operationAdmin->getName(), "payment", "*");
        $I->assertTrue($actual);
    }

    /**
     * Tests acl with adding new rule for operation after adding wildcard rule
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/2648
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-10-01
     */
    public function testWildCardLastOperation(UnitTester $I)
    {
        $acl = new Memory();
        $acl->addOperation(new Operation("Guests"));
        $acl->addSubject(new Subject('Post'), ['index', 'update', 'create']);

        $acl->allow('Guests', 'Post', 'create');
        $acl->allow('*', 'Post', 'index');
        $acl->allow('Guests', 'Post', 'update');

        $actual = $acl->isAllowed('Guests', 'Post', 'create');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Guests', 'Post', 'index');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Guests', 'Post', 'update');
        $I->assertTrue($actual);
    }

    /**
     * Tests adding wildcard rule second time
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/2648
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-10-01
     */
    public function testWildCardSecondTime(UnitTester $I)
    {
        $acl = new Memory();
        $acl->addOperation(new Operation("Guests"));
        $acl->addSubject(new Subject('Post'), ['index', 'update', 'create']);

        $acl->allow('Guests', 'Post', 'create');
        $acl->allow('*', 'Post', 'index');
        $acl->allow('*', 'Post', 'update');

        $actual = $acl->isAllowed('Guests', 'Post', 'create');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Guests', 'Post', 'index');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Guests', 'Post', 'update');
        $I->assertTrue($actual);
    }


    /**
     * Tests negation of multiple inherited operations
     *
     *
     * @author  cq-z <64899484@qq.com>
     * @since   2018-10-10
     */
    public function testAclNegationOfMultipleInheritedOperations(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::DENY);

        $acl->addOperation('Guests');
        $acl->addOperation('Guests2');
        $acl->addOperation('Members', ['Guests', 'Guests2']);

        $acl->addSubject('Login', ['help', 'index']);

        $acl->allow('Guests', 'Login', '*');
        $acl->deny('Guests2', 'Login', ['help']);
        $acl->deny('Members', 'Login', ['index']);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'index');
        $I->assertFalse($actual);

        $actual = (bool) $acl->isAllowed('Guests', 'Login', 'help');
        $I->assertTrue($actual);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'help');
        $I->assertTrue($actual);
    }

    /**
     * Tests negation of multilayer inherited operations
     *
     *
     * @author  cq-z <64899484@qq.com>
     * @since   2018-10-10
     */
    public function testAclNegationOfMultilayerInheritedOperations(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::DENY);

        $acl->addOperation('Guests1');
        $acl->addOperation('Guests12', 'Guests1');
        $acl->addOperation('Guests2');
        $acl->addOperation('Guests22', 'Guests2');
        $acl->addOperation('Members', ['Guests12', 'Guests22']);

        $acl->addSubject('Login', ['help', 'index']);
        $acl->addSubject('Logout', ['help', 'index']);

        $acl->allow('Guests1', 'Login', '*');
        $acl->deny('Guests12', 'Login', ['help']);

        $acl->deny('Guests2', 'Logout', '*');
        $acl->allow('Guests22', 'Logout', ['index']);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'index');
        $I->assertTrue($actual);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'help');
        $I->assertFalse($actual);

        $actual = (bool) $acl->isAllowed('Members', 'Logout', 'help');
        $I->assertFalse($actual);

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'index');
        $I->assertTrue($actual);
    }
}
