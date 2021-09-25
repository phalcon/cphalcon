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

namespace Phalcon\Tests\Database\DataMapper\Query\QueryFactory;

use DatabaseTester;
use Phalcon\DataMapper\Query\QueryFactory;
use Phalcon\DataMapper\Query\Select;

class NewSelectCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\QueryFactory :: newSelect()
     *
     * @since  2020-01-20
     */
    public function dMQueryQueryFactoryNewSelect(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\QueryFactory - newSelect()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);
        $I->assertInstanceOf(Select::class, $select);
    }
}
