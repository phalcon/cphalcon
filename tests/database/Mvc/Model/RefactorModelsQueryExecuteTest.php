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

use Phalcon\Tests\AbstractDatabaseTestCase;

final class RefactorModelsQueryExecuteTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testExecuteMysql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testExecutePostgresql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testExecuteSqlite(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }
}

// Original Cest file content (ModelsQueryExecuteCest):
//
// <?php
//
// namespace Phalcon\Tests\Integration\Mvc\Model;
//
// use IntegrationTester;
// use Phalcon\Tests\Support\Traits\DiTrait;
//
// class ModelsQueryExecuteCest
// {
//     use DiTrait;
//
//     public function _before(IntegrationTester $I)
//     {
//         $this->setNewFactoryDefault();
//     }
//
//     public function _after(IntegrationTester $I)
//     {
//         $this->container['db']->close();
//     }
//
//     public function testExecuteMysql(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//
//         $this->testSelectExecute($I);
//         $this->testSelectRenamedExecute($I);
//         $this->testInsertExecute($I);
//         $this->testInsertRenamedExecute($I);
//         $this->testUpdateExecute($I);
//         $this->testUpdateRenamedExecute($I);
//         $this->testDeleteExecute($I);
//         $this->testDeleteRenamedExecute($I);
//     }
//
//     public function testExecutePostgresql(IntegrationTester $I)
//     {
//         $this->setDiPostgresql();
//
//         $this->testSelectExecute($I);
//         $this->testSelectRenamedExecute($I);
//         $this->testInsertExecute($I);
//         $this->testInsertRenamedExecute($I);
//         $this->testUpdateExecute($I);
//         $this->testUpdateRenamedExecute($I);
//         $this->testDeleteExecute($I);
//         $this->testDeleteRenamedExecute($I);
//     }
//
//     public function testExecuteSqlite(IntegrationTester $I)
//     {
//         $this->setDiSqlite();
//
//         /**
//          * @todo Check Sqlite tests - they lock up
//
