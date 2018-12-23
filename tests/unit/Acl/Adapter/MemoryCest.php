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
use Phalcon\Acl\Subject;
use Phalcon\Acl\Operation;
use Phalcon\Test\Fixtures\Acl\TestSubjectAware;
use Phalcon\Test\Fixtures\Acl\TestOperationAware;
use Phalcon\Test\Fixtures\Acl\TestOperationSubjectAware;
use PHPUnit\Framework\Exception;
use UnitTester;
use Closure;

class MemoryCest
{

    /**
     * Tests the addOperation for the same operation twice
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddOperationTwiceReturnsFalse(UnitTester $I)
    {
        $acl     = new Memory();
        $aclOperation = new Operation('Administrators', 'Super User access');

        $acl->addOperation($aclOperation);
        $actual = $acl->addOperation($aclOperation);
        $I->assertFalse($actual);
    }

    /**
     * Tests the addOperation for the same operation twice by key
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddOperationTwiceByKeyReturnsFalse(UnitTester $I)
    {
        $acl     = new Memory();
        $aclOperation = new Operation('Administrators', 'Super User access');

        $acl->addOperation($aclOperation);
        $actual = $acl->addOperation('Administrators');
        $I->assertFalse($actual);
    }

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
     * Tests the isOperation with wrong keyword
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclIsOperationWithWrongKeyReturnsFalse(UnitTester $I)
    {
        $acl    = new Memory();
        $actual = $acl->isOperation('Wrong');
        $I->assertFalse($actual);
    }

    /**
     * Tests the ACL objects default action
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclObjectsWithDefaultAction(UnitTester $I)
    {
        $acl         = new Memory();
        $aclOperation     = new Operation('Administrators', 'Super User access');
        $aclSubject = new Subject('Customers', 'Customer management');

        $acl->setDefaultAction(Acl::DENY);

        $acl->addOperation($aclOperation);
        $acl->addSubject($aclSubject, ['search', 'destroy']);

        $expected = Acl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $I->assertEquals($expected, $actual);

        $acl         = new Memory();
        $aclOperation     = new Operation('Administrators', 'Super User access');
        $aclSubject = new Subject('Customers', 'Customer management');

        $acl->setDefaultAction(Acl::DENY);

        $acl->addOperation($aclOperation);
        $acl->addSubject($aclSubject, ['search', 'destroy']);

        $expected = Acl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests the ACL objects
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclObjects(UnitTester $I)
    {
        $acl         = new Memory();
        $aclOperation     = new Operation('Administrators', 'Super User access');
        $aclSubject = new Subject('Customers', 'Customer management');

        $acl->setDefaultAction(Acl::DENY);

        $acl->addOperation($aclOperation);
        $acl->addSubject($aclSubject, ['search', 'destroy']);

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $expected = Acl::ALLOW;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $I->assertEquals($expected, $actual);

        $acl         = new Memory();
        $aclOperation     = new Operation('Administrators', 'Super User access');
        $aclSubject = new Subject('Customers', 'Customer management');

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

        $acl         = new Memory();
        $aclOperation     = new Operation('Administrators', 'Super User access');
        $aclSubject = new Subject('Customers', 'Customer management');

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
     * Tests ACL Subjects with numeric values
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/1513
     *
     * @author  Phalcon Team <team@phalconphp.com>
     * @since   2014-10-04
     */
    public function testAclSubjectsWithNumericValues(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::DENY);

        $acl->addOperation(new Operation('11'));
        $acl->addSubject(new Subject('11'), ['index']);

