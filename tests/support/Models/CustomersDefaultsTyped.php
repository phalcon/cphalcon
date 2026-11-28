<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Models;

use Phalcon\Mvc\Model;

/**
 * Model with public typed properties for a table with default values. Used to
 * test the weak type checks of the ORM.
 */
class CustomersDefaultsTyped extends Model
{
    public ?int $cst_id = null;
    public ?string $cst_name_first = null;
    public ?string $cst_name_last = null;
    public ?int $cst_status_flag = null;

    public function initialize(): void
    {
        $this->setSource('co_customers_defaults');
    }
}
