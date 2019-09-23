<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models\Some;

use Phalcon\Db\Column;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\MetaData;

class Products extends Model
{
    public function initialize()
    {
        $this->setSource('le_products');
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
