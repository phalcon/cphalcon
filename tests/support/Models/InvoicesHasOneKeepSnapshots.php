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

class InvoicesHasOneKeepSnapshots extends Invoices
{
    public function initialize()
    {
        $this->setSource('co_invoices');
        $this->keepSnapshots(true);

        $this->hasOne(
            'inv_cst_id',
            CustomersKeepSnapshots::class,
            'cst_id',
            [
                'alias'    => 'customer',
                'reusable' => false,
            ]
        );
    }
}