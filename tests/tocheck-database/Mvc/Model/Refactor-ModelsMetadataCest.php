<?php

namespace Phalcon\Tests\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Personas;
use Phalcon\Tests\Models\Robots;

class ModelsMetadataCest
{
    use DiTrait;

    protected $meta = [
        0  => [
            0 => 'id',
            1 => 'name',
            2 => 'type',
            3 => 'year',
            4 => 'datetime',
            5 => 'deleted',
            6 => 'text',
        ],
        1  => [
            0 => 'id',
        ],
        2  => [
            0 => 'name',
            1 => 'type',
            2 => 'year',
            3 => 'datetime',
            4 => 'deleted',
            5 => 'text',
        ],
        3  => [
            0 => 'id',
            1 => 'name',
            2 => 'type',
            3 => 'year',
            4 => 'datetime',
            5 => 'text',
        ],
        4  => [
            'id'       => 0,
            'name'     => 2,
            'type'     => 2,
            'year'     => 0,
            'datetime' => 4,
            'deleted'  => 4,
            'text'     => 6,
        ],
        5  => [
            'id'   => true,
            'year' => true,
        ],
        8  => 'id',
        9  => [
            'id'       => 1,
            'name'     => 2,
            'type'     => 2,
            'year'     => 1,
            'datetime' => 2,
            'deleted'  => 2,
            'text'     => 2,
        ],
        10 => [],
        11 => [],
        12 => [
            'type'    => 'mechanical',
            'year'    => 1900,
            'deleted' => null,
        ],
        13 => [],
    ];

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    public function testMetadataMysql(IntegrationTester $I)
    {
        $this->setDiMysql();
        $this->executeTests($I);
    }

    protected function executeTests(IntegrationTester $I)
    {
        $metaData = $this->container->getShared('modelsMetadata');

        $personas    = new Personas();
        $pAttributes = [
            0  => 'cedula',
            1  => 'tipo_documento_id',
            2  => 'nombres',
            3  => 'telefono',
            4  => 'direccion',
            5  => 'email',
            6  => 'fecha_nacimiento',
            7  => 'ciudad_id',
            8  => 'creado_at',
            9  => 'cupo',
            10 => 'estado',
        ];

        $attributes = $metaData->getAttributes($personas);
        $I->assertEquals($attributes, $pAttributes);

        $ppkAttributes = [
            0 => 'cedula',
        ];

        $pkAttributes = $metaData->getPrimaryKeyAttributes($personas);
        $I->assertEquals($ppkAttributes, $pkAttributes);

        $pnpkAttributes = [
            0 => 'tipo_documento_id',
            1 => 'nombres',
            2 => 'telefono',
            3 => 'direccion',
            4 => 'email',
            5 => 'fecha_nacimiento',
            6 => 'ciudad_id',
            7 => 'creado_at',
            8 => 'cupo',
            9 => 'estado',
        ];

        $npkAttributes = $metaData->getNonPrimaryKeyAttributes($personas);
        $I->assertEquals($pnpkAttributes, $npkAttributes);

        $pnnAttributes = [
            0 => 'cedula',
            1 => 'tipo_documento_id',
            2 => 'nombres',
            3 => 'cupo',
            4 => 'estado',
        ];

        $nnAttributes = $metaData->getNotNullAttributes($personas);
        $I->assertEquals($nnAttributes, $pnnAttributes);

        /**
         * @todo Check this test - its weird
         */
//        $dataTypes = [
//            'cedula'            => 5,
//            'tipo_documento_id' => 0,
//            'nombres'           => 2,
//            'telefono'          => 2,
//            'direccion'         => 2,
//            'email'             => 2,
//            'fecha_nacimiento'  => 1,
//            'ciudad_id'         => 0,
//            'creado_at'         => 1,
//            'cupo'              => 3,
////            'estado'            => 5,
//            'estado'            => 18,
//        ];
//
//        $dtAttributes = $metaData->getDataTypes($personas);
//        $I->assertEquals($dataTypes, $dtAttributes);

        $pndAttributes = [
            'tipo_documento_id' => true,
            'ciudad_id'         => true,
            'cupo'              => true,
        ];
        $ndAttributes  = $metaData->getDataTypesNumeric($personas);
        $I->assertEquals($ndAttributes, $pndAttributes);

//        $bindTypes = [
//            'cedula'            => 2,
//            'tipo_documento_id' => 1,
//            'nombres'           => 2,
//            'telefono'          => 2,
//            'direccion'         => 2,
//            'email'             => 2,
//            'fecha_nacimiento'  => 2,
//            'ciudad_id'         => 1,
//            'creado_at'         => 2,
//            'cupo'              => 32,
//            'estado'            => 2,
//        ];
//        $btAttributes = $metaData->getBindTypes($personas);
//        $I->assertEquals($bindTypes, $btAttributes);

        $defValues      = [
            'nombres'          => '',
            'telefono'         => null,
            'direccion'        => null,
            'email'            => null,
            'fecha_nacimiento' => '1970-01-01',
            'ciudad_id'        => '0',
            'creado_at'        => null,
        ];
        $modelDefValues = $metaData->getDefaultValues($personas);
        $I->assertEquals($defValues, $modelDefValues);

        $robots = new Robots();

        //Robots
        $pAttributes = [
            0 => 'id',
            1 => 'name',
            2 => 'type',
            3 => 'year',
            4 => 'datetime',
            5 => 'deleted',
            6 => 'text',
        ];

        $attributes = $metaData->getAttributes($robots);
        $I->assertEquals($attributes, $pAttributes);

        $ppkAttributes = [
            0 => 'id',
        ];

        $pkAttributes = $metaData->getPrimaryKeyAttributes($robots);
        $I->assertEquals($ppkAttributes, $pkAttributes);

        $pnpkAttributes = [
            0 => 'name',
            1 => 'type',
            2 => 'year',
            3 => 'datetime',
            4 => 'deleted',
            5 => 'text',
        ];

        $npkAttributes = $metaData->getNonPrimaryKeyAttributes($robots);
        $I->assertEquals($pnpkAttributes, $npkAttributes);

        $I->assertEquals($metaData->getIdentityField($robots), 'id');

        $defValues = [
            'type'    => 'mechanical',
            'year'    => 1900,
            'deleted' => null,
        ];

        $modelDefValues = $metaData->getDefaultValues($robots);
        $I->assertEquals($defValues, $modelDefValues);
    }

    public function testMetadataPostgresql(IntegrationTester $I)
    {
        $this->setupPostgres();
        $this->executeTests($I);
    }

    public function testMetadataSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();
        $this->executeTests($I);
    }
}
