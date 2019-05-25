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
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class DropIndexCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: dropIndex()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     *
     * @dataProvider getDropIndexFixtures
     */
    public function dbDialectPostgresqlDropIndex(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - dropIndex()');

        $schema   = $example[0];
        $index    = $example[1];
        $expected = $example[2];

        $dialect = $this->getDialectPostgresql();

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
