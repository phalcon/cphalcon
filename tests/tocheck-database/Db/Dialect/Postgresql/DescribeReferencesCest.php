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

class DescribeReferencesCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: describeReferences()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getDescribeReferencesFixtures
     */
    public function dbDialectPostgresqlDescribeReferences(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - describeReferences()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Postgresql();

        $actual = $dialect->describeReferences(
            'table',
            $schema
        );

        $I->assertEquals($expected, $actual);
    }

    protected function getDescribeReferencesFixtures(): array
    {
        return [
            [
                null,
                rtrim(
                    file_get_contents(
                        dataDir('fixtures/Db/postgresql/example7.sql')
                    )
                ),
            ],
            [
                'schema',
                rtrim(
                    file_get_contents(
                        dataDir('fixtures/Db/postgresql/example8.sql')
                    )
                ),
            ],
        ];
    }
}
