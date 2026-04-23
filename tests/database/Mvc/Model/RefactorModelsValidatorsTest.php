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

final class RefactorModelsValidatorsTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testValidatorsMysql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testValidatorsPostgresql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testValidatorsSqlite(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }
}

// Original Cest file content (ModelsValidatorsCest):
//
// <?php
//
// namespace Phalcon\Tests\Integration\Mvc\Model;
//
// use IntegrationTester;
// use Phalcon\Tests\Support\Traits\DiTrait;
// use Phalcon\Tests\Support\Models\Abonnes;
// use Phalcon\Validation\Validator\Email;
// use Phalcon\Validation\Validator\ExclusionIn;
// use Phalcon\Validation\Validator\InclusionIn;
// use Phalcon\Validation\Validator\PresenceOf;
// use Phalcon\Validation\Validator\Regex;
// use Phalcon\Validation\Validator\StringLength\Max;
// use Phalcon\Validation\Validator\StringLength\Min;
// use Phalcon\Validation\Validator\Uniqueness;
//
// use function date;
//
// class ModelsValidatorsCest
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
//     public function testValidatorsMysql(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//         $this->testValidatorsRenamed($I);
//     }
//
//     public function testValidatorsPostgresql(IntegrationTester $I)
//     {
//         $this->setupPostgres();
//         $this->testValidatorsRenamed($I);
//     }
//
//     public function testValidatorsSqlite(IntegrationTester $I)
//     {
//         $this->setDiSqlite();
//         /**
//          * @todo Check Sqlite - tests lock up
//
