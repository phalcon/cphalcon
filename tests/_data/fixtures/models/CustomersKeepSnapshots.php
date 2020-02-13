<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * Class CustomersKeepSnapshots
 *
 * @property int    $cst_id;
 * @property int    $cst_status_flag;
 * @property string $cst_name_last;
 * @property string $cst_name_first;
 */
class CustomersKeepSnapshots extends Model
{
    public $cst_id;
    public $cst_status_flag;
    public $cst_name_last;
    public $cst_name_first;

    public function initialize()
    {
        $this->keepSnapshots(true);
        $this->setSource('co_customers');

        $this->belongsTo(
            'cst_id',
            __NAMESPACE__ . 'InvoicesKeepSnapshots',
            'inv_cst_id',
            [
                'alias'    => 'invoices',
                'reusable' => true,
            ]
        );
    }
}
