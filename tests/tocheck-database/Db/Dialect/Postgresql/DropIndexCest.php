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

namespace Phalcon\Tests\Integration\Db\Dialect\Postgresql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Postgresql;

class DropIndexCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: dropIndex()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-05-25
     *
     * @dataProvider getDropIndexFixtures
     */
    public function dbDialectPostgresqlDropIndex(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - dropIndex()');

        $schema   = $example[0];
        $index    = $example[1];
        $expected = $example[2];

        $dialect = new Postgresql();

        $actual = $dialect->dropIndex('table', $schema, $index);

        $I->assertEquals($expected, $actual);
    }

    protected function getDropIndexFixtures(): array
    {
        return [
            [
                '',
                'index1',
                'DROP INDEX "index1"',
            ],
            [
                'schema',
                'index1',
                'DROP INDEX "index1"',
            ],
        ];
    }
}
