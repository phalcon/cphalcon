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

class GetSetDefaultActionCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getDefaultAction()/setDefaultAction()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetSetDefaultAction(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getDefaultAction()/setDefaultAction()');

        $acl = new Memory();

        $acl->setDefaultAction(
            Acl::ALLOW
        );

        $I->assertEquals(
            Acl::ALLOW,
            $acl->getDefaultAction()
        );
    }

    /**
     * Tests Phalcon\Acl\Adapter\Memory :: getDefaultAction()/setDefaultAction()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryGetSetDefaultActionDefault(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - getDefaultAction()/setDefaultAction() - default');

        $acl = new Memory();

        $I->assertEquals(
            Acl::DENY,
            $acl->getDefaultAction()
        );
    }
}
