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

namespace Phalcon\Test\Integration\Firewall\Adapter\Annotations;

use IntegrationTester;
use Phalcon\Acl as PhAcl;
use Phalcon\Annotations\Adapter\Memory;
use Phalcon\Firewall\Adapter\Annotations;

class GetSetDefaultAccessCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Annotations ::
     * getDefaultAccess()/setDefaultAccess()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-12
     */
    public function firewallAdapterAnnotationsGetSetDefaultAccess(IntegrationTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Annotations - getDefaultAccess()/setDefaultAccess()');

        $firewall = new Annotations(new Memory());
        $firewall->setDefaultAccess(PhAcl::ALLOW);

        $actual = $firewall->getDefaultAccess();
        $I->assertEquals(PhAcl::ALLOW, $actual);
    }
}
