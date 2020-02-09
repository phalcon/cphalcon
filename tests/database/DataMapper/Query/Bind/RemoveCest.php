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

class RemoveCest
{
    /**
     * Database Tests Phalcon\DataMapper\Query\Bind :: remove()
     *
     * @since  2020-01-20
     */
    public function dMQueryBindRemove(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Query\Bind - remove()');

        $bind = new Bind();

        $expected = [];
        $actual   = $bind->toArray();
        $I->assertEquals($expected, $actual);

        $bind->bindInline("one");
        $bind->bindInline(true, PDO::PARAM_BOOL);

        $expected = [
            "__1__" => ["one", 2],
            "__2__" => [1, 5],
        ];
        $actual   = $bind->toArray();
        $I->assertEquals($expected, $actual);

        $bind->remove("__1__");

        $expected = [
            "__2__" => [1, 5],
        ];
        $actual   = $bind->toArray();
        $I->assertEquals($expected, $actual);
    }
}
