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

use UnitTester;

class GetDispatcherCest
{
    /**
     * Tests Phalcon\Firewall\Adapter\Annotations :: getDispatcher()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-12
     */
    public function firewallAdapterAnnotationsGetDispatcher(UnitTester $I)
    {
        $I->wantToTest('Firewall\Adapter\Annotations - getDispatcher()');

        $I->skipTest('Need implementation');
    }
}
