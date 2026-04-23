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

namespace Phalcon\Tests\Database\Mvc\Model;

use PDO;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\StringFieldMigration;
use Phalcon\Tests\Support\Models\ModelWithStringField;
use Phalcon\Tests\Support\Traits\DiTrait;

/**
 * @group phql
 */
final class NotNullEmptyStringTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16426
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-23
     *
     * @group  mysql
     * @group  sqlite
     * @group  pgsql
     */
    public function testNotNullVarcharAcceptsEmptyString(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        (new StringFieldMigration($connection, false))->create();

        $model        = new ModelWithStringField();
        $model->field = '';

        $result = $model->create();

        $this->assertTrue($result, implode(', ', array_map(fn($m) => $m->getMessage(), $model->getMessages())));
        $this->assertCount(0, $model->getMessages());
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16426
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-23
     *
     * @group  mysql
     * @group  sqlite
     * @group  pgsql
     */
    public function testNotNullVarcharRejectsNull(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        (new StringFieldMigration($connection, false))->create();

        $model        = new ModelWithStringField();
        $model->field = null;

        $result = $model->create();

        $this->assertFalse($result);
        $this->assertCount(1, $model->getMessages());
        $this->assertSame('field is required', $model->getMessages()[0]->getMessage());
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16426
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-23
     *
     * @group  mysql
     * @group  sqlite
     * @group  pgsql
     */
    public function testNotNullVarcharAcceptsNonEmptyString(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        (new StringFieldMigration($connection, false))->create();

        $model        = new ModelWithStringField();
        $model->field = 'hello';

        $result = $model->create();

        $this->assertTrue($result);
        $this->assertCount(0, $model->getMessages());
    }
}
