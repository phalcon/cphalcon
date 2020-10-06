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

namespace Phalcon\Test\Models;

/**
 * Class InvoicesMap
 *
 * @property int    $inv_id
 * @property int    $inv_cst_id
 * @property int    $inv_status_flag
 * @property string $inv_title
 * @property float  $inv_total
 * @property string $inv_created_at
 */
class InvoicesKeepSnapshots extends Invoices
{
    public function initialize()
    {
        $this->setSource('co_invoices');
        $this->keepSnapshots(true);

        $this->belongsTo(
            'inv_cst_id',
            Customers::class,
            'cst_id',
            [
                'alias'    => 'customer',
                'reusable' => true,
            ]
        );
    }
}
