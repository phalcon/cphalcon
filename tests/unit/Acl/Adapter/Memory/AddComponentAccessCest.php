<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use Phalcon\Acl\Exception;
use UnitTester;

/**
 * Class AddComponentAccessCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class AddComponentAccessCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addComponentAccess()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddComponentAccess(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addComponentAccess()');

        $acl = new Memory();

        $component = new Component('Customer', 'Customer component');
        $added     = $acl->addComponent(
            'Customer',
            ['index']
        );

        $accessAdded = $acl->addComponentAccess(
            'Customer',
            ['new']
        );

        $I->assertTrue($accessAdded);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addComponentAccess() - unknown
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddComponentAccessUnknown(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addComponentAccess() - unknown');

        $I->expectThrowable(
            new Exception("Component 'Post' does not exist in the ACL"),
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddComponentAccessWrongAccessList(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addComponentAccess() - wrong access list');

        $I->expectThrowable(
            new Exception('Invalid value for the accessList'),
            function () {
                $acl  = new Memory();
                $post = new Component('Post');

                $acl->addComponent($post, ['update']);
                $acl->addComponentAccess('Post', 123);
            }
        );
    }
}
