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
use Phalcon\DataMapper\Query\QueryFactory;
use Phalcon\DataMapper\Query\Update;

class NewUpdateCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\QueryFactory :: newUpdate()
     *
     * @since  2020-01-20
     */
    public function dMQueryQueryFactoryNewUpdate(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\QueryFactory - newUpdate()');

        $connection = $I->getDataMapperConnection();
        $factory    = new QueryFactory();
        $update     = $factory->newUpdate($connection);
        $I->assertInstanceOf(Update::class, $update);
    }
}
