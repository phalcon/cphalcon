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
 * Class GetActiveAccessCest
 */
class GetActiveAccessCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveAccess() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetActiveAccessDefault(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveAccess() - default');
        $acl    = new Memory();
        $actual = $acl->getActiveAccess();
        $I->assertNull($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveAccess() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetActiveAccess(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveAccess()');
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);

        $acl->addRole('Guests');
        $acl->addComponent('Login', ['help', 'index']);

        $acl->allow('Guests', 'Login', '*');
        $actual = $acl->isAllowed('Guests', 'Login', 'index');
        $I->assertTrue($actual);

        $expected = 'index';
        $actual   = $acl->getActiveAccess();
        $I->assertEquals($expected, $actual);
    }
}
