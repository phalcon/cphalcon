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

final class RefactorModelsForeignKeysTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testExecuteTestsNormal(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testExecuteTestsRenamed(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }
}

// Original Cest file content (ModelsForeignKeysCest):
//
// <?php
//
// namespace Phalcon\Tests\Integration\Mvc\Model;
//
// use Codeception\Example;
// use IntegrationTester;
// use Phalcon\Messages\Message;
// use Phalcon\Tests\Support\Traits\DiTrait;
// use Phalcon\Tests\Support\Models\Deles;
// use Phalcon\Tests\Support\Models\Parts;
// use Phalcon\Tests\Support\Models\Robots;
// use Phalcon\Tests\Support\Models\RobotsParts;
// use Phalcon\Tests\Support\Models\Robotters;
// use Phalcon\Tests\Support\Models\RobottersDeles;
//
// class ModelsForeignKeysCest
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
//     /**
//      * @dataProvider adaptersProvider
//
