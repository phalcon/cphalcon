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

namespace Phalcon\Tests\Models;

use Phalcon\Mvc\Model\Behavior\SoftDelete;
use Phalcon\Mvc\Model\Behavior\Timestampable;

/**
 * Class InvoicesSoftDelete
 *
 * @property int    $inv_id
 * @property int    $inv_cst_id
 * @property int    $inv_status_flag
 * @property string $inv_title
 * @property float  $inv_total
 * @property string $inv_created_at
 */
class InvoicesBehavior extends Invoices
{
    public function initialize()
    {
        $this->setSource('co_invoices');
        $this->addBehavior(
            new SoftDelete(
                [
                    'field' => 'inv_status_flag',
                    'value' => Invoices::STATUS_INACTIVE,
                ]
            )
        );
        $this->addBehavior(
            new Timestampable(
                [
                    'beforeCreate' => [
                        'field'  => 'inv_created_at',
                        'format' => 'Y-m-d H:i:s',
                    ],
                ]
            )
        );
    }
}
