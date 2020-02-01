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

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Component;
use UnitTester;

class GetComponentsCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getComponents()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetComponents(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getComponents()');

        $acl = new Memory();

        $component1 = new Component('Posts');
        $component2 = new Component('Tags');

        $acl->addComponent($component1, ['index']);
        $acl->addComponent($component2, ['index']);


        $expected = [$component1, $component2];

        $I->assertEquals(
            $expected,
            $acl->getComponents()
        );
    }
}
