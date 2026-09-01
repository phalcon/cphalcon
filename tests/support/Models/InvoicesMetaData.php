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

namespace Phalcon\Tests\Support\Models;

use Phalcon\Db\Column;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\MetaData;

/**
 * Accounting model that supplies its metadata manually via metaData() (used by
 * the Memory metadata adapter tests).
 */
class InvoicesMetaData extends Model
{
    public function initialize()
    {
        $this->setSource('co_invoices');
    }

    public function metaData()
    {
        return [
            MetaData::MODELS_ATTRIBUTES               => [
                'inv_id', 'inv_cst_id', 'inv_status_flag', 'inv_title',
            ],
            MetaData::MODELS_PRIMARY_KEY              => [
                'inv_id',
            ],
            MetaData::MODELS_NON_PRIMARY_KEY          => [
                'inv_cst_id', 'inv_status_flag', 'inv_title',
            ],
            MetaData::MODELS_NOT_NULL                 => [
                'inv_id', 'inv_cst_id', 'inv_status_flag', 'inv_title',
            ],
            MetaData::MODELS_DATA_TYPES               => [
                'inv_id'          => Column::TYPE_INTEGER,
                'inv_cst_id'      => Column::TYPE_INTEGER,
                'inv_status_flag' => Column::TYPE_INTEGER,
                'inv_title'       => Column::TYPE_VARCHAR,
            ],
            MetaData::MODELS_DATA_TYPES_NUMERIC       => [
                'inv_id'          => true,
                'inv_cst_id'      => true,
                'inv_status_flag' => true,
            ],
            MetaData::MODELS_IDENTITY_COLUMN          => 'inv_id',
            MetaData::MODELS_DATA_TYPES_BIND          => [
                'inv_id'          => Column::BIND_PARAM_INT,
                'inv_cst_id'      => Column::BIND_PARAM_INT,
                'inv_status_flag' => Column::BIND_PARAM_INT,
                'inv_title'       => Column::BIND_PARAM_STR,
            ],
            MetaData::MODELS_AUTOMATIC_DEFAULT_INSERT => [],
            MetaData::MODELS_AUTOMATIC_DEFAULT_UPDATE => [],
        ];
    }
}
