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
use Phalcon\Contracts\Mvc\Model\Relation\CacheKeyProvider;

/**
 * Model that implements CacheKeyProvider so that the Model Manager uses a
 * stable, primary-key-based cache key when reusable relations are in play.
 */
class InvoicesCacheKeyProvider extends Model implements CacheKeyProvider
{
    public $inv_id;
    public $inv_cst_id;
    public $inv_status_flag;
    public $inv_title;
    public $inv_total;
    public $inv_created_at;

    public function initialize(): void
    {
        $this->setSource('co_invoices');

        $this->hasOne(
            'inv_cst_id',
            CustomersCacheKeyProvider::class,
            'cst_id',
            [
                'alias'    => 'customer',
                'reusable' => true,
            ]
        );
    }

    public function getUniqueKey(): string
    {
        return static::class . ':' . $this->inv_id;
    }
}
