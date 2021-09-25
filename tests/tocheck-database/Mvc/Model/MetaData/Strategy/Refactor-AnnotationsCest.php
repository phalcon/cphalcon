<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Integration\Mvc\Model\MetaData\Strategy;

use IntegrationTester;
use Phalcon\Db\Column;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Mvc\Model\MetaData\Strategy\Annotations;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Annotations\Robot;

class AnnotationsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();

        $metaData = new Memory();
        $metaData->setDI($this->container);
        $metaData->setStrategy(new Annotations());

        $this->container->setShared('modelsMetadata', $metaData);
    }

    /**
     * @author michanismus
     * @since  2017-04-06
     */
    public function testModelMetaDataAnnotations(IntegrationTester $I)
    {
        $model    = new Robot();
        $metaData = $this->container->getShared('modelsMetadata');

        $expected = [
            'id'         => 'id',
            'name'       => 'name',
            'type'       => 'type',
            'year'       => 'year',
            'deleted'    => 'deleted',
            'text'       => 'description',
            'float'      => 'float',
            'double'     => 'double',
            'decimal'    => 'decimal',
            'activated'  => 'activated',
            'birthday'   => 'birthday',
            'timestamp'  => 'timestamp',
            'code'       => 'code',
            'json'       => 'json',
            'tinyblob'   => 'tinyblob',
            'blob'       => 'blob',
            'mediumblob' => 'mediumblob',
            'longblob'   => 'longblob',
        ];
        $actual   = $metaData->getColumnMap($model);
        $I->assertEquals($expected, $actual);

        $expected = [
            'id'          => 'id',
            'name'        => 'name',
            'type'        => 'type',
            'year'        => 'year',
            'deleted'     => 'deleted',
            'description' => 'text',
            'float'       => 'float',
            'double'      => 'double',
            'decimal'     => 'decimal',
            'activated'   => 'activated',
            'birthday'    => 'birthday',
            'timestamp'   => 'timestamp',
            'code'        => 'code',
            'json'        => 'json',
            'tinyblob'    => 'tinyblob',
            'blob'        => 'blob',
            'mediumblob'  => 'mediumblob',
            'longblob'    => 'longblob',
        ];
        $actual   = $metaData->getReverseColumnMap($model);
        $I->assertEquals($expected, $actual);

        $expected = 'id';
        $actual   = $metaData->getIdentityField($model);
        $I->assertEquals($expected, $actual);

        $expected = ['id'];
        $actual   = $metaData->getPrimaryKeyAttributes($model);
        $I->assertEquals($expected, $actual);

        $expected = [
            'name', 'type', 'year', 'deleted', 'text', 'float', 'double',
            'decimal', 'activated', 'birthday', 'timestamp', 'code',
            'json', 'tinyblob', 'blob', 'mediumblob', 'longblob',
        ];
        $actual   = $metaData->getNonPrimaryKeyAttributes($model);
        $I->assertEquals($expected, $actual);

        $expected = [
            'id', 'name', 'type', 'year', 'text', 'float', 'double',
            'decimal', 'activated', 'birthday', 'timestamp', 'code',
        ];
        $actual   = $metaData->getNotNullAttributes($model);
        $I->assertEquals($expected, $actual);

        $expected = [
            'id'         => Column::TYPE_BIGINTEGER,
            'name'       => Column::TYPE_VARCHAR,
            'type'       => Column::TYPE_VARCHAR,
            'year'       => Column::TYPE_INTEGER,
            'deleted'    => Column::TYPE_DATETIME,
            'text'       => Column::TYPE_TEXT,
            'float'      => Column::TYPE_FLOAT,
            'double'     => Column::TYPE_DOUBLE,
            'decimal'    => Column::TYPE_DECIMAL,
            'activated'  => Column::TYPE_BOOLEAN,
            'birthday'   => Column::TYPE_DATE,
            'timestamp'  => Column::TYPE_TIMESTAMP,
            'code'       => Column::TYPE_CHAR,
            'json'       => Column::TYPE_JSON,
            'tinyblob'   => Column::TYPE_TINYBLOB,
            'blob'       => Column::TYPE_BLOB,
            'mediumblob' => Column::TYPE_MEDIUMBLOB,
            'longblob'   => Column::TYPE_LONGBLOB,
        ];
        $actual   = $metaData->getDataTypes($model);
        $I->assertEquals($expected, $actual);

        $expected = [
            'id'      => true,
            'year'    => true,
            'float'   => true,
            'double'  => true,
            'decimal' => true,
        ];
        $actual   = $metaData->getDataTypesNumeric($model);
        $I->assertEquals($expected, $actual);

        $expected = [
            'id'         => Column::BIND_PARAM_INT,
            'name'       => Column::BIND_PARAM_STR,
            'type'       => Column::BIND_PARAM_STR,
            'year'       => Column::BIND_PARAM_INT,
            'deleted'    => Column::BIND_PARAM_STR,
            'text'       => Column::BIND_PARAM_STR,
            'float'      => Column::BIND_PARAM_DECIMAL,
            'double'     => Column::BIND_PARAM_DECIMAL,
            'decimal'    => Column::BIND_PARAM_DECIMAL,
            'activated'  => Column::BIND_PARAM_BOOL,
            'birthday'   => Column::BIND_PARAM_STR,
            'timestamp'  => Column::BIND_PARAM_STR,
            'code'       => Column::BIND_PARAM_STR,
            'json'       => Column::BIND_PARAM_STR,
            'tinyblob'   => Column::BIND_PARAM_BLOB,
            'blob'       => Column::BIND_PARAM_BLOB,
            'mediumblob' => Column::BIND_PARAM_BLOB,
            'longblob'   => Column::BIND_PARAM_BLOB,
        ];
        $actual   = $metaData->getBindTypes($model);
        $I->assertEquals($expected, $actual);

        $expected = [
            'deleted',
        ];
        $actual   = $metaData->getAutomaticCreateAttributes($model);
        $I->assertEquals($expected, $actual);

        $expected = [
            'float', 'longblob',
        ];
        $actual   = $metaData->getAutomaticUpdateAttributes($model);
        $I->assertEquals($expected, $actual);

        $expected = [
            'name', 'text',
        ];
        $actual   = $metaData->getEmptyStringAttributes($model);
        $I->assertEquals($expected, $actual);

        $expected = [
            'type'       => 'mechanical',
            'year'       => '1900',
            'deleted'    => null,
            'json'       => null,
            'tinyblob'   => null,
            'blob'       => null,
            'mediumblob' => null,
            'longblob'   => null,
        ];
        $actual   = $metaData->getDefaultValues($model);
        $I->assertEquals($expected, $actual);
    }
}
