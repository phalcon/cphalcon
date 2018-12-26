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
 * Class GetActiveSubjectCest
 */
class GetActiveSubjectCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveSubject() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetActiveSubjectDefault(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveSubject() - default');
        $acl = new Memory();
        $actual   = $acl->getActiveSubject();
        $I->assertNull($actual);
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getActiveSubject()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetActiveSubject(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getActiveSubject()');
        $acl = new Memory();
        $acl->setDefaultAction(Acl::DENY);

        $acl->addOperation('Guests');
        $acl->addSubject('Login', ['help', 'index']);

        $acl->allow('Guests', 'Login', '*');
        $actual = $acl->isAllowed('Guests', 'Login', 'index');
        $I->assertTrue($actual);

        $expected = 'Login';
        $actual   = $acl->getActiveSubject();
        $I->assertEquals($expected, $actual);
    }
}
