<?php

namespace Some;

use Phalcon\Db\Column;
use Phalcon\Mvc\Model\MetaData;

class Products extends \Phalcon\Mvc\Model
{

    public function getSource()
    {
        return 'le_products';
    }

    public function metaData()
    {
        return [
            MetaData::MODELS_ATTRIBUTES               => [
                'id', 'name', 'type', 'price',
            ],
            MetaData::MODELS_PRIMARY_KEY              => [
                'id',
            ],
            MetaData::MODELS_NON_PRIMARY_KEY          => [
                'name', 'type', 'price',
            ],
            MetaData::MODELS_NOT_NULL                 => [
                'id', 'name', 'type', 'price',
            ],
            MetaData::MODELS_DATA_TYPES               => [
                'id'    => Column::TYPE_INTEGER,
                'name'  => Column::TYPE_VARCHAR,
                'type'  => Column::TYPE_VARCHAR,
                'price' => Column::TYPE_INTEGER,
            ],
            MetaData::MODELS_DATA_TYPES_NUMERIC       => [
                'id'    => true,
                'price' => true,
            ],
            MetaData::MODELS_IDENTITY_COLUMN          => 'id',
            MetaData::MODELS_DATA_TYPES_BIND          => [
                'id'    => Column::BIND_PARAM_INT,
                'name'  => Column::BIND_PARAM_STR,
                'type'  => Column::BIND_PARAM_STR,
                'price' => Column::BIND_PARAM_INT,
            ],
            MetaData::MODELS_AUTOMATIC_DEFAULT_INSERT => [],
            MetaData::MODELS_AUTOMATIC_DEFAULT_UPDATE => [],
        ];
    }

}
