<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Dialect\Sqlite;

use Phalcon\Test\Fixtures\Traits\DialectTrait;
use IntegrationTester;

class AddForeignKeyCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: addForeignKey()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testAddForeignKey(IntegrationTester $I)
    {
        $data = $this->getAddForeignKeyFixtures();
        foreach ($data as $item) {
            $schema     = $item[0];
            $reference  = $item[1];
            $expected   = $item[2];
            $dialect    = $this->getDialectSqlite();
            $references = $this->getReferences();
            $actual     = $dialect->addForeignKey('table', $schema, $references[$reference]);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @return array
     */
    protected function getAddForeignKeyFixtures(): array
    {
        return [];
    }
}
