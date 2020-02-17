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
 * Class OrderProducts
 *
 * @property int    $cst_id;
 * @property string $prdt_id;
 */
class OrderProducts extends Model
{
    public $cst_id;
    public $prdt_id;

    public function initialize()
    {
        $this->setSchema('private');
        $this->setSource('co_order_products');
    }
}
