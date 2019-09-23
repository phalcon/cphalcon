<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use Phalcon\Acl\Exception;
use UnitTester;

class AddComponentAccessCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addComponentAccess()
     *
     * @author Phalcon Team <team@phalcon.io>
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddComponentAccessUnknown(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addComponentAccess() - unknown');

        $I->expectThrowable(
            new Exception("Component 'Post' does not exist in ACL"),
            function () {
                $acl = new Memory();

                $acl->addComponentAccess(
                    'Post',
                    ['update']
                );
            }
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addComponentAccess() - wrong access
     * list
     *
     * @author Phalcon Team <team@phalcon.io>
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

                $acl->addComponent(
                    $post,
                    ['update']
                );

                $acl->addComponentAccess('Post', 123);
            }
        );
    }
}
