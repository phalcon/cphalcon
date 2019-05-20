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

namespace Phalcon\Test\Unit\Firewall\Adapter\Acl;

use UnitTester;

class GetModuleSeparatorCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Acl :: getModuleSeparator()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-12
     */
    public function firewallAdapterAclGetModuleSeparator(UnitTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Acl - getModuleSeparator()');

        $I->skipTest('Need implementation');
    }
}
