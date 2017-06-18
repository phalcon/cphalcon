<?php

namespace Phalcon\Test\Unit\Mvc\Model\MetaData\Strategy;

use Phalcon\Di;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Mvc\Model\MetaData\Memory;
use Phalcon\Mvc\Model\MetaData\Strategy\Annotations;
use Phalcon\Test\Models\Annotations\Robot;
use Phalcon\Db\Column;

class AnnotationsTest extends UnitTest
{

    protected function setUpModelsMetadata()
    {
        $di = Di::getDefault();
        Di::reset();

        $metaData = new Memory();
        $metaData->setDI($di);
        $metaData->setStrategy(new Annotations());

        $di->setShared('modelsMetadata', $metaData);

        Di::setDefault($di);

        return $metaData;
    }

    /**
     * @author michanismus
     * @since  2017-04-06
     */
    public function testModelMetaDataAnnotations()
    {
        $this->specify(
            "Reading model metadata using annotations strategy failed",
            function () {

                $model = new Robot();
                $metaData = $this->setUpModelsMetadata();

                expect($metaData->getColumnMap($model))->equals([
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
                    'longblob'   => 'longblob'
                ]);

                expect($metaData->getReverseColumnMap($model))->equals([
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
                    'longblob'    => 'longblob'
                ]);

                expect($metaData->getIdentityField($model))->equals('id');
                expect($metaData->getPrimaryKeyAttributes($model))->equals(['id']);

                expect($metaData->getNonPrimaryKeyAttributes($model))->equals([
                    'name', 'type', 'year', 'deleted', 'text', 'float', 'double',
                    'decimal', 'activated', 'birthday', 'timestamp', 'code',
                    'json', 'tinyblob', 'blob', 'mediumblob', 'longblob'
                ]);

                expect($metaData->getNotNullAttributes($model))->equals([
                    'id', 'name', 'type', 'year', 'text', 'float', 'double',
                    'decimal', 'activated', 'birthday', 'timestamp', 'code'
                ]);

                expect($metaData->getDataTypes($model))->equals([
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
                    'longblob'   => Column::TYPE_LONGBLOB
                ]);

                expect($metaData->getDataTypesNumeric($model))->equals([
                    'id'      => true,
                    'year'    => true,
                    'float'   => true,
                    'double'  => true,
                    'decimal' => true
                ]);

                expect($metaData->getBindTypes($model))->equals([
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
                    'longblob'   => Column::BIND_PARAM_BLOB
                ]);

                expect($metaData->getAutomaticCreateAttributes($model))->equals([
                    'deleted'
                ]);

                expect($metaData->getAutomaticUpdateAttributes($model))->equals([
                    'float', 'longblob'
                ]);

                expect($metaData->getEmptyStringAttributes($model))->equals([
                    'name', 'text'
                ]);

                expect($metaData->getDefaultValues($model))->equals([
                    'type'       => 'mechanical',
                    'year'       => '1900',
                    'deleted'    => null,
                    'json'       => null,
                    'tinyblob'   => null,
                    'blob'       => null,
                    'mediumblob' => null,
                    'longblob'   => null
                ]);
            }
        );
    }
}
