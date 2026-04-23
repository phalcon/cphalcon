<?php

/**
 * This file is part of the Phalcon Framework.
 * (c) Phalcon Team <team@phalcon.io>
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use PDOException;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\RecordsTrait;
use Phalcon\Tests\Support\Migrations\RollbackTestMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use RuntimeException;
use Throwable;

/**
 *
 * @group phql
 */
final class RollbackOnExceptionTest extends AbstractDatabaseTestCase
{
    use DiTrait;
    use RecordsTrait;

    /**
     * @var RollbackTestMigration
     */
    private RollbackTestMigration $migration;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $this->migration = new RollbackTestMigration(self::getConnection(), false);
    }

    /**
     * @issue  16604
     * @author noone-silent <lominum@protonmail.com>
     * @since  2024-06-10
     *
     * @group mysql
     * @group pgsql
     */
    public function testMvcModelQueryRollbackOnException(): void
    {
        $this->migration->create();
        $this->migration->clear();

        $this->assertNotInDatabase($this->migration->getTable(), ['name' => 'abc']);
        $this->assertNotInDatabase($this->migration->getTable(), ['name' => 'test 4 OK']);
        $this->assertNotInDatabase($this->migration->getTable(), ['name' => 'test 5 OK']);

        /** @var Manager|null $modelsManager */
        $modelsManager = $this->container->get('modelsManager');
        if ($modelsManager instanceof Manager === false) {
            throw new RuntimeException('Manager not set in di');
        }

        $modelsManager->executeQuery(
            'DELETE FROM \\Phalcon\\Tests\\Support\\Models\\RbTestModel'
        );
        $modelsManager->executeQuery(
            'INSERT INTO \\Phalcon\\Tests\\Support\\Models\\RbTestModel (id, name) VALUES (1, "abc")'
        );
        $modelsManager->executeQuery(
            'INSERT INTO \\Phalcon\\Tests\\Support\\Models\\RbTestModel (id, name) VALUES (2, "abc")'
        );
        $modelsManager->executeQuery(
            'INSERT INTO \\Phalcon\\Tests\\Support\\Models\\RbTestModel (id, name) VALUES (3, "abc")'
        );
        $modelsManager->executeQuery(
            'INSERT INTO \\Phalcon\\Tests\\Support\\Models\\RbTestModel (id, name) VALUES (4, "abc")'
        );
        $modelsManager->executeQuery(
            'INSERT INTO \\Phalcon\\Tests\\Support\\Models\\RbTestModel (id, name) VALUES (5, "abc")'
        );

        $messages = [];

        $messages[] = $this->update(1, 'test 1 OK', $modelsManager);
        $messages[] = $this->update(2, 'test 2 OK', $modelsManager);
        $messages[] = $this->update(3, 'test 3 DATA TRUNCATED ERROR', $modelsManager);
        $messages[] = $this->update(4, 'test 4 OK', $modelsManager);
        $messages[] = $this->update(5, 'test 5 OK', $modelsManager);

        $this->assertEquals('Update test 1 OK', $messages[0]);
        $this->assertEquals('Update test 2 OK', $messages[1]);
        $this->assertNotEquals('Update test 3 OK', $messages[2]);
        $this->assertStringContainsString('PDOException', $messages[2]);
        $this->assertEquals('Update test 4 OK', $messages[3]);
        $this->assertEquals('Update test 5 OK', $messages[4]);

        $this->assertInDatabase($this->migration->getTable(), ['name' => 'test 1 OK']);
        $this->assertInDatabase($this->migration->getTable(), ['name' => 'test 2 OK']);
        $this->assertInDatabase($this->migration->getTable(), ['id' => 1, 'name' => 'abc']);
        $this->assertInDatabase($this->migration->getTable(), ['name' => 'test 4 OK']);
        $this->assertInDatabase($this->migration->getTable(), ['name' => 'test 5 OK']);
    }

    /**
     * @param int     $id
     * @param string  $name
     * @param Manager $modelsManager
     *
     * @return string
     */
    private function update(int $id, string $name, Manager $modelsManager): string
    {
        try {
            $query = 'UPDATE \\Phalcon\\Tests\\Support\\Models\\RbTestModel '
                . 'SET name = :name: WHERE id = :id:';
            $modelsManager->executeQuery($query, ['id' => $id, 'name' => $name]);
            return "Update $name";
        } catch (PDOException $exc) {
            return $exc::class . ' ' . $exc->getMessage();
        } catch (Throwable $exc) {
            return get_class($exc) . ' ' . $exc->getMessage();
        }
    }
}
