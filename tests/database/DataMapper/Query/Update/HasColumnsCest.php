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

namespace Phalcon\Test\Database\DataMapper\Query\Update;

use DatabaseTester;
use Phalcon\DataMapper\Query\QueryFactory;

class HasColumnsCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Update :: hasColumns()
     *
     * @since  2020-01-20
     */
    public function dMQueryUpdateHasColumns(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Update - hasColumns()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $update     = $factory->newUpdate($connection);

        $actual = $update->hasColumns();
        $I->assertFalse($actual);

        $update->columns(['inv_id', 'inv_total']);

        $actual = $update->hasColumns();
        $I->assertTrue($actual);
    }
}
