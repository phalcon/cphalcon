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

namespace Phalcon\Tests\Support\Models;

use Phalcon\Mvc\Model;

/**
 * Fixture model used to test isVisibleModelProperty().
 * Exposes a known set of public, protected, and private properties.
 */
class CustomersVisible extends Model
{
    public $id;
    public $document_id;
    public $customer_id;
    public $first_name;
    public $last_name;

    protected $protected_field;

    // @phpstan-ignore-next-line
    private $private_field;

    public function initialize(): void
    {
        $this->setSource('co_customers');
    }
}
