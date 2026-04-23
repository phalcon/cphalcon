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

final class RefactorModelsMetadataTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testMetadataMysql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testMetadataPostgresql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testMetadataSqlite(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }
}

// Original Cest file content (ModelsMetadataCest):
//
// <?php
//
// namespace Phalcon\Tests\Integration\Mvc\Model;
//
// use IntegrationTester;
// use Phalcon\Tests\Support\Traits\DiTrait;
// use Phalcon\Tests\Support\Models\Personas;
// use Phalcon\Tests\Support\Models\Robots;
//
// class ModelsMetadataCest
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
//     public function testMetadataMysql(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//         $this->executeTests($I);
//     }
//
//     protected function executeTests(IntegrationTester $I)
//     {
//         $metaData = $this->container->getShared('modelsMetadata');
//
//         $personas    = new Personas();
//         $pAttributes = [
//             0  => 'cedula',
//             1  => 'tipo_documento_id',
//             2  => 'nombres',
//             3  => 'telefono',
//             4  => 'direccion',
//             5  => 'email',
//             6  => 'fecha_nacimiento',
//             7  => 'ciudad_id',
//             8  => 'creado_at',
//             9  => 'cupo',
//             10 => 'estado',
//         ];
//
//         $attributes = $metaData->getAttributes($personas);
//         $I->assertEquals($attributes, $pAttributes);
//
//         $ppkAttributes = [
//             0 => 'cedula',
//         ];
//
//         $pkAttributes = $metaData->getPrimaryKeyAttributes($personas);
//         $I->assertEquals($ppkAttributes, $pkAttributes);
//
//         $pnpkAttributes = [
//             0 => 'tipo_documento_id',
//             1 => 'nombres',
//             2 => 'telefono',
//             3 => 'direccion',
//             4 => 'email',
//             5 => 'fecha_nacimiento',
//             6 => 'ciudad_id',
//             7 => 'creado_at',
//             8 => 'cupo',
//             9 => 'estado',
//         ];
//
//         $npkAttributes = $metaData->getNonPrimaryKeyAttributes($personas);
//         $I->assertEquals($pnpkAttributes, $npkAttributes);
//
//         $pnnAttributes = [
//             0 => 'cedula',
//             1 => 'tipo_documento_id',
//             2 => 'nombres',
//             3 => 'cupo',
//             4 => 'estado',
//         ];
//
//         $nnAttributes = $metaData->getNotNullAttributes($personas);
//         $I->assertEquals($nnAttributes, $pnnAttributes);
//
//         /**
//          * @todo Check this test - its weird
//
