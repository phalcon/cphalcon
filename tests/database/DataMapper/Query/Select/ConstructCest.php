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

namespace Phalcon\Tests\Database\DataMapper\Query\Select;

use DatabaseTester;
use Phalcon\DataMapper\Query\Bind;
use Phalcon\DataMapper\Query\Select;

class ConstructCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Select :: __construct()
     *
     * @since  2020-01-20
     */
    public function dMQuerySelectConstruct(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Select - __construct()');

        $connection = $I->getDataMapperConnection();
        $bind       = new Bind();
        $select     = new Select($connection, $bind);

        $I->assertInstanceOf(Select::class, $select);
    }
}
