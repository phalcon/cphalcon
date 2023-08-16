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
 * Class OrdersProductsFieldsOneComp
 *
 * @property int    $oxp_ord_id;
 * @property string $oxp_prd_id;
 * @property string $oxp_quantity;
 * @property int    $oxp_ord_status_flag;
 * @property int    $oxp_prd_status_flag;
 */
class OrdersProductsFieldsOneComp extends Model
{
    public $oxp_ord_id;
    public $oxp_prd_id;
    public $oxp_quantity;


    public function initialize()
    {
        $this->setSource('co_orders_x_products_one_comp');
    }
}
