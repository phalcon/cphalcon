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

namespace Phalcon\Test\Database\DataMapper\Query\QueryFactory;

use DatabaseTester;
use Phalcon\DataMapper\Query\Insert;
use Phalcon\DataMapper\Query\QueryFactory;

class NewInsertCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\QueryFactory :: newInsert()
     *
     * @since  2020-01-20
     */
    public function dMQueryQueryFactoryNewInsert(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\QueryFactory - newInsert()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $insert     = $factory->newInsert($connection);
        $I->assertInstanceOf(Insert::class, $insert);
    }
}
