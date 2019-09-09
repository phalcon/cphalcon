<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use UnitTester;

class AddInheritCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: addInherit()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryAddInherit(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - addInherit()');

        $I->skipTest('Need implementation');
    }
}
