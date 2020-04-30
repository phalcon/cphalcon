<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\Mvc\Model\Row;

use DatabaseTester;
use Phalcon\Mvc\Model\Row;

/**
 * Class SetDirtyStateCest
 */
class SetDirtyStateCest
{
    /**
     * Tests Phalcon\Mvc\Model\Row :: setDirtyState()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function mvcModelRowSetDirtyState(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Row - setDirtyState()');

        $row = new Row();

        $I->assertFalse($row->setDirtyState(0));
        $I->assertFalse($row->setDirtyState(1));
    }
}
