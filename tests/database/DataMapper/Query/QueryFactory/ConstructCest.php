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

class ConstructCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\QueryFactory :: __construct()
     *
     * @since  2020-01-20
     */
    public function dMQueryQueryFactoryConstruct(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\QueryFactory - __construct()');

        $factory = new QueryFactory();
        $I->assertInstanceOf(QueryFactory::class, $factory);
    }
}
