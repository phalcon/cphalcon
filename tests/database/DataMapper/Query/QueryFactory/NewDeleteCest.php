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
use Phalcon\DataMapper\Query\Delete;
use Phalcon\DataMapper\Query\QueryFactory;

class NewDeleteCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\QueryFactory :: newDelete()
     *
     * @since  2020-01-20
     */
    public function dMQueryQueryFactoryNewDelete(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\QueryFactory - newDelete()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $delete     = $factory->newDelete($connection);
        $I->assertInstanceOf(Delete::class, $delete);
    }
}
