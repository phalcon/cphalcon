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
class CustomersCacheKeyProvider extends Model implements CacheKeyProvider
{
    public $cst_id;
    public $cst_status_flag;
    public $cst_name_last;
    public $cst_name_first;

    public function initialize(): void
    {
        $this->setSource('co_customers');

        $this->hasMany(
            'cst_id',
            InvoicesCacheKeyProvider::class,
            'inv_cst_id',
            [
                'alias'    => 'invoices',
                'reusable' => true,
            ]
        );
    }

    public function getUniqueKey(): string
    {
        return static::class . ':' . $this->cst_id;
    }
}
