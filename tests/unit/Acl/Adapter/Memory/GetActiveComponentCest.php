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
use UnitTester;

/**
 * Class GetActiveComponentCest
 */
class GetActiveComponentCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveComponent() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetActiveComponentDefault(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveComponent() - default');
        $acl    = new Memory();
        $actual = $acl->getActiveComponent();
        $I->assertNull($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveComponent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetActiveComponent(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveComponent()');
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole('Guests');
        $acl->addComponent('Login', ['help', 'index']);

        $acl->allow('Guests', 'Login', '*');
        $actual = $acl->isAllowed('Guests', 'Login', 'index');
        $I->assertTrue($actual);

        $expected = 'Login';
        $actual   = $acl->getActiveComponent();
        $I->assertEquals($expected, $actual);
    }
}
