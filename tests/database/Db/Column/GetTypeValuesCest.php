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

namespace Phalcon\Tests\Database\Db\Column;

use DatabaseTester;
use Phalcon\Tests\Fixtures\Traits\DbTrait;

class GetTypeValuesCest
{
    use DbTrait;

    /**
     * Tests Phalcon\Db\Column :: getTypeValues()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function dbColumnGetTypeValues(DatabaseTester $I)
    {
        $I->wantToTest('Db\Column - getTypeValues()');

        $columns         = $this->getColumnsArray();
        $expectedColumns = $this->getColumnsObjects();

        foreach ($expectedColumns as $index => $column) {
            $I->assertEquals(
                $columns[$index]['typeValues'],
                $column->getTypeValues()
            );
        }
    }
}
