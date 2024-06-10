<?php

/**
 * This file is part of the Phalcon Framework.
 * (c) Phalcon Team <team@phalcon.io>
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Codeception\Util\Debug;
use DatabaseTester;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Storage\Exception;
use Phalcon\Tests\Fixtures\Migrations\RollbackTestMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Fixtures\Traits\RecordsTrait;
use PDOException;

class RollbackOnExceptionCest
{
    use DiTrait;
    use RecordsTrait;

    /**
     * @var RollbackTestMigration
     */
    private $migration;

    /**
     * Executed before each test
     *
     * @param DatabaseTester $I
     *
     * @return void
     */
    public function _before(DatabaseTester $I): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $I->fail($e->getMessage());
        }

        $this->setDatabase($I);

        $this->migration = new RollbackTestMigration($I->getConnection(), false);
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: mvcModelQueryRollbackOnException() - Issue 16604
     *
     * @param DatabaseTester $I
     *
     * @author noone-silent <lominum@protonmail.com>
     * @since  2024-06-10
     * @issue  16604
     * @group  mysql
     * @group  pgsql
     */
    public function mvcModelQueryRollbackOnException(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model\Query :: mvcModelQueryRollbackOnException() - #16604');

        $this->migration->create();
        $this->migration->clear();

        $I->dontSeeInDatabase($this->migration->getTable(), ['name' => 'abc']);
        $I->dontSeeInDatabase($this->migration->getTable(), ['name' => 'test 4 OK']);
        $I->dontSeeInDatabase($this->migration->getTable(), ['name' => 'test 5 OK']);

        /** @var Manager|null $modelsManager */
        $modelsManager = $this->container->get('modelsManager');
        if ($modelsManager instanceof Manager === false) {
            throw new \RuntimeException('Manager not set in di');
        }

        $modelsManager->executeQuery('DELETE FROM \\Phalcon\\Tests\\Models\\RbTestModel');
        $modelsManager->executeQuery('INSERT INTO \\Phalcon\\Tests\\Models\\RbTestModel (id, name) VALUES (1, "abc")');
        $modelsManager->executeQuery('INSERT INTO \\Phalcon\\Tests\\Models\\RbTestModel (id, name) VALUES (2, "abc")');
        $modelsManager->executeQuery('INSERT INTO \\Phalcon\\Tests\\Models\\RbTestModel (id, name) VALUES (3, "abc")');
        $modelsManager->executeQuery('INSERT INTO \\Phalcon\\Tests\\Models\\RbTestModel (id, name) VALUES (4, "abc")');
        $modelsManager->executeQuery('INSERT INTO \\Phalcon\\Tests\\Models\\RbTestModel (id, name) VALUES (5, "abc")');

        $messages = [];

        $messages[] = $this->update(1, 'test 1 OK', $modelsManager);
        $messages[] = $this->update(2, 'test 2 OK', $modelsManager);
        $messages[] = $this->update(3, 'test 3 DATA TRUNCATED ERROR', $modelsManager);
        $messages[] = $this->update(4, 'test 4 OK', $modelsManager);
        $messages[] = $this->update(5, 'test 5 OK', $modelsManager);

        Debug::debug($messages);

        $I->assertEquals('Update test 1 OK', $messages[0]);
        $I->assertEquals('Update test 2 OK', $messages[1]);
        $I->assertNotEquals('Update test 3 OK', $messages[2]);
        $I->assertStringContainsString('PDOException', $messages[2]);
        $I->assertEquals('Update test 4 OK', $messages[3]);
        $I->assertEquals('Update test 5 OK', $messages[4]);

        $I->seeInDatabase($this->migration->getTable(), ['name' => 'test 1 OK']);
        $I->seeInDatabase($this->migration->getTable(), ['name' => 'test 2 OK']);
        $I->seeInDatabase($this->migration->getTable(), ['id' => 3, 'name' => 'abc']);
        $I->seeInDatabase($this->migration->getTable(), ['name' => 'test 4 OK']);
        $I->seeInDatabase($this->migration->getTable(), ['name' => 'test 5 OK']);
    }

    private function update(int $id, string $name, Manager $modelsManager): string
    {
        try {
            $query = 'UPDATE \\Phalcon\\Tests\\Models\\RbTestModel SET name = :name: WHERE id = :id:';
            $modelsManager->executeQuery($query, ['id' => $id, 'name' => $name]);
            return "Update $name";
        } catch (PDOException $exc) {
            return $exc::class . ' ' . $exc->getMessage();
        } catch (\Throwable $exc) {
            return get_class($exc) . ' ' . $exc->getMessage();
        }
    }
}
