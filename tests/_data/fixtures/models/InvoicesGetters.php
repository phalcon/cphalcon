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

namespace Phalcon\Tests\Fixtures\models;

use Phalcon\Tests\Models\Invoices;

/**
 * Class InvoicesGetters
 */
class InvoicesGetters extends Invoices
{
    /**
     * @return bool|null
     */
    public function getInvTitle(): string
    {
        return $this->inv_title . '!' . $this->inv_id;
    }
}
