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
 * Class Customers
 *
 * @property string $cst_name_last
 * @property string $cst_name_first
 */
class CustomersDefaults extends Customers
{
    public $cst_name_last = 'cst_default_lastName';
    public $cst_name_first = 'cst_default_firstName';

    public function initialize()
    {
        parent::initialize();

        $this->setSource('co_customers_defaults');
        $this->keepSnapshots(true);
    }
}
