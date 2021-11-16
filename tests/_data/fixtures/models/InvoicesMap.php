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

use Phalcon\Mvc\Model;

/**
 * Class InvoicesMap
 *
 * @property int    $id
 * @property int    $cst_id
 * @property int    $status_flag
 * @property string $title
 * @property float  $total
 * @property string $created_at
 */
class InvoicesMap extends Model
{
    public $id;
    public $cst_id;
    public $status_flag;
    public $title;
    public $total;
    public $created_at;

    public function initialize()
    {
        $this->setSource('co_invoices');
    }

    public function columnMap()
    {
        return [
            'inv_id'          => 'id',
            'inv_cst_id'      => 'cst_id',
            'inv_status_flag' => 'status_flag',
            'inv_title'       => 'title',
            'inv_total'       => 'total',
            'inv_created_at'  => 'created_at',
        ];
    }
}
