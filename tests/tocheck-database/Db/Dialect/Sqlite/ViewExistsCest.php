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

namespace Phalcon\Tests\Integration\Db\Dialect\Sqlite;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Sqlite;
use function is_string;

class ViewExistsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: viewExists()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getViewExistsFixtures
     */
    public function dbDialectSqliteViewExists(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Sqlite - viewExists()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Sqlite();

        $actual = $dialect->viewExists(
            'view',
            $schema
        );

        $I->assertTrue(is_string($actual));

        $I->assertEquals($expected, $actual);
    }

    protected function getViewExistsFixtures(): array
    {
        return [
            [
                null,
                'SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END ' .
                "FROM sqlite_master WHERE type='view' AND tbl_name='view'",
            ],

            [
                'schema',
                'SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END ' .
                "FROM sqlite_master WHERE type='view' AND tbl_name='view'",
            ],
        ];
    }
}
