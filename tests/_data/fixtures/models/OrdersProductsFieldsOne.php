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
 * Class class OrdersProductsFieldsOne
 *
 * @property int    $oxp_ord_id;
 * @property string $oxp_prd_id;
 * @property string $oxp_quantity;
 */
class OrdersProductsFieldsOne extends Model
{
    public $oxp_id;
    public $oxp_ord_id;
    public $oxp_prd_id;
    public $oxp_quantity;


    public function initialize()
    {
        $this->setSource('co_orders_x_products_one');
    }
}
