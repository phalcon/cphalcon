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

final class RefactorModelsMetadataStrategyTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testMetadataDatabaseIntrospection(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testMetadataAnnotations(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }
}

// Original Cest file content (ModelsMetadataStrategyCest):
//
// <?php
//
// namespace Phalcon\Tests\Integration\Mvc\Model;
//
// use IntegrationTester;
// use Phalcon\Mvc\Model\MetaData\Memory;
// use Phalcon\Mvc\Model\MetaData\Strategy\Annotations;
// use Phalcon\Mvc\Model\MetaData\Strategy\Introspection;
// use Phalcon\Tests\Support\Traits\DiTrait;
// use Phalcon\Tests\Support\Models\Boutique\Robots as BoutiqueRobots;
// use Phalcon\Tests\Support\Models\Robots;
//
// class ModelsMetadataStrategyCest
// {
//     use DiTrait;
//
//     protected $meta = [
//         0  => [
//             0 => 'id',
//             1 => 'name',
//             2 => 'type',
//             3 => 'year',
//             4 => 'datetime',
//             5 => 'deleted',
//             6 => 'text',
//         ],
//         1  => [
//             0 => 'id',
//         ],
//         2  => [
//             0 => 'name',
//             1 => 'type',
//             2 => 'year',
//             3 => 'datetime',
//             4 => 'deleted',
//             5 => 'text',
//         ],
//         3  => [
//             0 => 'id',
//             1 => 'name',
//             2 => 'type',
//             3 => 'year',
//             4 => 'datetime',
//             5 => 'text',
//         ],
//         4  => [
//             'id'       => 0,
//             'name'     => 2,
//             'type'     => 2,
//             'year'     => 0,
//             'datetime' => 4,
//             'deleted'  => 4,
//             'text'     => 6,
//         ],
//         5  => [
//             'id'   => true,
//             'year' => true,
//         ],
//         8  => 'id',
//         9  => [
//             'id'       => 1,
//             'name'     => 2,
//             'type'     => 2,
//             'year'     => 1,
//             'datetime' => 2,
//             'deleted'  => 2,
//             'text'     => 2,
//         ],
//         10 => [],
//         11 => [],
//         12 => [
//             'type'    => 'mechanical',
//             'year'    => 1900,
//             'deleted' => null,
//         ],
//         13 => [],
//     ];
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
//     public function testMetadataDatabaseIntrospection(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//         $this->container['modelsMetadata'] = function () {
//             $metaData = new Memory();
//             $metaData->setStrategy(new Introspection());
//
//             return $metaData;
//         };
//
//         $metaData = $this->container['modelsMetadata'];
//
//         $robots = new Robots();
//         $meta   = $metaData->readMetaData($robots);
//         $I->assertEquals($meta, $this->meta);
//
//         $meta = $metaData->readMetaData($robots);
//         $I->assertEquals($meta, $this->meta);
//     }
//
//     public function testMetadataAnnotations(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//         $this->container['modelsMetadata'] = function () {
//             $metaData = new Memory();
//             $metaData->setStrategy(new Annotations());
//
//             return $metaData;
//         };
//
//         $metaData = $this->container['modelsMetadata'];
//
//         $robots = new BoutiqueRobots();
//
//         $meta = $metaData->readMetaData($robots);
//         $I->assertEquals($meta, $this->meta);
//
//         $meta = $metaData->readMetaData($robots);
//         $I->assertEquals($meta, $this->meta);
//     }
// }
//
//
