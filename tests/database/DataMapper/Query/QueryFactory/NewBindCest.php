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
use Phalcon\DataMapper\Query\Bind;
use Phalcon\DataMapper\Query\QueryFactory;

class NewBindCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\QueryFactory :: newBind()
     *
     * @since  2020-01-20
     */
    public function dMQueryQueryFactoryNewBind(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\QueryFactory - newBind()');

        $factory = new QueryFactory();
        $bind    = $factory->newBind();
        $I->assertInstanceOf(Bind::class, $bind);
    }
}
