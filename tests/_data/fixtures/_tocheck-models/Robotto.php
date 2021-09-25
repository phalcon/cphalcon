<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models;

use Phalcon\Db\Column;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\MetaData;

class Robotto extends Model
{
    public function initialize()
    {
        $this->setSource('robots');
    }

    public function metaData()
    {
        return [
            MetaData::MODELS_ATTRIBUTES               => [
                'id', 'name', 'type', 'year',
            ],
            MetaData::MODELS_PRIMARY_KEY              => [
                'id',
            ],
            MetaData::MODELS_NON_PRIMARY_KEY          => [
                'name', 'type', 'year',
            ],
            MetaData::MODELS_NOT_NULL                 => [
                'id', 'name', 'type', 'year',
            ],
            MetaData::MODELS_DATA_TYPES               => [
                'id'   => Column::TYPE_INTEGER,
                'name' => Column::TYPE_VARCHAR,
                'type' => Column::TYPE_VARCHAR,
                'year' => Column::TYPE_INTEGER,
            ],
            MetaData::MODELS_DATA_TYPES_NUMERIC       => [
                'id'   => true,
                'year' => true,
            ],
            MetaData::MODELS_IDENTITY_COLUMN          => 'id',
            MetaData::MODELS_DATA_TYPES_BIND          => [
                'id'   => Column::BIND_PARAM_INT,
                'name' => Column::BIND_PARAM_STR,
                'type' => Column::BIND_PARAM_STR,
                'year' => Column::BIND_PARAM_INT,
            ],
            MetaData::MODELS_AUTOMATIC_DEFAULT_INSERT => [],
            MetaData::MODELS_AUTOMATIC_DEFAULT_UPDATE => [],
        ];
    }
}
