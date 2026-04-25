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

namespace Phalcon\Tests\Database\Db\Dialect;

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class SavepointTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialectClasses(): array
    {
        return [
            [Mysql::class],
            [Postgresql::class],
            [Sqlite::class],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: createSavepoint
     *
     * @dataProvider getDialectClasses
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectCreateSavepoint(string $dialectClass): void
    {
        $dialect = new $dialectClass();

        $expected = 'SAVEPOINT PH_SAVEPOINT_1';
        $actual   = $dialect->createSavepoint('PH_SAVEPOINT_1');
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: releaseSavepoint
     *
     * @dataProvider getDialectClasses
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectReleaseSavepoint(string $dialectClass): void
    {
        $dialect = new $dialectClass();

        $expected = 'RELEASE SAVEPOINT PH_SAVEPOINT_1';
        $actual   = $dialect->releaseSavepoint('PH_SAVEPOINT_1');
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: rollbackSavepoint
     *
     * @dataProvider getDialectClasses
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectRollbackSavepoint(string $dialectClass): void
    {
        $dialect = new $dialectClass();

        $expected = 'ROLLBACK TO SAVEPOINT PH_SAVEPOINT_1';
        $actual   = $dialect->rollbackSavepoint('PH_SAVEPOINT_1');
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: supportsSavepoints
     *
     * @dataProvider getDialectClasses
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectSupportsSavepoints(string $dialectClass): void
    {
        $dialect = new $dialectClass();

        $this->assertTrue($dialect->supportsSavepoints());
    }

    /**
     * Tests Phalcon\Db\Dialect :: supportsReleaseSavepoints
     *
     * @dataProvider getDialectClasses
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectSupportsReleaseSavepoints(string $dialectClass): void
    {
        $dialect = new $dialectClass();

        $this->assertTrue($dialect->supportsReleaseSavepoints());
    }
}
