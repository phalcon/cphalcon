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
 * Class Products
 *
 * @property int    $prdt_id;
 * @property string $prdt_name;
 */
class Products extends Model
{
    public $prdt_id;
    public $prdt_name;

    public function initialize()
    {
        $this->setSource('co_products');
    }
}
