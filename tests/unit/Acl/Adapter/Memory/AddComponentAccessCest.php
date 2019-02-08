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
use Phalcon\Acl\Component;
use UnitTester;

/**
 * Class AddComponentAccessCest
 */
class AddComponentAccessCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addComponentAccess()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddComponentAccess(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addComponentAccess()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addComponentAccess() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddComponentAccessUnknown(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addComponentAccess() - unknown');
        $I->expectThrowable(
            new Exception("Component 'Post' does not exist in ACL"),
            function () {
                $acl = new Memory();
                $acl->addComponentAccess('Post', ['update']);
            }
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addComponentAccess() - wrong access
     * list
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddComponentAccessWrongAccessList(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addComponentAccess() - wrong access list');
        $I->expectThrowable(
            new Exception('Invalid value for accessList'),
            function () {
                $acl  = new Memory();
                $post = new Component('Post');
                $acl->addComponent($post, ['update']);
                $acl->addComponentAccess('Post', 123);
            }
        );
    }
}
