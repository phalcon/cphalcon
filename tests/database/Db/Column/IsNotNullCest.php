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

class IsNotNullCest
{
    use DbTrait;

    /**
     * Tests Phalcon\Db\Column :: isNotNull()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbColumnIsNotNull(DatabaseTester $I)
    {
        $I->wantToTest("Db\Column - isNotNull()");

        $columns         = $this->getColumnsArray();
        $expectedColumns = $this->getColumnsObjects();

        foreach ($expectedColumns as $index => $column) {
            $I->assertEquals(
                $columns[$index]['notNull'],
                $column->isNotNull()
            );
        }
    }
}
