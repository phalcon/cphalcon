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

namespace Phalcon\Test\Database\Db\Column;

use DatabaseTester;
use Phalcon\Test\Fixtures\Traits\Db\MysqlTrait;
use Phalcon\Test\Fixtures\Traits\DbTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class GetDefaultCest
{
    use DbTrait;

    /**
     * Tests Phalcon\Db\Column :: getDefault()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbColumnGetDefault(DatabaseTester $I)
    {
        $I->wantToTest("Db\Column - getDefault()");

        $columns         = $this->getColumnsArray();
        $expectedColumns = $this->getColumnsObjects();

        foreach ($expectedColumns as $index => $column) {
            $I->assertEquals(
                $columns[$index]['default'],
                $column->getDefault()
            );
        }
    }
}
