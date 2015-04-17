<?php
/**
 * ACLMemoryTest.php
 * \Phalcon\Acl\Adapter\Memory\ACLMemoryTest
 *
 * Tests the \Phalcon\Acl\Adapter\Memory component
 *
 * Phalcon Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Tests\unit\Phalcon\Acl;

use \Phalcon\Acl as PhAcl;
use \PhalconTest\Acl\Adapter\Memory as PhTAclMem;

use \PhalconTest\Acl\Role as PhTAclRole;
use \PhalconTest\Acl\Resource as PhTAclResource;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class ACLMemoryTest extends TBase
{
    /**
     * Tests the ACL constants
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-03
     */
    public function testAclConstants()
    {
        $this->specify(
            "The ACL constants are not correct",
            function () {

                expect(PhAcl::ALLOW)->equals(1);
                expect(PhAcl::DENY)->equals(0);
            }
        );
    }

    /**
     * Tests the setDefaultAction
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclDefaultAction()
    {
        $this->specify(
            'The Acl\Adapter\Memory does not get/set the default action correctly',
            function () {

                $acl = new PhTAclMem();

                $acl->setDefaultAction(PhAcl::ALLOW);

                $expected = PhAcl::ALLOW;
                $actual   = $acl->getDefaultAction();
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the addRole
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddRoleExists()
    {
        $this->specify(
            'Adding a ACL\Role in the ACL does not exist',
            function () {

                $acl     = new PhTAclMem();
                $aclRole = new PhTAclRole('Administrators', 'Super User access');

                $acl->addRole($aclRole);

                $actual = $acl->isRole('Administrators');
                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the addRole for the same role twice
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddRoleTwiceReturnsFalse()
    {
        $this->specify(
            'Acl\Role added twice returns true',
            function () {

                $acl     = new PhTAclMem();
                $aclRole = new PhTAclRole('Administrators', 'Super User access');

                $acl->addRole($aclRole);
                $actual = $acl->addRole($aclRole);

                expect($actual)->false();
            }
        );
    }

    /**
     * Tests the addRole for the same role twice by key
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddRoleTwiceByKeyReturnsFalse()
    {
        $this->specify(
            'Acl\Role added twice by key returns true',
            function () {

                $acl     = new PhTAclMem();
                $aclRole = new PhTAclRole('Administrators', 'Super User access');

                $acl->addRole($aclRole);
                $actual = $acl->addRole('Administrators');

                expect($actual)->false();
            }
        );
    }

    /**
     * Tests the wildcard allow/deny
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclWildcardAllowDeny()
    {
        $this->specify(
            'Acl\Role added twice by key returns true',
            function () {

                $acl     = new PhTAclMem();
                $acl->setDefaultAction(PhAcl::DENY);

                $aclRoles  = [
                    'Admin'  => new PhTAclRole('Admin'),
                    'Users'  => new PhTAclRole('Users'),
                    'Guests' => new PhTAclRole('Guests')
                ];

                $aclResources = [
                    'welcome' => ['index', 'about'],
                    'account' => ['index'],
                ];

                foreach ($aclRoles as $role => $object) {
                    $acl->addRole($object);
                }

                foreach ($aclResources as $resource => $actions) {
                    $acl->addResource(new PhTAclResource($resource), $actions);
                }
                $acl->allow("*", "welcome", "index");

                foreach ($aclRoles as $role => $object) {
                    expect($acl->isAllowed($role, 'welcome', 'index'))->true();
                }

                $acl->deny("*", "welcome", "index");
                foreach ($aclRoles as $role => $object) {
                    expect($acl->isAllowed($role, 'welcome', 'index'))->false();
                }
            }
        );
    }

    /**
     * Tests the isRole with wrong keyword
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclIsRoleWithWrongKeyReturnsFalse()
    {
        $this->specify(
            'Acl\Role added with wrong key returns true in isRole',
            function () {

                $acl     = new PhTAclMem();

                $actual = $acl->isRole('Wrong');

                expect($actual)->false();
            }
        );
    }

    /**
     * Tests the role name
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclRoleName()
    {
        $this->specify(
            'Acl\Role does not exist in Acl',
            function () {

                $acl     = new PhTAclMem();
                $aclRole = new PhTAclRole('Administrators', 'Super User access');

                $acl->addRole($aclRole);

                $actual = $acl->isRole('Administrators');

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the addResource
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclAddResourceExists()
    {
        $this->specify(
            'Acl\Resource does not exist in Acl',
            function () {

                $acl         = new PhTAclMem();
                $aclResource = new PhTAclResource('Customers', 'Customer management');

                $actual = $acl->addResource($aclResource, 'search');

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the resource name
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclResourceName()
    {
        $this->specify(
            'Acl\Resource by name does not exist in the acl',
            function () {

                $acl         = new PhTAclMem();
                $aclResource = new PhTAclResource('Customers', 'Customer management');

                $acl->addResource($aclResource, 'search');

                $actual = $acl->isResource('Customers');

                expect($actual)->true();
            }
        );
    }

    /**
     * Tests the ACL objects default action
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclObjectsWithDefaultAction()
    {
        $this->specify(
            'Acl with default action search does not return correct results',
            function () {

                $acl         = new PhTAclMem();
                $aclRole     = new PhTAclRole('Administrators', 'Super User access');
                $aclResource = new PhTAclResource('Customers', 'Customer management');

                $acl->setDefaultAction(PhAcl::DENY);

                $acl->addRole($aclRole);
                $acl->addResource($aclResource, ['search', 'destroy']);

                $expected = PhAcl::DENY;
                $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            'Acl with default action destroy does not return correct results',
            function () {

                $acl         = new PhTAclMem();
                $aclRole     = new PhTAclRole('Administrators', 'Super User access');
                $aclResource = new PhTAclResource('Customers', 'Customer management');

                $acl->setDefaultAction(PhAcl::DENY);

                $acl->addRole($aclRole);
                $acl->addResource($aclResource, array('search', 'destroy'));

                $expected = PhAcl::DENY;
                $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests the ACL objects
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclObjects()
    {
        $this->specify(
            'Acl search does not return correct results',
            function () {

                $acl         = new PhTAclMem();
                $aclRole     = new PhTAclRole('Administrators', 'Super User access');
                $aclResource = new PhTAclResource('Customers', 'Customer management');

                $acl->setDefaultAction(PhAcl::DENY);

                $acl->addRole($aclRole);
                $acl->addResource($aclResource, ['search', 'destroy']);

                $acl->allow('Administrators', 'Customers', 'search');
                $acl->deny('Administrators', 'Customers', 'destroy');

                $expected = PhAcl::ALLOW;
                $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
                expect($actual)->equals($expected);
            }
        );

        $this->specify(
            'Acl destroy does not return correct results',
            function () {

                $acl         = new PhTAclMem();
                $aclRole     = new PhTAclRole('Administrators', 'Super User access');
                $aclResource = new PhTAclResource('Customers', 'Customer management');

                $acl->setDefaultAction(PhAcl::DENY);

                $acl->addRole($aclRole);
                $acl->addResource($aclResource, array('search', 'destroy'));

                $acl->allow('Administrators', 'Customers', 'search');
                $acl->deny('Administrators', 'Customers', 'destroy');

                $expected = PhAcl::DENY;
                $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests serializing the ACL
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-04
     */
    public function testAclSerialize()
    {
        $this->specify(
            'Acl serialization/unserialization does not return a correct object back',
            function () {

                $filename    = newFileName('acl', 'log');

                $acl         = new PhTAclMem();
                $aclRole     = new PhTAclRole('Administrators', 'Super User access');
                $aclResource = new PhTAclResource('Customers', 'Customer management');

                $acl->addRole($aclRole);
                $acl->addResource($aclResource, ['search', 'destroy']);

                $acl->allow('Administrators', 'Customers', 'search');
                $acl->deny('Administrators', 'Customers', 'destroy');

                $contents = serialize($acl);
                file_put_contents(PATH_CACHE . $filename, $contents);

                $acl = null;

                $contents = file_get_contents(PATH_CACHE . $filename);

                cleanFile(PATH_CACHE, $filename);

                $acl = unserialize($contents);
                $actual = ($acl instanceof \Phalcon\Acl\Adapter\Memory);
                expect($actual)->true();

                $actual = $acl->isRole('Administrators');
                expect($actual)->true();

                $actual = $acl->isResource('Customers');
                expect($actual)->true();

                $expected = PhAcl::ALLOW;
                $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
                expect($actual)->equals($expected);

                $expected = PhAcl::DENY;
                $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
                expect($actual)->equals($expected);
            }
        );
    }

    /**
     * Tests negation of inherited roles
     *
     * @issue   65
     *
     * @author  Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since   2014-10-04
     */
    public function testAclNegationOfInheritedRoles()
    {
        $this->specify(
            'Negation of inherited roles does not return the correct result',
            function () {

                $acl = new PhTAclMem;
                $acl->setDefaultAction(PhAcl::DENY);

                $acl->addRole('Guests');
                $acl->addRole('Members', 'Guests');

                $acl->addResource('Login', array('index'));

                $acl->allow('Guests', 'Login', 'index');
                $acl->deny('Members', 'Login', 'index');

                $actual = (bool)$acl->isAllowed('Members', 'Login', 'index');
                expect($actual)->false();
            }
        );
    }

    /**
     * Tests ACL Resources with numeric values
     *
     * @issue   1513
     *
     * @author  Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since   2014-10-04
     */
    public function testAclResourcesWithNumericValues()
    {
        $this->specify(
            'ACL Resources with numeric values are not set properly',
            function () {

                $acl = new PhTAclMem;
                $acl->setDefaultAction(PhAcl::DENY);

                $acl->addRole(new PhTAclRole('11'));
                $acl->addResource(new PhTAclResource('11'), ['index']);

                $actual = $acl->isResource('11');
                expect($actual)->true();
            }
        );
    }
}
