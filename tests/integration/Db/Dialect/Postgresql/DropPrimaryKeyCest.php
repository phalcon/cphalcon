<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Dialect\Postgresql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Postgresql;

class DropPrimaryKeyCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: dropPrimaryKey()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     *
     * @dataProvider getDropPrimaryKeyFixtures
     */
    public function testDropPrimaryKey(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - dropPrimaryKey()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Postgresql();

        $actual = $dialect->dropPrimaryKey(
            'table',
            $schema
        );

        $I->assertEquals($expected, $actual);
    }

    protected function getDropPrimaryKeyFixtures(): array
    {
        return [
            [
                '',
                'ALTER TABLE "table" DROP CONSTRAINT "table_PRIMARY"',
            ],

            [
                'schema',
                'ALTER TABLE "schema"."table" DROP CONSTRAINT "table_PRIMARY"',
            ],
        ];
    }
}
