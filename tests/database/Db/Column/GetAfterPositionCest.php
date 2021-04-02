<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\Db\Column;

use DatabaseTester;
use Phalcon\Test\Fixtures\Traits\DbTrait;

class GetAfterPositionCest
{
    use DbTrait;

    /**
     * Tests Phalcon\Db\Column :: getAfterPosition()
     *
     * @param  DatabaseTester $I
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function dbColumnGetAfterPosition(DatabaseTester $I)
    {
        $I->wantToTest("Db\Column - getAfterPosition()");

        $columns         = $this->getColumnsArray();
        $expectedColumns = $this->getColumnsObjects();

        foreach ($expectedColumns as $index => $column) {
            $I->assertEquals(
                $columns[$index]['after'],
                $column->getAfterPosition()
            );
        }
    }
}
