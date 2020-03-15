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

namespace Phalcon\Test\Database\DataMapper\Query\Bind;

use DatabaseTester;
use PDO;
use Phalcon\DataMapper\Query\Bind;
use Phalcon\DataMapper\Query\QueryFactory;

class BindInlineCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Bind :: bindInline()
     *
     * @since  2020-01-20
     */
    public function dMQueryBindBindInline(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Bind - bindInline()');

        $connection = $I->getDataMapperConnection();
        $bind       = new Bind();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_customers')
            ->where('inv_cst_id = ', 1)
        ;

        $expected = [];
        $actual   = $bind->toArray();
        $I->assertEquals($expected, $actual);

        $bind->bindInline("one");

        $expected = [
            "__1__" => ["one", 2],
        ];
        $actual   = $bind->toArray();
        $I->assertEquals($expected, $actual);

        $bind->bindInline(true, PDO::PARAM_BOOL);

        $expected = [
            "__1__" => ["one", 2],
            "__2__" => [1, 5],
        ];
        $actual   = $bind->toArray();
        $I->assertEquals($expected, $actual);

        $bind->bindInline(["six", "seven", 8, 9]);

        $expected = [
            "__1__" => ["one", 2],
            "__2__" => [1, 5],
            "__3__" => ["six", 2],
            "__4__" => ["seven", 2],
            "__5__" => [8, 1],
            "__6__" => [9, 1],
        ];
        $actual   = $bind->toArray();
        $I->assertEquals($expected, $actual);

        $expected = '(SELECT * FROM co_customers WHERE inv_cst_id = :__1__)';
        $actual   = $bind->bindInline($select);
        $I->assertEquals($expected, $actual);
    }
}
