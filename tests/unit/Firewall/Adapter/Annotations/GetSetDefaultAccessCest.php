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

namespace Phalcon\Test\Unit\Firewall\Adapter\Annotations;

use Phalcon\Acl as PhAcl;
use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Firewall\Adapter\Annotations;
use UnitTester;

class GetSetDefaultAccessCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Annotations ::
     * getDefaultAccess()/setDefaultAccess()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-12
     */
    public function firewallAdapterAnnotationsGetSetDefaultAccess(UnitTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Annotations - getDefaultAccess()/setDefaultAccess()');

        $firewall = new Annotations(new Memory());
        $firewall->setDefaultAccess(PhAcl::ALLOW);

        $actual = $firewall->getDefaultAccess();
        $I->assertEquals(PhAcl::ALLOW, $actual);
    }
}
