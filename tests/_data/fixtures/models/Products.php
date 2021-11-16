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
 * Class Products
 *
 * @property int    $prd_id;
 * @property string $prd_name;
 */
class Products extends Model
{
    public $prd_id;
    public $prd_name;

    public function initialize()
    {
        $this->setSource('co_products');
    }
}
