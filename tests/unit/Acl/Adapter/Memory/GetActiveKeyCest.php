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
use Phalcon\Acl\Role;
use Phalcon\Acl\Component;
use UnitTester;

/**
 * Class GetActiveKeyCest
 */
class GetActiveKeyCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveKey()
     *
     * @param UnitTester $I
     *
     * @author  Wojciech Slawski <jurigag@gmail.com>
     * @since   2017-01-13
     */
    public function aclAdapterMemoryGetActiveKey(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveKey()');
        $acl = new Memory();
        $acl->addRole(new Role('Guests'));
        $acl->addComponent(new Component('Post'), ['index', 'update', 'create']);

        $acl->allow('Guests', 'Post', 'create');
        $I->assertTrue($acl->isAllowed('Guests', 'Post', 'create'));

        $expected = 'Guests!Post!create';
        $actual   = $acl->getActiveKey();
        $I->assertEquals($expected, $actual);
    }
}