        $actual = $acl->isSubject('11');
        $I->assertTrue($actual);
    }

    /**
     * Tests function in Acl Allow Method
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/11235
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2015-12-16
     */
    public function testAclAllowFunction(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::DENY);
        $acl->addOperation('Guests');
        $acl->addOperation('Members', 'Guests');
        $acl->addOperation('Admins', 'Members');
        $acl->addSubject('Post', ['update']);

        $guest         = new TestOperationAware(1, 'Guests');
        $member        = new TestOperationAware(2, 'Members');
        $anotherMember = new TestOperationAware(3, 'Members');
        $admin         = new TestOperationAware(4, 'Admins');
        $model         = new TestSubjectAware(2, 'Post');

        $acl->deny('Guests', 'Post', 'update');
        $acl->allow('Members', 'Post', 'update', function (TestOperationAware $user, TestSubjectAware $model) {
            return $user->getId() == $model->getUser();
        });
        $acl->allow('Admins', 'Post', 'update');

        $actual = $acl->isAllowed($guest, $model, 'update');
        $I->assertFalse($actual);

        $actual = $acl->isAllowed($member, $model, 'update');
        $I->assertTrue($actual);

        $actual = $acl->isAllowed($anotherMember, $model, 'update');
        $I->assertFalse($actual);

        $actual = $acl->isAllowed($admin, $model, 'update');
        $I->assertTrue($actual);
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
     * Tests function in Acl Allow Method without arguments
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12094
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2016-06-05
     */
    public function testAclAllowFunctionNoArguments(UnitTester $I)
    {
        $acl = new Memory;
        $acl->setDefaultAction(Acl::ALLOW);
        $acl->setNoArgumentsDefaultAction(Acl::DENY);
        $acl->addOperation('Guests');
        $acl->addOperation('Members', 'Guests');
        $acl->addOperation('Admins', 'Members');
        $acl->addSubject('Post', ['update']);

        $guest         = new TestOperationAware(1, 'Guests');
        $member        = new TestOperationAware(2, 'Members');
        $anotherMember = new TestOperationAware(3, 'Members');
        $admin         = new TestOperationAware(4, 'Admins');
        $model         = new TestSubjectAware(2, 'Post');

        $acl->allow('Guests', 'Post', 'update', function ($parameter) {
            return $parameter % 2 == 0;
        });
        $acl->allow('Members', 'Post', 'update', function ($parameter) {
            return $parameter % 2 == 0;
        });
        $acl->allow('Admins', 'Post', 'update');

        $actual = @$acl->isAllowed($guest, $model, 'update');
        $I->assertFalse($actual);
        $actual = @$acl->isAllowed($member, $model, 'update');
        $I->assertFalse($actual);
        $actual = @$acl->isAllowed($anotherMember, $model, 'update');
        $I->assertFalse($actual);
        $actual = @$acl->isAllowed($admin, $model, 'update');
        $I->assertTrue($actual);
    }

    /**
     * Tests function in Acl Allow Method without arguments
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12094
     * @author                   Wojciech Slawski <jurigag@gmail.com>
     * @since                    2016-06-05
     */
    public function testAclAllowFunctionNoArgumentsWithWarning(UnitTester $I)
    {
        $I->expectThrowable(
            new Exception(
                "You didn't provide any parameters when check Guests can " .
                "update Post. We will use default action when no arguments.",
                1024
            ),
            function () {
                $acl = new Memory;
                $acl->setDefaultAction(Acl::ALLOW);
                $acl->setNoArgumentsDefaultAction(Acl::DENY);
                $acl->addOperation('Guests');
                $acl->addOperation('Members', 'Guests');
                $acl->addOperation('Admins', 'Members');
                $acl->addSubject('Post', ['update']);

                $guest         = new TestOperationAware(1, 'Guests');
                $member        = new TestOperationAware(2, 'Members');
                $anotherMember = new TestOperationAware(3, 'Members');
                $admin         = new TestOperationAware(4, 'Admins');
                $model         = new TestSubjectAware(2, 'Post');

                $acl->allow('Guests', 'Post', 'update', function ($parameter) {
                    return $parameter % 2 == 0;
                });
                $acl->allow('Members', 'Post', 'update', function ($parameter) {
                    return $parameter % 2 == 0;
                });
                $acl->allow('Admins', 'Post', 'update');

                $actual = $acl->isAllowed($guest, $model, 'update');
                $I->assertFalse($actual);
                $actual = $acl->isAllowed($member, $model, 'update');
                $I->assertFalse($actual);
                $actual = $acl->isAllowed($anotherMember, $model, 'update');
                $I->assertFalse($actual);
                $actual = $acl->isAllowed($admin, $model, 'update');
                $I->assertTrue($actual);
            }
        );
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
     * Tests adding wildcard rule second time
     *
     * @issue   https://github.com/phalcon/cphalcon/issues/12573
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-01-25
     */
    public function testDefaultAction(UnitTester $I)
    {
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);
        $acl->addSubject(new Acl\Subject('Post'), ['index', 'update', 'create']);
        $acl->addOperation(new Operation('Guests'));

        $acl->allow('Guests', 'Post', 'index');
        $actual = $acl->isAllowed('Guests', 'Post', 'index');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed('Guests', 'Post', 'update');
        $I->assertFalse($actual);
    }

    /**
     * Tests operation and subject objects as isAllowed parameters
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function testOperationSubjectObjects(UnitTester $I)
    {
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);
        $operation     = new Operation('Guests');
        $subject = new Subject('Post');
        $acl->addOperation($operation);
        $acl->addSubject($subject, ['index', 'update', 'create']);

        $acl->allow('Guests', 'Post', 'index');

        $actual = $acl->isAllowed($operation, $subject, 'index');
        $I->assertTrue($actual);
        $actual = $acl->isAllowed($operation, $subject, 'update');
        $I->assertFalse($actual);
    }

    /**
     * Tests operation and subject objects as isAllowed parameters of the same class
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-02-15
     */
    public function testOperationSubjectSameClassObjects(UnitTester $I)
    {
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);
        $operation     = new TestOperationSubjectAware(1, 'User', 'Admin');
        $subject = new TestOperationSubjectAware(2, 'User', 'Admin');
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

    /**
     * Tests checking active key method
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-01-13
     */
    public function testActiveKey(UnitTester $I)
    {
        $acl = new Memory();
        $acl->addOperation(new Operation("Guests"));
        $acl->addSubject(new Subject('Post'), ['index', 'update', 'create']);

        $acl->allow('Guests', 'Post', 'create');
        $I->assertTrue($acl->isAllowed('Guests', 'Post', 'create'));
        $I->assertEquals('Guests!Post!create', $acl->getActiveKey());
    }

    /**
     * Tests checking active function method
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-01-13
     */
    public function testActiveFunction(UnitTester $I)
    {
        $function = function ($a) {
            return true;
        };

        $acl = new Memory();
        $acl->addOperation(new Operation("Guests"));
        $acl->addSubject(new Subject('Post'), ['index', 'update', 'create']);

        $acl->allow('Guests', 'Post', 'create', $function);
        $I->assertTrue($acl->isAllowed('Guests', 'Post', 'create', ['a' => 1]));
        $returnedFunction = $acl->getActiveFunction();

        $I->assertInstanceOf(Closure::class, $returnedFunction);
        $I->assertEquals(1, $function(1));
        $I->assertEquals(1, $acl->getActiveFunctionCustomArgumentsCount());
    }
}
