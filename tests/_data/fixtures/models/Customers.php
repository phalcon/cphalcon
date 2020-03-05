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

use Phalcon\Mvc\Model;

/**
 * Class Customers
 *
 * @property int    $cst_id;
 * @property int    $cst_status_flag;
 * @property string $cst_name_last;
 * @property string $cst_name_first;
 */
class Customers extends Model
{
    public $cst_id;
    public $cst_status_flag;
    public $cst_name_last;
    public $cst_name_first;

    public function initialize()
    {
        $this->setSource('co_customers');

        $this->hasMany(
            'cst_id',
            Invoices::class,
            'inv_cst_id',
            [
                'alias'    => 'invoices',
                'reusable' => true,
            ]
        );
    }
}
