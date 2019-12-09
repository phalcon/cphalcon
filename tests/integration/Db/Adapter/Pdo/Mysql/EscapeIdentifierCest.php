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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\Db\MysqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class EscapeIdentifierCest
{
    use DiTrait;
    use MysqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: escapeIdentifier()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2016-11-19
     *
     * @dataProvider testEscapeIdentifierProvider
     */
    public function dbAdapterPdoMysqlEscapeIdentifier(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - escapeIdentifier()');

        $identifier = $example['identifier'];
        $expected   = $example['expected'];

        $I->assertEquals(
            $expected,
            $this->connection->escapeIdentifier($identifier)
        );
    }

    private function testEscapeIdentifierProvider(): array
    {
        return [
            [
                'identifier' => 'robots',
                'expected'   => '`robots`',
            ],

            [
                'identifier' => ['schema', 'robots'],
                'expected'   => '`schema`.`robots`',
            ],

            [
                'identifier' => '`robots`',
                'expected'   => '```robots```',
            ],

            [
                'identifier' => ['`schema`', 'rob`ots'],
                'expected'   => '```schema```.`rob``ots`',
            ],
        ];
    }
}
