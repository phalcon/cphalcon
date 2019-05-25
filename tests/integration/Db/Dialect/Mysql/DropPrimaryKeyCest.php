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

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Mysql;

class DropPrimaryKeyCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: dropPrimaryKey()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     *
     * @dataProvider getDropPrimaryKeyFixtures
     */
    public function testDropPrimaryKey(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Mysql - dropPrimaryKey()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Mysql();

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
                'ALTER TABLE `table` DROP PRIMARY KEY',
            ],

            [
                'schema',
                'ALTER TABLE `schema`.`table` DROP PRIMARY KEY',
            ],
        ];
    }
}
