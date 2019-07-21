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
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class AddPrimaryKeyCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: addPrimaryKey()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     *
     * @dataProvider getAddPrimaryKeyFixtures
     */
    public function dbDialectPostgresqlAddPrimaryKey(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Db\Dialect\Postgresql - addPrimaryKey()");

        $schema    = $example[0];
        $reference = $example[1];
        $expected  = $example[2];

        $dialect = new Postgresql();

        $indexes = $this->getIndexes();

        $actual = $dialect->addPrimaryKey('table', $schema, $indexes[$reference]);

        $I->assertEquals($expected, $actual);
    }

    protected function getAddPrimaryKeyFixtures(): array
    {
        return [
            [
                '',
                'PRIMARY',
                'ALTER TABLE "table" ADD CONSTRAINT "table_PRIMARY" PRIMARY KEY ("column3")',
            ],
            [
                'schema',
                'PRIMARY',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "table_PRIMARY" PRIMARY KEY ("column3")',
            ],
        ];
    }
}
