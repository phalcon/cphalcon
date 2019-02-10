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

namespace Phalcon\Test\Unit\Config\Adapter\Grouped;

use UnitTester;

/**
 * Class SetStateCest
 */
class SetStateCest
{
    /**
     * Tests Phalcon\Config\Adapter\Grouped :: __set_state()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function configAdapterGroupedSetState(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Grouped - __set_state()');
        $I->skipTest('Need implementation');
    }
}
