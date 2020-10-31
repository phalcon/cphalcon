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
 * Class Orders
 *
 * @property int    $ord_id;
 * @property string $ord_name;
 */
class Orders extends Model
{
    public $ord_id;
    public $ord_name;

    public function initialize()
    {
        $this->setSource('co_orders');

        $this->hasManyToMany(
            'ord_id',
            OrdersProducts::class,
            'oxp_ord_id',
            'oxp_prd_id',
            Products::class,
            'prd_id',
            [
                'alias' => 'products'
            ]
        );

        $this->hasOneThrough(
            'ord_id',
            OrdersProducts::class,
            'oxp_ord_id',
            'oxp_prd_id',
            Products::class,
            'prd_id',
            [
                'alias' => 'singleProduct'
            ]
        );
    }
}
